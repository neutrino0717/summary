#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

#pygmentize -l bash $0; exit
elrun <<EOF
#To download the 2.6.17.8 kernel version using wget, enter:
echo wget http://www.kernel.org/pub/linux/kernel/v2.6/linux-2.6.17.8.tar.gz
#To download the 2.6.17.8 kernel version using curl, enter:
echo curl http://www.kernel.org/pub/linux/kernel/v2.6/linux-2.6.17.8.tar.gz -o linux-2.6.17.8.tar.gz
EOF
