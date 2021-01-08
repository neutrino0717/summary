#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${red}${endColor}"
eprt '
'
elrun <<"EOF"
#kernel will be shown as 'x86 boot sector'
sudo file /boot/vmlinuz*
sudo file /boot/initd*
EOF
