#!/usr/bin/env esh

###BEGIN block
## BEGIN {awk-commands}
###BODY block
## /pattern/ {awk-commands}
###END block
## END {awk-commands}
a=$(cat /etc/nsswitch.conf | egrep -v '(^#|^\s*$)' |cat -n|sed 's/^\s*//')
echo "$a"
##BEGIN
echo "$a" |awk 'BEGIN{print "---------------------"}{print $0}' 
##basic
echo "$a" |awk '{print}'
echo "$a" |awk '{print $0}'
echo "$a" |awk '{print $1, $NF}'

## /pattern/: match a patten
echo "$a" |awk '/db/'
echo "$a" |awk '/db/{print}'
echo "$a" |awk '$3=="db"'
echo "$a" |awk '$3=="db"{print}'
echo "$a" |awk '{if($3=="db"){print}}'

echo "$a" |awk 'length($3)==2'

##count the number of line that pattern matched
#awk process line by line, so it's possible to count
echo "$a" |awk '/db/{aaa++}END{print aaa}'
echo "$a" |awk '/db/{aaa++}END{print "the number of lines with db are",aaa}'

##the lines that the pattern matched
echo "$a" |awk '/db/{a=a" "NR}END{print "lines with db are",a}'

## -v: use variables
echo $USER
echo "$a" |awk -v usr=$USER '{print usr,$0}'
echo "$a" |awk '{print ENVIRON["USER"],$0}'


