#!/bin/bash

#sudo cp ~neutrino0717/graduation/cmd/linuxfromscratch/8.cmds_by_chroot-make_bootable.sh /mnt/lfs/8.cmds_by_chroot-make_bootable_realtime.sh
#sudo chmod 777 /mnt/lfs/7.cmds_by_chroot_realtime.sh
#ln -s /mnt/lfs/7.cmds_by_chroot_realtime.sh

set -e
set -u
set -v
set -x
if [ "$(id -u -n)" != "root" ]; then echo "please run as chroot!"; exit 1; fi

cat > /etc/fstab << "EOF"
# Begin /etc/fstab

# file system  mount-point  type     options             dump  fsck
#                                                              order
/dev/sdb2       /            ext3     defaults            1     1
#/dev/<xxx>     /            <fff>    defaults            1     1
#/dev/<yyy>     swap         swap     pri=1               0     0
proc           /proc        proc     nosuid,noexec,nodev 0     0
sysfs          /sys         sysfs    nosuid,noexec,nodev 0     0
devpts         /dev/pts     devpts   gid=5,mode=620      0     0
tmpfs          /run         tmpfs    defaults            0     0
devtmpfs       /dev         devtmpfs mode=0755,nosuid    0     0

# End /etc/fstab
EOF

#Installation of the kernel 
#==================================================================#
#  pname=$1
  pdir=`echo ${pname}|sed -e 's/\.tar\..*$//'`
  ext=${pname: -3}
  arg=${mtar[$ext]}
  cd /sources/${pdir}
pname=linux-4.7.2.tar.xz
logfilecur="/log/`date -u +%y%m%d%H%M%S`${pname}.log"
log_configure="/log/make/`date -u +%y%m%d%H%M%S`${pname}_configure.log"
log_make="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make.log"
log_make_check="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make_check.log"
log_make_install="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make_install.log"
tar xvf linux-4.7.2.tar.xz
cd linux-4.7.2
make check > $log_make_check
make install > $log_make_install
make -C doc install-html docdir=/usr/share/doc/tar-1.29
savelog

#Prepare for compilation by running the following command: 
make mrproper > $log_make
make menuconfig |tee -a $log_make
make | tee -a $log_make
#Install the modules, if the kernel configuration uses them: 
make modules_install | tee -a $log_make
#After kernel compilation is complete, Some files need to be copied to the /boot directory
cp -v arch/x86/boot/bzImage /boot/vmlinuz-4.7.2-lfs-7.10
cp -v System.map /boot/System.map-4.7.2
cp -v .config /boot/config-4.7.2
install -d /usr/share/doc/linux-4.7.2
cp -r Documentation/* /usr/share/doc/linux-4.7.2


install -v -m755 -d /etc/modprobe.d
cat > /etc/modprobe.d/usb.conf << "EOF"
# Begin /etc/modprobe.d/usb.conf

install ohci_hcd /sbin/modprobe ehci_hcd ; /sbin/modprobe -i ohci_hcd ; true
install uhci_hcd /sbin/modprobe ehci_hcd ; /sbin/modprobe -i uhci_hcd ; true

# End /etc/modprobe.d/usb.conf
EOF

#emergency boot disk
#ou need to jump ahead to BLFS and install xorriso from the libisoburn package
#cd /tmp 
#grub-mkrescue --output=grub-img.iso 
#xorriso -as cdrecord -v dev=/dev/cdrw blank=as_needed grub-img.iso
#

#Install the GRUB files into /boot/grub and set up the boot track: 
grub-install /dev/sdb
#Installing for i386-pc platform.
#Installation finished. No error reported.
cat > /boot/grub/grub.cfg << "EOF"
# Begin /boot/grub/grub.cfg
set default=0
set timeout=5

insmod ext2
set root=(hd0,2)

menuentry "GNU/Linux, Linux 4.7.2-lfs-7.10" {
        linux   /boot/vmlinuz-4.7.2-lfs-7.10 root=/dev/sda2 ro
}
EOF


echo 7.10 > /etc/lfs-release
cat > /etc/lsb-release << "EOF"
DISTRIB_ID="Linux From Scratch"
DISTRIB_RELEASE="7.10"
DISTRIB_CODENAME="Evan Liu"
DISTRIB_DESCRIPTION="Linux From Scratch"
EOF

find /bin /opt /sbin /usr /boot /etc /lib /var -type f | while read l; do md5sum $l|awk '{print $2" "$1}'; done > $logfilecur

#exit from the chroot environment:
logout

#Then unmount the virtual file systems:
umount -v $LFS/dev/pts
umount -v $LFS/dev
umount -v $LFS/run
umount -v $LFS/proc
umount -v $LFS/sys

#Unmount the LFS file system itself:
umount -v $LFS

#reboot the system with:
shutdown -r now

