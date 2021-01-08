#!/bin/bash
./library-check.sh #all present or all not
./version-check.sh

(cd /bin/ && sudo ln -sf bash sh)
sudo apt-get install bison
sudo apt-get install texinfo

#add a new disk on virtual box to the vm, the name will be /dev/sdb
sudo fdisk -l
##Disk /dev/sda: 43.4 GB, 43353210880 bytes
##   Device Boot      Start         End      Blocks   Id  System
##/dev/sda1   *        2048    82577407    41287680   83  Linux
##/dev/sda2        82579454    84672511     1046529    5  Extended
##/dev/sda5        82579456    84672511     1046528   82  Linux swap / Solaris
##
##Disk /dev/sdb: 8589 MB, 8589934592 bytes

#partition for /boot and /
sudo fdisk /dev/sdb
##n -> p -> 1 ->default ->+100M
##n -> p -> 2 ->default ->default
##p -> w
##   Device Boot      Start         End      Blocks   Id  System
##/dev/sdb1            2048      206847      102400   83  Linux
##/dev/sdb2          206848    16777215     8285184   83  Linux

#mke2fs - create an ext2/ext3/ext4 filesystem
#mkfs is a "wrapper". ... Actually, it calls mke2fs
#  -t fs-type
#  -j Create the filesystem with an ext3 journal
sudo mke2fs -jv /dev/sdb1
sudo mke2fs -jv /dev/sdb2
#    mkfs -v -t ext4 /dev/sdb1 #or
#    mkfs -v -t ext4 /dev/sdb2 #or

#mount
export LFS=/mnt/lfs
sudo mkdir -v $LFS
#sudo mkdir -v $LFS/boot
#sudo mount /dev/sdb1 $LFS/boot
sudo mount /dev/sdb2 $LFS
df -h
##/dev/sdb1        93M  1.6M   87M   2% /mnt/lfs/boot
##/dev/sdb2       7.7G   18M  7.3G   1% /mnt/lfs

#download packages
sudo mkdir -v $LFS/sources
sudo chmod -v a+wt $LFS/sources
wget http://www.linuxfromscratch.org/lfs/view/stable/wget-list
wget --input-file=wget-list --continue --directory-prefix=$LFS/ources
wget http://www.zlib.net/fossils/zlib-1.2.8.tar.gz --continue --directory-prefix=$LFS/sources
pushd $LFS/sources
wget http://www.linuxfromscratch.org/lfs/view/stable/md5sums
md5sum -c md5sums
popd

sudo mkdir -v $LFS/tools
sudo ln -sv $LFS/tools /

#add user lfs
sudo groupadd lfs
sudo useradd -s /bin/bash -g lfs -m -k /dev/null lfs
sudo passwd lfs
sudo chown -v lfs $LFS/tools
sudo chown -v lfs $LFS/sources

su - lfs
cat > ~/.bash_profile << "EOF"
exec env -i HOME=$HOME TERM=$TERM PS1='\u:\w\$ ' /bin/bash
EOF
cat > ~/.bashrc << "EOF"
set +h
umask 022
LFS=/mnt/lfs
LC_ALL=POSIX
LFS_TGT=$(uname -m)-lfs-linux-gnu
PATH=/tools/bin:/bin:/usr/bin
LOG_DIR=/home/neutrino0717/graduation/cmd/linuxfromscratch
export LFS LC_ALL LFS_TGT PATH LOG_DIR
EOF

# login as lfs
su - lfs
export LFS=/mnt/lfs
cd $LFS/sources
