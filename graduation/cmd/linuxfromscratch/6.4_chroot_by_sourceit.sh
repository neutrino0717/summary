#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`
echo $adir
LFS=/mnt/lfs

sudo cp -ruv $adir/6.5_cmds_by_chroot.sh $LFS/6.5_cmds_by_chroot_real.sh
sudo cp -ruv $adir/6.7_cmds_by_chroot.sh $LFS/6.7_cmds_by_chroot_real.sh
sudo ln -sfv $LFS/6.5_cmds_by_chroot_real.sh $adir/
sudo ln -sfv $LFS/6.7_cmds_by_chroot_real.sh $adir/
sudo chmod 777 $LFS/6*
sudo chmod 777 $adir/6*
sudo chroot "$LFS" /tools/bin/env -i \
    HOME=/root                  \
    TERM="$TERM"                \
    PS1='\u:\w\$ '              \
    PATH=/bin:/usr/bin:/sbin:/usr/sbin:/tools/bin \
    /tools/bin/bash --login +h
