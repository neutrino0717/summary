#!/usr/bin/env python
import os, sys
#os.system('pygmentize -g ' + sys.argv[0])
#print "================== output =================="
from color import *
p=os.path.join(os.path.dirname(sys.argv[0]), os.pardir)
with open(os.path.join(p, 'color.py')) as f:
    exec(f.read())

eprtdoc('''

''')
ebrun('''

''')
