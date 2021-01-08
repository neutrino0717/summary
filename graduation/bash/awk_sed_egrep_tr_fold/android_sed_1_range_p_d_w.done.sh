#!/bin/esh
a=$(cat /etc/nsswitch.conf | egrep -v '(^#|^\s*$)' |cat -n)
echo "$a"

##absolute basic
#no command and no option
echo "$a" |sed -n ''  #no display buffer 
echo "$a" |sed ''
echo "$a" |sed -n 'p'

##handle address range, how to select line 1 and line 7
echo "$a" |sed -n '7p'
echo "$a" |sed -n '7,$p'
echo "$a" |sed -n '7,+2p'         #or '7,9p'
echo "$a" |sed -n '1~2p'

##handle pattern range, support regex fully
echo "$a" 
echo "$a" |sed -n '/services/p'
echo "$a" |sed -n '/services/,/rpc/p'
echo "$a" |sed -n '/services/,$p'
echo "$a" |sed -n '/services/,+2p'

##command delete
#[addr1[,addr2]]d
echo "$a" 
#d will delete from buffer,so nothing send to output stream 
echo "$a" |sed 'd'
#delete 1~9 in buffer, then send buffer to output stream
echo "$a" |sed '1,9d' 
echo "$a" |sed '1~2d'
echo "$a" |sed '/db/d'
echo "$a" |sed '/shadow/d'
echo "$a" |sed '/shadow/,/rpc/d'
echo "$a" |sed '/shadow/,$d'
echo "$a" |sed '/shadow/,+2d'

##command write
#[addr1,[addr2]]w filename
#not display the buffer, howver buffer is still there
echo "$a" |sed -n 'w /tmp/1.txt'; cat /tmp/1.txt
echo "$a" |sed -n '2 w /tmp/1.txt'; cat /tmp/1.txt
echo "$a" |sed -n '2~2 w /tmp/1.txt'; cat /tmp/1.txt
echo "$a" |sed -n '2,9! w /tmp/1.txt'; cat /tmp/1.txt
echo "$a" |sed -n '/db/ w /tmp/1.txt'; cat /tmp/1.txt
echo "$a" |sed -n '/db/! w /tmp/1.txt'; cat /tmp/1.txt

##command read
echo "$a" |sed '2 r /proc/uptime' 
##to use multiple command use -e switch
