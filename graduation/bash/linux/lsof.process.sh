#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${red}${endColor}"
eprt '
lsof   list open file
'
elrun <<"EOF"
sudo lsof -i :ssh
sudo lsof -i :22
#-n       inhibits the conversion of network numbers to 'host names' for network files.
#-P       option inhibits the conversion of port numbers to 'port names' for network files.
sudo lsof -i :22 -n -P

EOF
