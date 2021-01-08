#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${red}
ps        
  three types of options
       1   UNIX options, preceded by a dash.  ---> ps -ef
       2   BSD options,  must not be used with a dash. --> ps aux
       3   GNU long options, which are preceded by two dashes.
${endColor}"
eprt ''
elrun <<"EOF"
pstree -a | grep -B 5 --color $0
ps -e f | grep -B 5  --color $0
EOF
