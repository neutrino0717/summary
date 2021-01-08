#!/usr/bin/env eepython
import os, sys
##__new__ has to create the instance first, so __init__ can initialize it
#
##__new__ 
#  when you need to control the creation of a new instance.
#  it's the first step --> return a new instance of your class
#  static class method
#  #do not override __new__ unless you're subclassing an immutable type like str, int, unicode or tuple.

##__init__ 
#  when you need to control initialization of a new instance.
#  it's the second step --> doesn't return anything, only initiallizing the instance the __new__ returned
#  instance method
#  __init__ takes self as parameter

class A(object): pass
class B(): pass
print hasattr(A, "__new__"), hasattr(A, "__init__")
print hasattr(B, "__new__"), hasattr(B, "__init__")
print A.__dict__
print B.__dict__
print dir(A)
print dir(B)

class A(object):
    x=7
    def __init__(self):
        self.y=11

class B():
    x=7
    def __init__(self):
        self.y=11
print A.__dict__
print B.__dict__
print A().__dict__
print B().__dict__

#check the paraments of __new__
class C(object):
    def __new__(*args, **kwargs):
        print args
        print kwargs
C()
print repr(C)

