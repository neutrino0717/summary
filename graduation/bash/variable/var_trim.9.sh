#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}
String pattern-matching operators
  Operator "#"  means "delete from the left, to the first case of what follows."
  Operator "##" means "delete from the left, to the last case of what follows."
  Operator "%"  means "delete from the right, to the first case of what follows."
  Operator "%%" means "delete from the right, to the last case of what follows."
${endColor}"
eprt ''
elrun <<"EOF"
x="This is my test string."
echo ${x#* }
echo ${x##* }
echo ${x% *}
echo ${x%% *}
EOF

if="$(cat <<EOF
lo        Link encap:Local Loopback 
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:16436  Metric:1
          RX packets:129 errors:0 dropped:0 overruns:0 frame:0
          TX packets:129 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0
          RX bytes:10132 (9.8 KiB)  TX bytes:10132 (9.8 KiB)

p3p2      Link encap:Ethernet  HWaddr 00:0C:29:B2:95:12 
          inet addr:192.168.117.2  Bcast:192.168.117.255  Mask:255.255.255.0
          inet6 addr: fe80::20c:29ff:feb2:9512/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:5669 errors:0 dropped:0 overruns:0 frame:0
          TX packets:4843 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:510238 (498.2 KiB)  TX bytes:1994002 (1.9 MiB)
          Interrupt:19 Base address:0x2080
EOF
)"
elrun <<"EOF"
echo "$if"
if=${if#*p3p2 *inet addr:}; echo "$if"
if=${if%% Bcast*}; echo "$if" 
EOF


