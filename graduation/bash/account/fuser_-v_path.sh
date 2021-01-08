#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${yellow}
View all the processes using a directory
${endColor}"
erun "fuser -v ."
erun "fuser -v ~"
#erun "fuser -v /"


