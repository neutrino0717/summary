#!/usr/bin/env esh
###built-in variables
a=$(cat /etc/nsswitch.conf | egrep -v '(^#|^\s*$)' |cat -n|sed 's/^\s*//')
echo "$a"

##ARGC, ARGV
awk 'BEGIN{print ARGC}' p{1..4} 
awk 'BEGIN{for(i=0;i<ARGC;i++){printf "%s ", ARGV[i]}}' p{1..4} 
 
##FILENAME   the current file name
awk 'BEGIN{print FILENAME}' /etc/hosts  #not OK
awk 'END{print FILENAME}' /etc/hosts    #OK

##FS   input field separator
#default is space
awk 'BEGIN{print FS}' /etc/hosts |cat -A
awk -F'|' 'BEGIN{print FS}' /etc/hosts |cat -A 
awk 'BEGIN{print FS}' /etc/hosts |cat -A 

##RS  input record separator

##NF  the number of field
echo $a |awk 'NF>3'

##NR  the line number of current record
echo $a |awk '{print $NF, NF, NR}'
echo $a |awk 'BEGIN{print "lstcol fldnum linenum"} {print $NF, NF, NR}' |column -t


##or
echo $a |awk '/dns|nis/{print}'
echo $a |awk '/dns/{print}; /dns/{print}'
echo $a |awk '/dns/{print}; /nis/{print}'

##print lines before a match
echo $a |awk '/dns/{print}; {print}'
echo $a |awk '/dns/{exit}; {print}'
