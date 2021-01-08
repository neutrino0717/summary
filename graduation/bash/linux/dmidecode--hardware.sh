#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

elrun <<"EOF"
dmidecode |awk    '/^System Info/,/^$/'
dmidecode |sed -n '/^System Info/,/^$/p'
EOF
