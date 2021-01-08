#!/usr/bin/env eepython
##http://stackoverflow.com/questions/6760685/creating-a-singleton-in-python
#override __new__(cls) to define singleton
#1. perfect
class Singleton1(object):
    _instance = None
    def __new__(cls):
        print "__new__ parameter is ", cls 
        if not cls._instance:
            ##Singleton1 and cls are the same 
            cls._instance = super(Singleton1,cls).__new__(cls)
            print "super() parmaeters: ", Singleton1, cls
            print Singleton1 is cls
            cls.y = 10
        return cls._instance
print locals()
print globals()
s1 = Singleton1()
s2 = Singleton1()
print "Singleton OK" if s1 is s2 else "Singleton fails"
#2. it's the same as 1 
class Singleton2(object):
    ##args and kw are empty
    def __new__(cls, *args, **kw):
        print cls, args, kw
        if not hasattr(cls, '_instance'):
            orig = super(Singleton2, cls)
            print "super returns: ", orig
            cls._instance = orig.__new__(cls, *args, **kw)
        return cls._instance
s3 = Singleton2()
s4 = Singleton2()
print "Singleton OK" if s3 is s4 else "Singleton fails"
#3. use decorator
def singleton(class_):
    print "class_ is:", class_
    instances = {}
    def getinstance(*args, **kwargs):
        print "getinstance() arguments: ", args, kwargs
        if class_ not in instances:
            print "create the single instance"
            instances[class_] = class_(*args, **kwargs)
        return instances[class_]
    return getinstance
@singleton
class Singleton3(object): pass
s5 = Singleton3()
s6 = Singleton3()
if s5 is s6: print "Singleton OK"

