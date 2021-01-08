#!/usr/bin/env eepython

## metaclass: 
#  metaclass is the class of a class
#    #[].__class__    -->   <type 'list'>
#    #list.__class__  -->   <type 'type'>
#    so 'type' is a metaclass
#  Any class whose instances are themselves classes
#    list is type's instance
#    list is a class
#    so 'type' is a metaclass

##two ways to create a class
#1. Class1 defined
class Class1(object):
    foo = 2
    bar = 4
a1 = Class1
print a1, a1.foo, a1.bar
b1 = a1()
print b1, b1.foo, b1.bar
print b1.__class__
print a1.__class__
print Class1.__class__

#2. Class2 created at runtime
def make_a_class(**attrs):
    return type('Class2', (object,), dict(**attrs))
###              ^^^^^^\  ^^^^^^^^^^\ ^^^^^^^^^^^^^^-class attributes in a dict
###                     \            \-class parents
###                      \-class name
a2 = Class2 = make_a_class(foo=2, bar=4)
print a2, a2.foo, a2.bar
b2 = a2()
print b2, b2.foo, b2.bar
print b2.__class__
print a2.__class__
print Class2.__class__

