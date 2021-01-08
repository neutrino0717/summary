#!/bin/bash -v
a=`echo rabbit{1..7} | sed 's| |\n|g'`

echo "$a"

echo "$a" | sed ''

#n       globally print nothing
echo "$a" | sed -n ''

#p       print 
echo "$a" | sed -n 'p'

#1,4p    print 1-4 lines
echo "$a" | sed -n '1,4p'

#1,4!p   not print 1-4 lines
echo "$a" | sed -n '1,4!p'

#2p     print 2nd line
echo "$a" | sed -n '2p'

#$p     print the last line
echo "$a" | sed -n '$p'

#d     delete the line end with 7
echo "$a" | sed '/^.*7$/d'

#      delete the lines end with 6 and 7
echo "$a" | sed -e '/^.*7$/d' -e '/^.*6$/d'
