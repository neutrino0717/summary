import os, sys
p=os.path.join(os.path.dirname(sys.argv[0]), os.pardir)
with open(os.path.join(p, 'color.py')) as f:
    exec(f.read())

