#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
#change hostname without reboot and permanantly
[root@localhost ~]# vim /etc/sysconfig/network
NETWORKING=yes
HOSTNAME=epg17-4

[root@localhost ~]# vim /etc/hosts
192.168.222.128 epg17-4
127.0.0.1   localhost localhost.localdomain localhost4 localhost4.localdomain4
::1         localhost localhost.localdomain localhost6 localhost6.localdomain6

[root@localhost ~]# reboot
# need a reboot
[root@localhost ~]# hostname
epg17-4

EOF

elrun <<"EOF"

EOF
