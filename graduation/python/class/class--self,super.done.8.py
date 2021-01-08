#!/usr/bin/env eepython
##self variable
#  represents the instance of the object itself. 
#  Most object-oriented languages pass this as a hidden parameter to the methods defined on an object;
#  Python does not. You have to declare it explicitly.
##super(Classname, instance_or_class): super is a class
#  To begin with super() in itself is simply shorthand for super(A, B), 
#  where A is the class wherein the code occurs, 
#  and B is the first argument to the function in which the code occurs; 
#  so in your particular case, super().__new__(cls) expands to super(CarModel, cls).__new__(cls)

##AKA: super(self.__class__, self)
#  lets you avoid referring to the base class explicitly
#  But the main advantage comes with multiple inheritance
#  syntax changed in Python 3.0: you can just say super().__init__() instead of super(ChildB, self).__init__()
class Base(object):
    def __init__(self):
        print "1. Base initialized"

class ChildA(Base):
    def __init__(self):
        Base.__init__(self)

class ChildB(Base):
    def __init__(self):
        #super(ChildB, self).__init__()
        print "2. type(Base) is ",type(Base)
        print "3. type(super(self.__class__,self)) is ", type(super(self.__class__,self))
        super(self.__class__, self).__init__()  #--> for python2.7 and above
ChildA()
ChildB()
print ChildA.__bases__
print ChildA.__base__
print Base.__base__

class A(object):
    def __init__(self):
        self.x = 'Hello'
    def method_a(self, foo):
        print self.x + ' ' + foo
# We do not need to pass any argument to the __init__ method
a = A()
print A.__dict__
print a.__dict__
# We only need to pass a single argument
a.method_a('Sailor!')
class B(A):
    def __init__(self):
        #super(B, self).__init__()
        super(self.__class__, self).__init__()   #--> for python2.7 and above
        self.x = "from parent: " + self.x
b = B()
b.method_a('Sailor!')

