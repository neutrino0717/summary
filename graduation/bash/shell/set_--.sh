#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt '
set --
  If no arguments follow this option, then the positional parameters are unse
'

elrun <<"EOF"
set param1 param2 "param 3"
echo "$1,$2,$3"
IFS=':'
echo $*; echo $@
echo "$*"; echo "$@"
set --
echo "$*"
set -- param1 param2 "param 3"
echo "$*"
echo "$@"
EOF



