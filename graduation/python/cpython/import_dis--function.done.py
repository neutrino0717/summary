#!/usr/bin/env eepython
import dis
def hello():
    print "hello"
    return True
dis.dis(hello)

def plus():
    a = 11
    b = 99
    c = a + b
    print c
    return str(a)
dis.dis(plus)

def concat(a, b):
    return a + b
dis.dis(concat)

def loop():
    for i in xrange(5):
        print i
dis.dis(loop)
