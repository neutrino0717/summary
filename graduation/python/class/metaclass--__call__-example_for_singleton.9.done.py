#!/usr/bin/env eepython
#in __call__(cls, *args, **kwargs),
#   cls is the instance of metaclass Singleton
#   so cls is class Myclass
class Singleton(type):
    _instances = {}
    def __call__(cls, *args, **kwargs):
        print cls, cls.__class__, Singleton
        print id(Singleton._instances)
        print id(cls._instances)
        print "dir(Singleton) is: ", dir(Singleton)
        print "dir(cls) is: ", dir(cls)
        if cls not in cls._instances:
            #or below, but why Myclass/cls has access to Singleton._instances
            #or Singleton._instances[cls] = super(Singleton,cls).__call__(*args, **kwargs)
            #or type(cls)._instances[cls] = super(Singleton,cls).__call__(*args, **kwargs)
            cls._instances[cls] = super(Singleton,cls).__call__(*args, **kwargs)
            cls.x = 5
        #print cls._instances
        return cls._instances[cls]

class MyClass(object):
    __metaclass__ = Singleton

m = MyClass()
v = MyClass()
print m.x
m.x = 9
print v.x
