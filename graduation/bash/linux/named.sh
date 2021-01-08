#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${red}${endColor}"
eprtdoc <<"EOF"
ps aux | grep -i named
#named    10129  0.0  0.0 455904  6244 ?        Ssl  07:13   0:00 /usr/sbin/named -u named -t /var/named/chroot
rootpath="/var/named/chroot"
namedConf=$rootpath/etc/named.conf
cat $namedconf | grep -i directory
#        directory "/var/named";
namedDataFile=$rootpath/var/named
EOF
