#!/usr/bin/env eepython
import sys
import os
import pexpect
import time
import signal 
import getpass
from color import *
user = "root"
host = "evencoding.com"
X = getpass.getpass()
tunnel_command = "ssh -L 7777:localhost:7777 -D 1080 %(user)s@%(host)s"
def start_tunnel ():
    try:
        print '-->spawning'
        ssh_tunnel = pexpect.spawn (tunnel_command % globals())
        ssh_tunnel.logfile = sys.stdout
        print '-->expecting password'
	while True:
            result = ssh_tunnel.expect (['password:','Are you sure you want to continue connecting.*'])
            if result == 0:
                print '-->sending password'
                ssh_tunnel.sendline (X)
		break
            elif result == 1:
	        print '--sending yes'
	        ssh_tunnel.sendline('yes')
	    else:
		sys.exit(-1)
        #time.sleep(60)
	ssh_tunnel.interact()
        print '-->expecting EOF'
        ssh_tunnel.expect (pexpect.EOF, timeout=1000)
        print '-->end'
    except Exception as e:
        print str(e)

pid=os.popen('netstat -anpt 2>/dev/null | awk \'$4=="127.0.0.1:8888" {printf $7 }\'').read()
pid=pid.split('/')[0]
if pid: 
    os.kill(int(pid), signal.SIGTERM)
start_tunnel()



