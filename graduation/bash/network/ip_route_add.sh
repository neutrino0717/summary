#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
eprt "
#ip route (need to enable ip_forward)
ip route add 192.168.2.0/24 via 192.168.1.1 dev lan

ip route add default via 10.70.200.222 dev eth0
ip route    
#default via 10.70.200.222 dev eth0

route -n
# ip route add 192.168.2.0/24 via 192.168.1.1 dev lan   
# ip route add 0.0.0.0/0 via 10.10.10.30 dev wan    #default route
# ip route add default via 10.10.10.30 dev wan      #default route
# ip route del 192.168.2.0/24
# traceroute www.google.com    #
# tracepath www.google.com    #..
# mtr www.google.com        #trace dynamic  
"

erun "ip route"
erun "route -n"
