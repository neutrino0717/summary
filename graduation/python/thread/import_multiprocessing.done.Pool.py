#!/usr/bin/env eepython
##side-stepping the Global Interpreter Lock by using subprocesses instead of threads
import multiprocessing
def f1(x): return x*x

##return value from all the processes will be in a list as Pool.map() function's return value
print multiprocessing.Pool(processes=4).map(f1,range(1,11))
