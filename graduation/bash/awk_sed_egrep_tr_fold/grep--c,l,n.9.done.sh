#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
eprt '
show every line in the log files that does not contain the string "info", case insensitive
grep -i -n -v "info" -R /var/log/*
     |   | ~~revert   ~recursive
     |   ~ display line number
     ~~case insensitive
'

elrun <<"EOF"
#c   -- How many lines matched the text pattern in a particular file?   
#cv  -- How many lines that don't match
#n   -- print lines number
#l   -- List only the matched file names
#r,R -- recusively
grep -c local /etc/hosts
grep -cv local /etc/hosts
grep -Rl wait ~/graduation/bash --color
grep -Rn wait ~/graduation/bash --color
grep -i -n "info" -R /var/log* | head -n 2
EOF
