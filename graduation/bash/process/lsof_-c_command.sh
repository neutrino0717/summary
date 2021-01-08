#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${green}
-c followed by the process name will list the files opened by the process starting with that processes name. 
   c means command
${endColor}"
echo "list files opened by init"
erun "sudo lsof -c init" 
