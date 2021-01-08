#!/usr/bin/env eepython
x='010'
y = x=='010' and "beijing" or "not beijing"; print y
x='021'
y = x=='010' and "beijing" or "not beijing"; print y

def f(x):
    if x ==0: return 1
    else: return x * f(x -1)
print f(0), f(1), f(2), f(3)

def f(x):
    #return x > 0 and x * f(x -1) or 1
    return x and x * f(x -1) or 1
print f(0), f(1), f(2), f(3)

f = lambda x: x and x * f(x - 1) or 1
print f(0), f(1), f(2), f(3)
