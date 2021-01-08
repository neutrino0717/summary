#!/usr/bin/env eepython
import distutils.spawn
print distutils.spawn.__doc__
print distutils.spawn.spawn.__doc__
print distutils.spawn.find_executable.__doc__
print distutils.spawn.find_executable('ls')

from distutils.spawn import find_executable
print find_executable('ls')

from distutils.spawn import find_executable
cmds = ('ls', 'uname', 'pwd', 'nocmd', 'ssh')
for cmd in cmds:
    if not find_executable(cmd):
        print "missing required executable '%s', plese check the $PATH env" % cmd
        sys.exit(1)
