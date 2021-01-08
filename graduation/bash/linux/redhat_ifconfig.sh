#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

eprtdoc <<EOF
#add a permanent address
[root@epgsim154 network-scripts]# cat ifcfg-eth0:1
DEVICE="eth0:1"
BOOTPROTO="static"
NM_CONTROLLED="no"
ONBOOT="yes"
IPADDR=10.46.69.72
NETMASK=255.255.255.240

#add a temparary address
ifconfig eth0:0 10.132.143.250 netmask 255.255.240.0 up

#remove
ifconfig eth0:0 down
EOF
