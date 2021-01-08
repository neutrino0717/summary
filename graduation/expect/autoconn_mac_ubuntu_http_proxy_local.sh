#!/bin/bash
cat <<EOF
#add below to crontab, however you need set password variable fist 
*/5 * * * * ~/graduation/learning/expect/$0
#or run
~/graduation/learning/expect/$0
ctr-z
bg
disown
EOF

export https_proxy=http://127.0.0.1:8888
export http_proxy=http://127.0.0.1:8888
read -p "Password:" -s password

p=`netstat -anpt 2>/dev/null | awk   '$4=="127.0.0.1:8888" {printf $7 }'`
if [  "$p" != "" ]; then
  pid=`echo $p|egrep -o '[[:digit:]]*'`
  #echo "kill -9 $pid" | bash -x
  echo "local http proxy already exists, pid=$pid"
fi

expect <<EOD
set prompt "~#"
set timeout 600
set timer 1
spawn ssh -L 8888:localhost:8888 root@evencoding.com
expect {
	    "*want to continue connecting*"  { send -- "yes\r"; exp_continue }
	    "*assword:"  { send -- "${password}\r"; exp_continue}
	    $prompt { send -- "\r" }
}

expect $prompt
interact
EOD
