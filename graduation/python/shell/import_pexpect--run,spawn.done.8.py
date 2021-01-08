#!/usr/bin/env eepython
#pexpect.run(cmd)
##equivelent to
#child = pexpect.spawn(cmd)
#child.expect(pexpect.EOF)
#print child.before

import pexpect
child = pexpect.spawn('uname -a')
child.expect(pexpect.EOF)
print child.before
print pexpect.run('uname -a')
print pexpect.run('bash -c "uname -a"')
#Remember that pexpect does NOT interpret shell meta characters such as redirect, pipe, or wild cards (>, |, or *). This is a common mistake. If you want to run a command and pipe it through another command then you must also start a shell. For example:
#print pexpect.run('ls -al | grep import')
## need to be root, use sudo
print pexpect.run('bash -c "ls -al | grep import"')
#equivelent
child = pexpect.spawn('/bin/bash', ['-c', 'ls -al|grep import'])
child.expect(pexpect.EOF)
print child.before
