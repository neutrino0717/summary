#!/usr/bin/env eepython
from multiprocessing import Process
from multiprocessing import Pool
def f(title):
    print '-->{}'.format(title)
    print 'module name:', __name__
    if hasattr(os, 'getppid'):  # only available on Unix
        print 'parent process:', os.getppid()
    print 'process id:', os.getpid()
    return title
##current process id
print os.getpid()

##function call will not start a new process
f('function all')

##function call with Process will start a new process
p = Process(target=f, args=('function all with process',))
p.start()
p.join()

##function call with Pool will start multiple new processes')
p2 = Pool(5)
result = p2.map(f, ['function call {} in pool'.format(x) for x in xrange(7)])
#return value from all the processes will be in a list
print result
