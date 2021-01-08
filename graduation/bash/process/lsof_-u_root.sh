#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${green}
 -u find the list of files opened by a specific users, use ‘-u’ option.
 -t terse output 
${endColor}"
erun "lsof -u root" 
erun "lsof -u syslog" 
echo
egrep_yellow ".*" <<<"Kill all process that belongs to a particular user"
erun "lsof -t -u neutrino0717 | xargs echo kill -9" 
