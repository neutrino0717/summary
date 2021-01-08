#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
eprt "
[root@epgsim151 ~]# top -u user001
top - 18:29:31 up 8 days,  2:02,  2 users,  load average: 2.87, 2.72, 2.66
Tasks: 288 total,   1 running, 287 sleeping,   0 stopped,   0 zombie
Cpu(s):  6.4%us, 34.6%sy,  0.0%ni, 58.9%id,  0.0%wa,  0.0%hi,  0.0%si,  0.0%st
Mem:  16280928k total, 16123636k used,   157292k free,   153200k buffers
Swap: 16383992k total,    32396k used, 16351596k free,  5434160k cached

  PID USER      PR  NI  VIRT  RES  SHR S %CPU %MEM    TIME+  COMMAND
38843 user001    5 -15 2093m 1.0g  33m S 104.0  6.7   1433:21 VBoxHeadless
39029 user001   20   0 2030m 1.0g  33m S 73.2  6.7 988:49.97 VBoxHeadless
38947 user001   20   0 2030m 1.0g  33m S 67.4  6.7 918:44.47 VBoxHeadless
38894 user001   20   0 2030m 1.0g  33m S 65.5  6.7 889:48.82 VBoxHeadless
39240 user001   20   0 1594m 632m  33m S 23.1  4.0 294:27.66 VBoxHeadless
38790 user001   20   0  129m 1760 1340 S  0.0  0.0   0:00.17 VBoxXPCOMIPCD
38797 user001   20   0  588m 5248 3744 S  0.0  0.0   0:13.39 VBoxSVC
"
elrun("top -u neutrino")

