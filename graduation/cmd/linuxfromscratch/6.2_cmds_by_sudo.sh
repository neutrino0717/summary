#Begin by creating directories onto which the file systems will be mounted
LFS=/mnt/lfs
sudo mkdir -pv $LFS/{dev,proc,sys,run}

#Creating Initial Device Nodes 
#the console and null device nodes must be created on the hard disk so that the are available before udevd has been started
#mknod [OPTION]... NAME TYPE [MAJOR MINOR]
sudo mknod -m 600 $LFS/dev/console c 5 1
sudo mknod -m 666 $LFS/dev/null c 1 3

#Since this new system does not yet have Udev and has not yet been booted, 
#it is necessary to mount and populate /dev manually.
#This is accomplished by bind mounting the host system's /dev directory. 
#A bind mount is a special type of mount that allows you to 
#create a mirror of a directory or mount point to some other location. 
##Mounting and Populating /dev 
#mount --bind olddir newdir
sudo mount -v --bind /dev $LFS/dev
#-->/dev on /mnt/lfs/dev type none (rw,bind)

##Mounting Virtual Kernel File Systems 
sudo mount | column -t
#       -t, --types vfstype
#              The  argument  following  the  -t  is  used to indicate the filesystem type.  The
#              such as ext, ext2, ext3, ext4, hfs, iso9660, jfs, minix, msdos,  nfs,  ntfs,  
#              proc, tmpfs, ubifs, udf, ufs, umsdos,
#gid=5
#  ensures that all devpts-created device nodes are owned by group ID 5. 
#  This is the ID we will use later on for the tty group.
#mode=0620
#  This ensures that all devpts-created device nodes have mode 0620 
#mount [-fnrsvw] [-t vfstype] [-o options] device dir
sudo mount -vt devpts devpts $LFS/dev/pts -o gid=5,mode=620
sudo mount -vt proc proc $LFS/proc
sudo mount -vt sysfs sysfs $LFS/sys
sudo mount -vt tmpfs tmpfs $LFS/run
sudo mount | column -t
#/dev/sdc1  on  /mnt/lfs                  type  ext3        (rw)
#/dev       on  /mnt/lfs/dev              type  none        (rw,bind)
#devpts     on  /mnt/lfs/dev/pts          type  devpts      (rw,gid=5,mode=620)
#proc       on  /mnt/lfs/proc             type  proc        (rw)
#sysfs      on  /mnt/lfs/sys              type  sysfs       (rw)
#tmpfs      on  /mnt/lfs/run              type  tmpfs       (rw)

#In some host systems, /dev/shm is a symbolic link to /run/shm. 
#The /run tmpfs was mounted above so in this case only a directory needs to be created
if [ -h $LFS/dev/shm ]; then
  sudo mkdir -pv $LFS/$(readlink $LFS/dev/shm)
fi
