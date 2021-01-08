#!/usr/bin/env eepython
## 1.How do we determine the metaclass of a class
#  if a class or its base has a __metaclass__ attribute, it's taken as the metaclass.
#  Otherwise, type is the metaclass.
## 2.How to define a class that has a metaclass other than 'type'
#  class Class1(object):
#      __metaclass__ = MyMeta
## 3.How to create a class that has a metaclass other then 'type'
#  a1 = MyMeta(Class1, bases, dict)
## 4.Metaclass's __new__ and __init__
#  __new__ should be implemented when you want to control the creation of a new class
#           __new__() will return class1 , aka the instance of MyMeta
#  __init__ should be implemented when you want to control the initialization of the new object after it has been created
#  __call__ is called when the already-created class is "called" to instantiate a new object.
#           x.__call__(...) <==> x(...), 
#           __call__() will return the instance of class1
class MyMeta(type):
    def __new__(mymeta, myname, mybases, mydct):
        print "in class MyMeta(type): def __new__(mymeta, myname, mybases, mydct)"
        print "  mymeta             : ", mymeta, type(mymeta)
        print "  myname is a string : ", myname
        print "  mybases            : ", mybases
        print "  mydct              : ", mydct
        # will return <class '__main__.Class1'>
        return super(MyMeta, mymeta).__new__(mymeta, myname, mybases, mydct)
    def __init__(mycls, myname, mybases, mydct):
        print "in class MyMeta(type): def __init__(mycls, myname, mybases, mydct)"
        print "  mycls              : ", mycls, type(mycls)
        print "  myname is a string : ", myname, type(myname)
        print "  mybases            : ", mybases
        print "  mydct              : ", mydct
        super(MyMeta, mycls).__init__(myname, mybases, mydct)
    def __call__(mycls, *args, **kwargs):
        print "in class Mymeta(type): def __call__(mycls, *args, **kwargs)"
        print "  mycls              : ", mycls, type(mycls)
        print "  args               : ", args
        print "  kwargs             : ", kwargs
        #will reuturn <__main__.Class1 object at 0x7fd743166d90>
        return type.__call__(mycls, *args, **kwargs)
        #return super(MyMeta, mycls).__call__(*args, **kwargs)
print "class MyMeta defined"

class Class1(object):
    bar = 2
    __metaclass__ = MyMeta
    def foo(self, param):
        pass
class Class2(object): pass
test = Class1()
print type(MyMeta)
print type(object)
print type(Class1)
print type(Class2)
