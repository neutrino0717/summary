#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${red}${endColor}"
eprt ''

elrun <<"EOF"
. constant.sh

pygmentize -g ${0}.exp

expect ${0}.exp $ipaddr $username $password 'grep BASH /etc/passwd -i --color'
EOF
