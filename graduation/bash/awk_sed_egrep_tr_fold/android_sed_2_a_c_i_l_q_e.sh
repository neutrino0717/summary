#!/bin/esh
a=$(cat /etc/nsswitch.conf | egrep -v '(^#|^\s*$)' |cat -n)
echo "$a"

##command append
echo "$a" |sed '4 a this is a  new line'
echo "$a" |sed '$ a this is a  new line'
echo "$a" |sed '/services/a this is a  new line'

##command change
echo "$a" |sed '$   c this line is replaced'
echo "$a" |sed '4,9 c those lines are replaced'
echo "$a" |sed '/services/,$ c this line is replaced'

##command insert
echo "$a" |sed '1 i this is a  new line'
#echo "$a" |sed '1 a this is a  new line'
#echo "$a" |sed '1 c this is a  new line'

##command l, display hidden charactors \t, $(end of line) etc
echo "$a" |cat -A
echo "$a" |sed -n 'l'

##command q, quit the executing flow
[addr]q [value]
echo "$a" |sed  '1q'
echo "$a" |sed  '/group/q'
#quit with exit code 99
echo "$a" |sed  '/group/q 99'; echo $?

##command e, execute
#[addr1[,addr2]] e [command]
echo "$a" |sed '/shadow/ e uptime'
echo "$a" |sed '3 r /proc/uptime'

##others
##input is handled line by line, see below
echo "$a" |sed '1d'
echo "$a" |sed '1d;4p'
echo "$a" |sed '1d;4p;3,9d'
