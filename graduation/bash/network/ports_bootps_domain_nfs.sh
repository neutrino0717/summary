#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}/etc/services defines the service ports${endColor}"
erun "cat /etc/services | egrep --color  'bootps|domain|nfs'"
