#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}
Use &> or &>> to redirect both standard output and standard error to the same place. 
${endColor}"
elrun <<"EOF"
tail no-exist-file /etc/group 
tail no-exist-file /etc/group >stdout.log 2>stderr.log

#the below two are equal
tail no-exist-file /etc/group 1>/dev/null 2>&1
tail no-exist-file /etc/group &>/dev/null
 
EOF
