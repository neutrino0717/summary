#!/usr/bin/env eepython
import sys, getopt
argv=sys.argv[2:]
print argv
try:
  opts = getopt.getopt(argv,"zxvf:C:")
except getopt.GetoptError:
  print "Usage: "+sys.argv[1]+" [-zxvf <fname>] [-C <dir>]"
  print "       ",sys.argv[1], "-zxvf ~/tmp/tst.tar.gz -C /tmp"
  sys.exit(2)
print opts

import getopt
##set arguments manually
args='-gi -c /root/op153_14A.cfg'.split(); print args
args='-gi -c /root/op153_14A.cfg'.split(); print getopt.getopt(args, 'gic:')
args='-gic /root/op153_14A.cfg'.split();   print getopt.getopt(args, 'gic:')

