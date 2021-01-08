#!/usr/bin/env eepython
###Use template to generat ifcfg-eth.xxx file
##for python 2.6 and above, myview: preferred
sss='''
DEVICE=eth1.{vlan}
BOOTPROTO=static
ONBOOT=yes
TYPE=Ethernet
IPADDR={ip}
NETMASK={mask}
VLAN=yes
'''
d={'vlan':561, 'ip':'10.69.23.49', 'mask':'255.255.255.248'}
print sss.format(**d)

##for python 2.6 below str.format not supported, use below instead
#1. %()s
sss='''
DEVICE=eth1.%(vlan)s
BOOTPROTO=static
ONBOOT=yes
TYPE=Ethernet
IPADDR=%(ip)s
NETMASK=%(mask)s
VLAN=yes
'''
print sss % d

#2. %s
sss='''
DEVICE=eth1.%s
BOOTPROTO=static
ONBOOT=yes
TYPE=Ethernet
IPADDR=%s
NETMASK=%s
VLAN=yes
'''
print sss % (d['vlan'], d['ip'], d['mask'])

## use string.Template, myview: preferred
import string
sss='''
DEVICE=eth1.$vlan
BOOTPROTO=static
ONBOOT=yes
TYPE=Ethernet
IPADDR=$ip
NETMASK=$mask
VLAN=yes
'''
print string.Template(sss).substitute(d)
