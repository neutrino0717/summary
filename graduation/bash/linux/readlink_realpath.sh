#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${red}
readlink -f file.txt  #get the absolute path to a file
  Usage: readlink [OPTION]... FILE
  Print value of a symbolic link or canonical file name
    -f, --canonicalize            canonicalize by following every symlink in
                                  every component of the given name recursively;
  [root@localhost ~]# readlink -f /sys/class/block/sda
  /sys/devices/pci0000:00/0000:00:10.0/host2/target2:0:0/2:0:0:0/block/sda
${endColor}"
eprt ''
elrun <<"EOF"
readlink -f .
readlink -f $0
realpath .
realpath $0
EOF
