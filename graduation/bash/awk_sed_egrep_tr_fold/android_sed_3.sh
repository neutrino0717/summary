#!/bin/esh
a=$(cat /etc/nsswitch.conf | egrep -v '(^#|^\s*$)'|cat -n)
echo "$a"

##command =, write linu number
echo "$a" |sed '1,3='
echo "$a" |sed '/db/='
echo "$a" |sed -n '/db/='

#print the total line number
echo "$a" |sed -n '$='
echo "$a" |wc -l

##command s, substitute
#[addr1[ ,addr2]]s/pattern/replacement/[flags]
echo "$a" |sed '2,5s/:/|/'

#
echo "$a" |sed '2,5s/:/|/; 2,5s/[0-9]/|/'
echo "$a" |sed '2,5s/[0-9:]/|/g'

#option n: not print the buffer
#flag p: show only the changed lines
#flag w: write changed lines to file
#flag i: case insenstive
echo "$a" |sed -n '2,5s/[0-9:]/|/gp'
echo "$a" |sed -n '2,5s/:/|/; 2,5s/[0-9]/|/p'
echo "$a" |sed -n '2,5s/[0-9:]/|/gw /tmp/1.txt'; cat /tmp/1.txt

#delimeter other thant /
#|, @, !, ^
echo "$a" |sed -n '2,5s/:/|/p'
echo "$a" |sed -n '2,5s@:@|@p'
echo "$a" |sed -n '2,5s^:^|^p'
echo "$a" |sed -n '2,5s!:!|!p'
echo "$a" |sed -n '2,5s&:&|&p'
echo "$a" |sed -n '2,5s|:|,|p'

##&, store the matched pattern
echo "$a" |sed 's/db/"&"/'

##create substrings
echo "$a" |sed 's/\s*\(\w\+\).*/"\1"/'
echo "$a" |sed 's/\s*\(\w\+\)\s*\(\w\+\).*/"\1" "\2"/'


