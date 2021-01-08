#!/usr/bin/env eepython
##factory pattern: let a function to choose the class to return  
@classmethod
def check1(self, myStr):
    return myStr=="ham"  
@classmethod
def check2(self, myStr):
    return myStr=="sandwich"

BaseClass=type("BaseClass", (object,), {})
C1=type("C1", (BaseClass,), {"x":1, "check":check1})
C2=type("C2", (BaseClass,), {"x":2, "check":check2})

#print BaseClass.__subclasses__()
#print BaseClass
#print BaseClass.__subclasses__()
#print locals()
#print globals()
def myFactory(cc):
    #print globals()
    assert cc in ['ham', 'sandwich']
    for cls in BaseClass.__subclasses__():
        if cls.check(cc):
            return cls() 

m = myFactory('ham')
print m.x
m = myFactory('sandwich'); print m.x
