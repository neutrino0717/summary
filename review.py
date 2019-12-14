#!/usr/bin/python
import os
import sys
import re
import logging
from color import *


def pp(str):
    print("\n" + RED + "========= %s =========" % str + ENDC)


def ep(str):
    print RED + str + ENDC
    exec (str, globals())


pp("multilayer decorator")


def strong_decorate(func):  # get_text = strong_decorate(get_text)
    def func_wrapper(name):
        return "<strong>{0}</strong>".format(func(name))

    return func_wrapper


def p_decorate(func):
    def func_wrapper(name):
        return "<p>{0}</p>".format(func(name))

    return func_wrapper


def div_decorate(func):
    def func_wrapper(name):
        return "<div>{0}</div>".format(func(name))

    return func_wrapper


# get_text = strong_decorate(get_text)
# get_text = p_decorate(get_text)
# get_text = div_decorate(get_text)
@div_decorate
@p_decorate
@strong_decorate
def get_text(name):
    return "Hello " + name


print(get_text("John"))
# <div><p><strong>Hello John</strong></p></div>

pp("Passing arguments to decorators")


# from functools import wraps
def tags(tag_name):
    def tags_decorator(func):
        # @wraps(func)       #--> get_text.__name__, get_text.__doc__, get_text.__module__ will return correct values
        def func_wrapper(name):
            return "<{1}>{0}</{1}>".format(func(name), tag_name)

        return func_wrapper

    return tags_decorator


@tags("div")
@tags("p")
@tags("strong")
def get_text(name):
    return "Hello " + name


# get_text = tags("strong")(get_text)
# get_text = tags("p")(get_text)
# get_text = tags("div")(get_text)
print(get_text("John"))
# <div><p><strong>Hello John</strong></p></div>

pp("namemangle to prevent accidental access")


# _var, _func():       semiprivate and meant just for convention
# __var, __func():     namemangle to prevent accidental access,
#                     __var changed to _cls__var by interpreter to ensure that the name will not overlap
#                     with a similar name in another class
# __var__, __func__(): reserved for builtin methods/variables
class Test(object):
    def __init__(self):
        self._a = 'a'
        self.__b = 'b'
        self.__c__ = 'c'


t = Test()
print t._a  # a  ## _a is a private variable
print t.__c__  # c  ## __c__ is a private variable, and in my view only for buildin, but it's OK if you use it
# print t.__b         ## __b not exist namemangling, use _Test__b instead
print t._Test__b  # b

pp("object.__dict__")
from pprint import pprint


class A:
    pass


class B(object):
    pass


a = A();
b = B()

ep("pprint(dict(object.__dict__))")
# epp("pprint(dict(A.__dict__))")
# epp("print(B.__dict__)")
# epp("print(B.__dict__['__dict__'])")
# epp("pprint(a.__dict__)")
# epp("pprint(b.__dict__)")

pp("object.__file__")
ep("print [ i for i in dir(os) if '__' in i ]")
ep("print os.__file__, os.__name__, __name__")
ep("print re.__file__")
ep("print logging.__file__")

'''
#__init__.py will run when you import a package.
  For instance, import idlelib within a program, runs idlelib/__init__.py
#__main__.py will run when you run a package as the main program.
  For instance, python -m idlelib at a command line runs idlelib/__main__.py,

#1.  sys.path
As long as the parent directory is on sys.path you will be able to call:
import mymodule       #or
from mymodule.submodule import something

#2.  __init__.py
You are dealing with a package. The package structure you should have is:
/dir_in_sys.path
    /mypackage             # This is not really a module - it's a package
        __init__.py         # loaded when you `import mypackage` or anything below it
        some.py             # import mypackage.some
        implementation.py   # import mypackage.implementation
        files.py            # import mypackage.files
        /submodule
            __init__.py       # loaded when you `import mypackage.submodule` or anything below it
            submodule_impl.py # import mypackage.submodule.submodule_impl
            goes.py           # import mypackage.submodule.goes
            here.py           # import mypackage.submodule.here
2.1 suppose class CustomClass is defined in the submodule_impl.py module
2.2  in __init__.py, add below
from .submodule_impl import CustomClass
2.3 #Now CustomClass can be imported directly from submodule
from mymodule.submodule import CustomClass
'''

pp("__init__.py")

# for example below:
# 1. import unitest will run __init__.py automaticaly
# 2. in __init__.py, result.py is importted
# 3. as a result all classes in result.py can be used now
import unittest

ep("print unittest.__file__")
ep("print [x for x in open(unittest.__file__[0:-1]) if 'from .result' in x]")
ep("print next(x for x in open(unittest.__file__[0:-1]) if 'from .result' in x)")
ep("print unittest")
ep("print unittest.result")
ep("print unittest.TestResult")

pp("atexit")
import atexit

ep('assert True, "it is True, so no output"')
ep("assert 'tough' in 'toughtough'")

# Below will throw out AssertionError exception, and exit
# assert False, "the result is False."
# print "this will not be executed"

pp("atexit decorator")


@atexit.register
def goodbye():
    print 'Goodbye, no more message will be displayed'


print "before run sys.exit()"
# sys.exit()        #uncomment this to test
print "after run sys.exit()"

pp("bitwise")
ebrun('''
a = 60            # 60 = 0011 1100 
b = 13            # 13 = 0000 1101 
c = 0
print a & b;        # 12 = 0000 1100
print a | b;        # 61 = 0011 1101 
print a ^ b;        # 49 = 0011 0001
print ~a;           # -61 = 1100 0011
print a << 2;       # 240 = 1111 0000
print a >> 2;       # 15 = 0000 1111

#use bitwise to check if even or odd
print 383 & 1
print 888 & 1

aa = 123
if aa & 1: print "it is odd"
''')

pp("True is 1, False is 0")
ebrun("""
print "true" if 1 else "false"
print "true" if 0 else "false"
print "true" if '' else "false"
print "true" if [] else "false"
print "true" if False else "false"
print "true" if None else "false"

print True + True
print False + False
print True + False
print True == 1, True == 0, True == 2
print False ==1, False ==0, False ==2

""")

pp("tenary")
ebrun('''
x='021'; y =(x=='021' and "SH" or "not SH"); print y; #SH
x='021'; y = x=='021' and "SH" or "not SH";  print y; #SH
x='010'; y = x=='021' and "SH" or "not SH";  print y; #not SH
y = 1        and "SH" or "not SH";  print y; #SH
y = 0        and "SH" or "not SH";  print y; #not SH
''')

pp("calendar")
ebrun('''
import calendar
cal = calendar.month(2016, 4)
print cal
print type(cal)
#Returns a 3-column calendar for an entire year as a multi-line string using the formatyear() of the TextCalendar class.
#w  The width between two columns. Default value is 2.
#l  Blank line between two rows. Default value is 1. 
#c  Space between two months (Column wise). Default value is 6. 
#m  Number of months in a row. Default value is 3.  
print calendar.calendar(1975,2,1,6,3)
''')

pp(
    "callable() function. The function checks if an object is a callable object. Or in other words, if an object is a function. ")
ebrun('''
print callable.__doc__
class Car:
    def setName(self, name):
        self.name = name

c = Car(); print callable(c.setName)
def fun(): pass
print callable(fun)
print callable([])
print callable(1)
''')

pp("cmp")
ebrun('''
print dir(cmp)
print cmp.__doc__
print cmp.__class__
print cmp(5,10)
print cmp(10,10)
print cmp(10,5)
''')

pp("for break continue else")
ebrun('''
def func(p1):
    for i in xrange(p1+1):
        if i==7: print "break out!"; break
        if i==2: print "two",; continue
        print i,
    else:
        print "done!"
func(10)
func(5)
''')

pp("try except else")
ebrun('''
def func(*a_list):
    try:
        print 'the list is:', a_list
        print 'third element:', a_list[2]
    except IndexError:
        print 'raised IndexError'
    else:
        print 'no error in try-block'
func()
func(1,2,3)
''')

pp("while else")
erun('''
i = 0
while i < 2:
    print 'in while: ', i
    i += 1
else:
    print 'in else: ', i   
''')

pp("for else")
erun('''
for i in range(2):
    print 'in while: ', i
else:
    print 'in else: ', i
   
''')

pp("deepcopy")
import copy

ebrun('''
a = [[1,2,3],[4,5,6]]
b = a
a.append(7); print a; print b           #make change to a; b also changed

##shallow copy
import copy
a = [[1,2,3],[4,5,6]]
b = copy.copy(a)
a.append(7); print a; print b           #make change to a; b not changed because of copy 
a[0][0] = 0; print a; print b           #make change to a; b also changed because of shallow copy only

##deep copy
import copy
a = [[1,2,3],[4,5,6]]
b = copy.deepcopy(a)
a.append(7); print a; print b  
a[0][0] = 0; print a; print b  


aa = [3, 2, 1]
bb = aa
#an interesting way to do deep copy
cc = aa[:]
print id(aa), id(bb), id(cc)
aa.append(4)
print aa, bb, cc
#dict deep copy
''')

pp("collections.Counter")
ebrun('''
from collections import Counter
import inspect

##A Counter is a dict subclass for counting hashable objects.
print inspect.getmro(Counter)

##class collections.Counter([iterable-or-mapping])
c = Counter();                      print c
c = Counter({'red': 4, 'blue': 2}); print c
c = Counter(['eggs', 'ham']);       print c
c = Counter('gallahad');            print c
c = Counter(cats=4, dogs=8);        print c

##for missing items return 0, instead of raising a KeyError
c = Counter(['eggs', 'ham']);       print c, c['hello'], c.get('hello')

## elements() return an iterator over elements repeating each as many times as its count
c = Counter(a=4, b=2, c=0, d=-2);   print c.elements(); print list(c.elements())

## most_common([n]) Return a list of the n most common elements and their counts from the most common to the least
print Counter('abracadabra').most_common(3)

## subtract([iterable-or-mapping]) Elements are subtracted from an iterable or from another mapping (or counter).
c = Counter(a=4, b=2, c=0, d=-2)
d = Counter(a=1, b=2, c=3, d=4)
c.subtract(d); print c
print sum(c.values())            # total of all counts, aka, 3 + 0 + (-3) + (-6)
c+=Counter();  print c           # remove zero and negative counts

##
c = Counter(a=3, b=1)
d = Counter(a=1, b=2)
print c + d                       # add two counters together:  c[x] + d[x]
print c - d                       # subtract (keeping only positive counts)
print c & d                       # intersection:  min(c[x], d[x])
print c | d                       # union:  max(c[x], d[x])
''')

###when you need to build a huge string, please use cStringIO
###myview: cStringIO is similiar to StringBuffer in Java
pp("cStringIO")
import cStringIO

output = cStringIO.StringIO()
output.write('First line.\n')
# add the \n automatically
print >> output, 'Second line.'
output.write('Third line.\n')

# Retrieve file contents -- this will be
# 'First line.\nSecond line.\n'
contents = output.getvalue()
print contents
# Close object and discard memory buffer, .getvalue() will now raise an exception.
output.close()

##Usually, a Python dictionary throws a KeyError if you try to get an item with a key that is not currently in the dictionary.
##The defaultdict in contrast will simply create any items that you try to access (provided of course they do not exist yet).
##
##To create such a "default" item, it calls the function object that you pass in the constructor (more precisely, it's an arbitrary "callable" object, which includes function and type objects).
##
##1.
##For the first example, default items are created using int(), which will return the integer object 0.
##
##2.
##For the second example, default items are created using list(), which returns a new empty list object.
from collections import defaultdict
import inspect

# defaultdict is just a subclass of the standard dict type
pp("defaultdict for int, list, dict")
ebrun('''
from collections import defaultdict
print inspect.getmro(defaultdict)
print int()
print list()
print dict()
s = 'mississippi'

#default items are created using int(), which will return the integer object 0.
d = defaultdict(int)
print d
for k in s:
    d[k] += 1  #int() will be called when d[k], and assign d[k] = int()
print d
print d.items()

#default items are created using list(), which returns a new empty list object.
s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
d = defaultdict(list)
print d

###list() will be called whtn d[k], and assgin d[k]=list()
for k, v in s:
    d[k].append(v)   
print d

#default items are created using dict(), which returns a new empty dict object
data=defaultdict(dict)
for n in xrange(7):
    data[n]["rnc"] = "RNC" + str(n)
    data[n]["lac"] = "LAC" + str(n)
print data
for n in xrange(7):
    print str(n) + '--> ' + str(data[n])
''')

pp("use dict to store list")
ebrun('''
### if elements in dict are list, how to give default value '[]' 
##1. when use dict, no default value build in for dict
contxt = {}
if True:
    if "name_list" in contxt:
        contxt["name_list"].append("Fiona")
    else:
        contxt["name_list"] = ["Fiona"]
print contxt
''')

pp("use defaultdict to store list")
ebrun('''
##2. when use defaultdict, default value is available for all elements
from collections import defaultdict
contxt = defaultdict(list)
contxt["name_list"].append("Fiona")
print contxt
''')

pp("use dict setdefault")
ebrun('''
##3. use setdefault to set default for only one element
contxt = {}
contxt.setdefault("name_list", []).append("Fiona")
print contxt

contxt = {}
print contxt.get("name_list", [])
print contxt.get("name_list")
''')

pp("use fromkeys")
ebrun('''
##4. use fromkeys to set default for multiple elements
#   fromkeys() creates a new dictionary with keys from seq and values set to value.
#   dict.fromkeys(seq[, value]))
lst = ['name_list', 'school_list']
#warn: the value [] is for all elements, so normaly we should use immutable as value
contxt = {}.fromkeys(lst, [])
print contxt
contxt['name_list'].append("Fiona")
print contxt
#                ^^^^^^                  ^^^^^^^
''')

pp("make dict with two list")
ebrun('''
keys = ['a', 'b', 'c']
values = [1, 2, 3]
dd = dict(zip(keys, values))
print dd
#reverse dict
print {v: k for k, v in dd.items()}
#another way to reverse dict
print                 dd.items()
print            zip(*dd.items())
print            zip(*dd.items())[::-1]
print      zip(*(zip(*dd.items())[::-1]))
print dict(zip(*(zip(*dd.items())[::-1])))
#the 3rd way
print dict(zip(dd.values(), dd.keys()))
''')

pp("deque")

ebrun('''
###Deques support thread-safe, memory efficient appends and pops from either side of the deque
###Deques are a generalization of stacks and queues the name is pronounced "deck" and is short for "double-ended queue"

from collections import deque

##deque([iterable[, maxlen]]) --> deque object
d = deque('lo');
print d
##extend(iterable), extendleft(iterable)
d.extend('ves');
print d
##append(x), apend on both sides
d.append('physics')
d.appendleft('Evan')
print d
##iterate over the deque's elements
for elem in d:
    print elem.upper(),
##pop() on both sides
d.pop();
print d
d.popleft();
print d
##reverse
print reversed(d)
print deque(reversed(d))
print list(reversed(d))
##rotate
d.rotate(1);
print d
d.rotate(-1);
print d
##slice just as list
print d[0], d[-1]
print 'o' in d
##clear
d.clear();
print d
''')


pp("dir")
ebrun('''
###dir() function
##dir() is the most important function when doing introspection. The function returns a sorted list of attributes and methods belonging to an object
###why dir() doesn't display __dict__ attribute
print dir.__doc__

class Foo:
    def __init__(self):
        self.a = "bar"
        self.b = 4711
global a
a=Foo(); 
print type(Foo), dir(Foo)
print type(a),   dir(a)
print a; print a.__class__.__name__
print type(1),   dir(1)
print type(int), dir(int)

''')

pp("__dict__")
ebrun('''
class Base():
    def __init__(self, conf):
        print self
        self.__conf__ = conf
        print self.__dict__
        print dir(self)
class Test(Base):
      a = 1
      b = 2
      def func1(self):
        self.c = "hello"

## self is instance of subclass
t = Test("myconf")
print t
##__dict__ only contains attributes of instance itself
print t.__dict__
t.func1()
print t.__dict__
##dir() contains __dict_ and class attribues,etc
print dir(t)


''')


pp("enumerate")

##enumerate(sequence, start=0)
#Return an enumerate object. sequence must be a sequence, an iterator, or some other object which supports iteration. The next() method of the iterator returned by enumerate() returns a tuple containing a count (from start which defaults to 0) and the values obtained from iterating over sequence:
#
##my_enumerate() below is similar to enmerate(), however
#The real enumerate function returns an iterator, not an generator. You can see this if you call help(x) after doing creating an enumerate object:
#
#In Python, generators are basically a specific type of iterator that's implemented by using a yield to return data from a function.
#However, enumerate is actually implemented in C, not pure Python, so there's no yield involved. You can find the source here: http://hg.python.org/cpython/file/2.7/Objects/enumobject.c
#

ebrun('''
def my_enumerate(sequence, start=0):
    n = start
    for elem in sequence:
        yield n, elem
        n += 1
# 1
e=enumerate    (["spring", "summer","fall" ,"winter"], 1)
##enumerate return an iterator(enumerate is iterator)
print type(e), dir(e)
print list(e)
import inspect; print inspect.getmro(enumerate)

# 2 
##my_enumerate return a generator
e=my_enumerate (["spring", "summer","fall" ,"winter"], 1)
print type(e), dir(e)
print list(e)

## use for loop
e=enumerate    (["spring", "summer","fall" ,"winter"])
for i in e: print i
e=my_enumerate (["spring", "summer","fall" ,"winter"])
for i in e: print i
''')

pp("eval and exec")
ebrun('''
#eval and exec have these two differences:
#eval: take a single expression, return a value
#exec: take a block,             return None 
#
#1.eval accepts only a single expression, 
#  exec can take a code block that has Python statements: loops, try: except:, class and function/method definitions and so on.
#2.eval returns the value of the given expression, 
#  exec always returns None, ignores the return value from its code

a=5; a = eval('37 + a'); print a          #42
a=5; exec('a = 37 + a'); print a          #42 
#a=5; eval('a = 37 + a')                   #SyntaxError: invalid syntax, you cannot evaluate a statement with eval
''')

pp("try except raise")
###1. the way to capture multiple exceptions is use a tuple as the first parmamter of except
###2. and always use 'as', for both python 2&3 support it
erun("""
try:
    l = ["a", "b"]
    int(l[2])
except (ValueError, IndexError) as e:  
    print "expection captured"

""")

erun("""
##raise an exception
#raise NameError('HiThere')

#raise then capture an exception
try:
    raise NameError('HiThere1')
except NameError:
    print 'An exception captured!'
""")

erun("""
##re-raise the same exception
#If you need to determine whether an exception was raised but don't intend to handle it, a simpler form of the raise statement allows you to re-raise the same exception:
try:
    raise NameError('HiThere2')
except NameError:
    print 'An exception flew by!'
    #raise    #comment out the raise NameError
""")

pp("filter and map")
ebrun("""
##The function filter(function, list) offers an elegant way to print out all the elements of a list, that for which the function function returns True. 

fib = [0,1,1,2,3,5,8,13,21,34,55]
print "Odd numbers: ", filter(lambda x: x % 2, fib)
print "Even numbers:", filter(lambda x: x % 2 == 0, fib)

##print all elements start with 'h'
f = ['hello',"where", 'hare', "hmm"]
print filter(lambda x: x[0:1] == 'h', f)
print filter(lambda x: x.startswith('h'), f)

import os
dir1 =  os.path.dirname(os.path.abspath(os.getcwd())); print dir1
dir2 = os.path.dirname(dir1);                          print dir2
flst = os.listdir(dir1);                               print flst
##print files starting with 'c'
flt1 = filter(lambda x: x.startswith('c'), flst);      print flt1
##removing the '.py' extension
flt2 = map(lambda x: x.rstrip('.py'), flst);           print flt2
""")

pp("positional arguments and named arguments")
ebrun("""
##use individual parameters
def func(p1,p2): 
    print(p1, p2)
print func.__doc__
tup=("param1","param2")
func("param1","param2")
func(*tup)

##The single star * unpacks the sequence/collection into positional arguments, use tuple as parmaters instead
def func(*t): print(t)
tup=("one", 2, 3.0)
func("one", 2, 3.0)
func(*tup)

##The double star ** does the same, only using a dictionary and thus named arguments, use dict as parameter
def func(**ages): 
    print(ages)  #**ages is dictionary
    print "the age of dad, mom, lisa are: %(dad)s, %(mom)s, %(lisa)s" % ages
dic={'dad':42,'mom':48,'lisa':7}; 
func(**dic)
func(dad=42,mom=48,lisa=7)

#The double star ** uses a dictionary --> named arguments
def func(particle, weight=0): print "the weight of %s is %s" %(particle, weight)
d={"particle": "neutrino", "weight": 0.001}
func(**d)

##parameters with default value
def func4(p1='tst1',p2='tst2'): print(p1+" "+p2)
func4()

###function with tuple and dictionary as parameters
#first, last only take one parameters respectively
#*numbers takes as many as possible until a '=' 
#**items takes all parameters start with a '='
def profile(first, last, *numbers, **items):
    print first, last
    print numbers
    print items
profile('bucky', 'roberts', 1,2,3,4,5, bacon=4, saus=64)

""")

pp("generator")
ebrun("""
#myview:
#1. creating a function with yield statement in it
#2. then the function would return a generator object
#3. generator object is a iterator object, support next() method
#
#myview:
#1. generator function is a function with yield statement inside
#2. generator function return generator object
#3. generator object is iterator

#Every generator is an iterator, but not vice versa. A generator is built by calling a function that has one or more yield 
def city_generator():
    yield("Konstanz")
    yield("Zurich")
    yield("Schaffhausen")
    yield("Stuttgart")

x=city_generator()
#import inspect; inspect.getmro(x)
print type(x), type(type(x))
print x
print x.next()
print x.next()
print x.next()
print x.next()

#'i for i in list if' syntax will return a generator
g=(x for x in os.listdir('/etc') if '.conf' in x)
print g
print g.next()
print g.next()
print g.next()
g2=[x for x in glob.glob('/etc/*.conf')]
print g2
""")

pp("glob")
ebrun("""
import glob
for sfile in glob.glob("/etc/r*.conf"):
    print sfile
""")

pp("hasattr")
ebrun("""
##The hasattr() function checks if an object has an attribute. The getattr() function returns the contents of an attribute if there are some.

##class attributes:
class Foo:
    def __init__(self):
        self.a = "bar"
        self.b = 4711
    def bar(): pass
foo=Foo()

#object
print object.__dict__
print dir(object)
for i in dir(object): print "class object has attribute", i,":", hasattr(object, i)
#Foo
print Foo.__dict__
print dir(Foo)
for i in dir(Foo): print "class Foo has attribute", i,":", hasattr(Foo, i)
#foo
print foo.__dict__
print dir(foo)
for i in dir(foo): print "instance foo has attribute", i,":", hasattr(foo, i)
for i in dir(foo): print "instance foo's  attribute", i,":", getattr(foo, i)

##function attributes:
def fun(): pass
print fun.__dict__
print dir(fun)
for i in dir(fun): print "function fun() has attribute", i,":", hasattr(fun, i)
#for i in dir(fun): print "function fun()'s attribute", i,":", getattr(fun, i)
""")

pp("dec and hex");
ebrun("""
#dec to hex
print hex(16)           #0x10
print "%X"     % 16     #10
print "%x"     % 16     #10
print "0x%x"   % 16     #0x10
print "0x%x"   % 1616   #0x650
print "0x%2x"  % 1616   #0x650
print "0x%17x" % 1616   #0x              650

print ord.__doc__
print chr.__doc__

print ord('a'), chr(ord('a'))  #97 a
print ord('1'), chr(ord('a'))  #49 a

s = "Hello world!"
print ":".join(            str(ord(x))for x in s)  #72:101:108:108:111:32:119:111:114:108:100:33
print ":".join(  '%d'  %       ord(x) for x in s)  #72:101:108:108:111:32:119:111:114:108:100:33
print ":".join(  '%x'  %       ord(x) for x in s)  #48:65:6c:6c:6f:20:77:6f:72:6c:64:21
print ":".join( '%0X'  %       ord(x)  for x in s) #48:65:6C:6C:6F:20:77:6F:72:6C:64:21
print ":".join("{:02x}".format(ord(x)) for x in s) #48:65:6c:6c:6f:20:77:6f:72:6c:64:21
print ":".join(            hex(ord(x)) for x in s) #0x48:0x65:0x6c:0x6c:0x6f:0x20:0x77:0x6f:0x72:0x6c:0x64:0x21

#a list of A-E
print map(lambda x: chr(x), xrange(ord('A'),ord('E')+1))     #['A', 'B', 'C', 'D', 'E']
print    [ chr(x) for x in xrange(ord('A'), ord('E')+1)]     #['A', 'B', 'C', 'D', 'E']
print    ( chr(x) for x in xrange(ord('a'), ord('z')+1))     #<generator object <genexpr> at 0x7f16f2c915f0>
""")

pp("id")
ebrun("""
##Return the identity of an object. This is an integer (or long integer) which is guaranteed to be unique and constant for this object during its lifetime.
##
##id() (or its equivalent) is used in the is operator.
##
import copy
foo = 1; bar = foo; print id(foo), id(bar)
list = [1,2,3]; print id(list)
print id(list[0]), id(list[1]), id(list[2])
for i in list: print id(i), 
print
#for imutable, copy.copy() don't really copy
list2 = copy.copy(list); print id(list2)
for i in list2: print id(i),
""")

pp("inspect.getcallargs()")
ebrun("""
import inspect
def f(a, b=1, *pos, **named):
    pass
print inspect.getcallargs(f,7)
print inspect.getcallargs(f,7,2)
print inspect.getcallargs(f,7,2,'a','b','c')
m={'d':'dd', 'e':'ee'}
print inspect.getcallargs(f,7,2,'a','b','c',**m)
""")

pp("inspect.getmembers()")
ebrun("""
##All functions of the module re:
print inspect.getmembers(re, inspect.isfunction)
#or:
print dir(re); print type(re)
""")

pp("inspect.getmro()")
ebrun("""
##inspect.getmro(cls)
##mro --> method resolution order
##Return a tuple of class cls's base classes, including cls, in method resolution order. No class appears more than once in this tuple. Note that the method resolution order depends on cls type. Unless a very peculiar user-defined metatype is in use, cls will be the first element of the tuple.
import inspect
print inspect.getmro.__class__
print inspect.getmro.__doc__

class A(object): pass
class B(A): pass
print inspect.getmro(B)
print B.__base__
print B.__base__.__base__
print B.__base__.__base__.__base__
""")

pp("isinstance()")
ebrun("""
##isinstance(object, classinfo)
##  check if the object argument is an instance of the classinfo argument
##  classinfo need to be a class object nor a type object
print isinstance ("hello", str)
print isinstance ("hello", object)
print isinstance (123.0, float )
print isinstance (False, bool )
print isinstance (0, bool )
print isinstance(u'foo', (str))
print isinstance(u'foo', (str,basestring))
print isinstance(u'foo', (str,unicode))
print isinstance([], list)
print isinstance((), tuple)
""")

pp("issubclass()")
ebrun("""
class MyObject():
   def __init__(self):
      pass
class Wall(MyObject):
   def __init__(self):
      pass
import inspect; print inspect.getmro(Wall)
print issubclass(MyObject, MyObject)
print issubclass(MyObject, Wall)
print issubclass(Wall, MyObject)
print issubclass(Wall, Wall)

""")

pp("iterator")
ebrun("""
##what is iterable: 
#An iterable is an object that you can get an iterator from.
#list, str, xrange, dict, file are iterable
#An iterable is an object that has 
#1. __iter__()   #method which returns an iterator,  or
#2. __getitem__  #method 

##what is iterator:
#An iterator is an object with a next (Python 2) or __next__ (Python 3) method. 
#Iterator objects are required to support the following two methods
#1. __iter__()
#    Return the iterator object itself
#    allow both containers and iterators to be used with the for and in statements.
#2. next()   #I think it's generator instead of Iterator
#    Return the next item from the container. If there are no further items, raise the StopIteration exception. 

#Whenever you use a for loop, or map, or a list comprehension, etc. in Python, the next method is called automatically to get each item from the iterator, thus going through the process of iteration.

##iterable
#1. Iterable_instance.__iter__()  --> Iterrator_instance
#2. iter(Iterable_instance)       --> Iterrator_instance
#3. Iterable_instance.__getitem__()->  the item of the index
##iterator
#1. Iterator_instance.__iter__() --> get the iterator itself
#2. Iterator_instance.next()      --> get item for python 2
#3. Iterator_instance.__next__()  --> get item for python 3

#fname=os.path.dirname(os.path.abspath(__file__))+'/color.py'
fname=os.path.join(os.path.expanduser('~'), 'graduation/python/color.py')
x=[1,2,3];           print type(iter(x)), type(x.__iter__()), x.__getitem__(1)
x='123';             print type(iter(x)),                     x.__getitem__(1)
x=xrange(1,4);       print type(iter(x)), type(x.__iter__()), x.__getitem__(1)
x=range(1,4);        print type(iter(x)), type(x.__iter__()), x.__getitem__(1)
with open(fname) as x:print type(x), type(iter(x)), type(x.__iter__())

i=iter([1,2,3]);     print i.next(), i.next(), i.next()
i=iter('123');       print i.next(), i.next(), i.next()
i=iter(xrange(1,4)); print i.next(), i.next(), i.next()
i=iter(range(1,4));  print i.next(), i.next(), i.next()
i=open(fname);       print i.next(), i.next(), i.next()
ii=iter(i);          print ii.next(),ii.next(),ii.next(); i.close()

#use the 'globl' next() method
i=iter([1,2,3]);     print next(i), next(i), next(i)
i=open(fname);       print next(i), next(i), next(i); i.close()

#iterator type 1 --> str
print "__getitem__" in  dir(str)
for c in 'python': print c

#iterator type 2 --> list
for i in [1,2,3,4]: print i
for i in iter([1,2,3,4]): print i

#iterator type 3: dictionary
for k in {"feng":36, "yu":25, "zhong":27}: print k
for k in {"feng":36, "yu":25, "zhong":27}.keys(): print k
for k in {"feng":36, "yu":25, "zhong":27}.values(): print k
for k in {"feng":36, "yu":25, "zhong":27}.items(): print k
#iterator type 4: read file
with open("/etc/hosts") as f:
    print type(f) 
    for line in f: print line,
""")

pp("itertools.chain(),count(),repeat(),cycle()")
ebrun("""
import itertools
##1. itertools.chain(*iterables)
print [ i for i in itertools.chain('ABC', 'DEF','XYZ') ]

#user defined equivelent
#chain('ABC', 'DEF') --> A B C D E F

def chain(*iterables):
    for it in iterables:
        for element in it:
            yield element

##2. itertools.count(start=0, step=1: once for each integer, Infinite!
for num in itertools.count():
    if num < 10000: continue
    if num > 10007: break
    print num,

##3. chain, repeat, cycle
##   itertools.cycle(iterable)
##   itertools.repeat(object[, times])
seq = itertools.chain(itertools.repeat(17,3), itertools.cycle(range(7, 11, 1)))
print seq
for count, num in enumerate(seq):
    if count > 20: break
    print num,
""")

pp("join")
ebrun("""
print ":".join(["a", "b", "c"])
print list("python")
print "".join(list("python"))

map={"guo":36, "zhi":25, "shang":27}
print list(map)
print "--".join(map)
print "--".join(list(map))
""")

pp("json.load()")
ebrun("""
import json
from pprint import pprint

cmd='''cat > AAT.conf <<EOF
{
    "data"              : "/home/eenmliu/aat/data01",
    "backup"            : "/home/eenmliu/aat/backup",
    "log-dir"           : "/home/eenmliu/aat/logs"
}
EOF
'''
os.system(cmd)
with open('AAT.conf') as f:
    print f.read()
    f.seek(0)
    data = json.load(f)
print type(data)
print data[u'log-dir']
print data['log-dir']
pprint(data)
""")

pp("Lambda")
ebrun("""
###Lambda expressions are a shorthand to create anonymous functions; yields a function object. 
## lambda
#  lambda arguments: expression 
## function
#  def name(arguments): return expression
import os
os.system('pydoc lambda|cat')

##equal to 'def sum(x,y): return x + y'
sum = lambda x,y: x + y
print sum(1,2)

def sum(x,y): return x + y
print sum(1,2)


##How to make a lambda, that takes a object as input, return the object's atribute "name"'s value
##aka:  lambda_fun(object) ---> return object.getname()
class A(object):
    name="hello"
#self is just the name of parameter, which is a object, which must have attribute 'name'
aaa = lambda self: self.__dict__['name'] 
print aaa(A)

#or
def makeGetter(attrName):
    return lambda self: self.__dict__[attrName]
aaa = makeGetter('name')
print aaa(A)

""")

pp("list")
ebrun("""
x = [ 1, 2 ,3 ]; print id(x), x  #140714377773496 [1, 2, 3]
x.append(4);     print id(x), x  #140714377773496 [1, 2, 3, 4]
x.append([4,5]); print id(x), x  #140714377773496 [1, 2, 3, 4, [4, 5]]
x.extend([4,5]); print id(x), x  #140714377773496 [1, 2, 3, 4, [4, 5], 4, 5]
x = x + [4, 5 ]; print id(x), x  #140714377754240 [1, 2, 3, 4, [4, 5], 4, 5, 4, 5]

list1=['1', '2', '3']; 
print      ''.join(list1)        #123
print list(''.join(list1))       #['1', '2', '3']

""")

pp("locals(), vars(), globals()")
ebrun("""
##globals() returns the dictionary of the module namespace
##          global variables can be accessed inside functions, but cann't be modified inside functions
##locals()  returns a dictionary of the current namespace
##vars()    returns either a dictionary of the current namespace (if called with no argument) or the dictionary of the argument.

map_l=locals(); print map_l
map_l=locals(); print type(map_l)
map_l=locals(); print map_l.get("name")
map_l=locals(); name=""; print map_l
print globals()["__name__"]
print vars()

ages={'dad':42,'mom':48,'me':7}
ages.clear()          # remove all entries in dict
print ages if 'ages' in locals() else "ages not defined"

ages={'dad':42,'mom':48,'me':7}
del ages              # delete all entries
print ages if 'ages' in locals() else "ages not defined"

age = "16"
name = "Evan"
print "hello %(name)s you are %(age)s years old" % locals()


a_string="this is a global variable"
def foo():
    a_string = "this is local variable"
    print '''-->locals() variabls '''
    print locals()
    print '''-->vars() variabls '''
    print vars()

foo()
print '''-->global variabls '''
print globals()

""")