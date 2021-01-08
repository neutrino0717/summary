#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${green}
List processes using a mount point

Sometime when we try to umount a directory, the system will say “Device or Resource Busy” error. So we need to find out what are all the processes using the mount point and kill those processes to umount the directory. By using lsof we can find those processes.
# lsof /home
The following will also work.
+D D  means deep,   causes lsof to search for all open instances of directory D and all the files and directories it contains to its complete depth.
# lsof +D /home/
${endColor}"
erun "lsof $HOME" 
erun "lsof +D $HOME" 
