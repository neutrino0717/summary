#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt 'print multiple ='
elrun <<"EOF"
printf '%17s\\n' |tr ' ' =
EOF
