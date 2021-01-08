#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

elrun <<"EOF"
str="bing.com|google.com|baidu.com|yahoo.com"
# use IFS and echo
IFS='|' sites=(`echo $str`); echo "${sites[@]}"
IFS='|' sites=(`printf "$str"`); echo "${sites[@]}"
#unset IFS
# use IFS and read
IFS=$'|' read -d '' -a sites2 <<< "$str"; echo "${sites2[@]}"
EOF
