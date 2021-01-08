#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${green}
 List all open files by a specific process.
${endColor}"
erun "pidof bash | awk '{print \$1}' | xargs lsof -p"
