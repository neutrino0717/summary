#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}
lsof    list open files, In unix, everything is a file, ( pipes, sockets, directories, devices, etc.).
${endColor}"
echo -e "${red}list processes that opened files in /var/log${endColor}"
erun "lsof | head -n 1"
erun "lsof | grep -i /var/log/" 

