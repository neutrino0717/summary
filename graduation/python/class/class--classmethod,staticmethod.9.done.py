#!/usr/bin/env eepython

##Difference between @staticmethod and @classmethod in Python:
#
#With classmethods, 
#    the class of the object instance is implicitly passed as the first argument instead of self.
#With staticmethods, 
#    neither self (the object instance) nor cls (the class) is implicitly passed as the first argument. 
#    They behave like plain functions except that you can call them from an instance or the class:
#
##in short term
#    an instance method knows its instance (and from that, its class)
#    a class method knows its class
#    a static method doesn't know its class or instance

import dis
class A(object):
    def foo(self,x):                                  #self --> <__main__.A object at 0xffd7ea8c>
        #print "executing foo(%s,%s)"%(self,x)
        print "foo arguments: %s,%s" % (self,x)
    @classmethod
    def class_foo(cls,x):                             #cls ---> <class '__main__.A'>
        #print "executing class_foo(%s,%s)"%(cls,x)
        print "class_foo arguments: %s,%s" % (cls,x)
    @staticmethod
    def static_foo(x):
        #print "executing static_foo(%s)"%x    
        print "static_fool arguments: %s" %x
a=A()
a.foo(1)
a.class_foo(1)
A.class_foo(1)
a.static_foo(1)
A.static_foo(1)
dis.dis(A)
