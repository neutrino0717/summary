#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${green}
${endColor}"
erun "lsof -u root -t" 
erun "pgrep -u root" 
