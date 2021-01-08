#!/usr/bin/env python
import re
import time
import os
import sys
from random import randint
import threading
import inspect
import glob
from os.path import expanduser
#import stack
#import binaryTree
import urllib

HEADER = '\033[95m'
BLUE = '\033[94m'
GREEN = '\033[92m'
YELLOW = '\033[93m'
RED = '\033[91m'
ENDC = '\033[0m'


class colors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    ENDC = '\033[0m'
global sfile
global ll
global ll_len
sfile = None
ll = None

def traceit(frame, event, arg):
    global ll
    global ll_len
    if sfile and (ll == None):#  and not sfile_content:    
        with open(sfile) as f:
            ll = f.readlines()	    
            ll_len = len(ll)
            for linep in enumerate(ll,1): print linep
	#if event == "line":
    lineno = frame.f_lineno 
    #print sfile, lineno, 
    if lineno < ll_len: eprtline(str(lineno)+": "+ll[lineno-1].strip())
    return traceit

#print colors.GREEN + "OK, it's green" + colors.ENDC
#print colors.YELLOW + "it's WARNING color" + colors.END
def eprt(p1):
    print colors.RED + p1 + colors.ENDC

def eprtdoc(p1):
    for line in  p1.split('\n'):
        #if line[0:1] == "#":
        if re.match('^\s*(##|print)', line):
            print colors.BLUE + line + colors.ENDC
        elif re.match('^\s*#', line):
            print colors.YELLOW + line + colors.ENDC
        else:
            print colors.RED + line + colors.ENDC

def eprtline(line):
    #if line[0:2] == "##":
    if re.match('^\s*(##|print)', line):
	print colors.YELLOW + line + colors.ENDC
    elif re.match('^\s*#', line):
	print colors.BLUE + line + colors.ENDC
    else:
        print colors.GREEN + line + colors.ENDC

def erun(p1):
    #p1=p1.rstrip()
    p1=p1.strip()
    print colors.GREEN+ p1 + colors.ENDC
    exec p1 
    print

def elrun(p1):
    p1=p1.strip()
    for linep in p1.split('\n'):
        print (colors.YELLOW if linep[0:1]=='#' else colors.GREEN) + linep + colors.ENDC
        #print colors.GREEN+ linep + colors.ENDC
        exec linep
    print


def esrun(p1):
    p1=p1.strip()
    for b_now in re.split(r'\n\n', p1):
        eprtline(b_now)
        exec b_now


def ebrun(p1):
    p1=p1.strip()
    #b=''
    start=True
    b_now = None
    b_next = None
    lcomment = False
    inblock = False
    execute = False
    for linep in re.split(r'\n', p1):
        if lcomment:                                       #---->inside the long comment
            if re.match(r'''['"]{3}''', linep):            #end of the long comment
                b_now =b_now +'\n'+linep 
                execute = True
		b_next = None
		lcomment = False    
                #print b
            else:
                b_now = (not b_now == None) and b_now + '\n' + linep or linep
                b_next = None
        else:
            if inblock:
                if re.match(r'\s', linep):
                    b_now = (not b_now == None) and b_now + '\n' + linep or linep
                    b_next = None
                else:                   #end of a block 
                    execute = True
                    b_next = None
                    inblock = False

            if not inblock:
  	        if re.match(r'''[a-zA-Z0-9]*=['"]{3}''', linep): #match abc='''
                    lcomment = True
	            execute = True
	            b_next = linep
                elif re.match(r'^\s*$', linep):   #match a empty line 
                    execute = True
                    b_next = linep
	        elif re.match(r'\s', linep):      #---->inside a block
	            b_now = (not b_now == None) and b_now + '\n' + linep or linep
	            execute = False
	            inblock = True
                    b_next = None
	        else:                             #match a line start with command not space not space
                    execute = True
	            b_next = linep

	if execute:
	    if not b_now == None:
                eprtline(b_now)
                exec b_now
            b_now = b_next
	    b_next = None
	    execute = False
    if not b_now == None:
        eprtline(b_now)
        exec b_now

    if not b_next == None: 
	b_now = b_next;
	#print (colors.YELLOW if b_now[0:1]=='#' else colors.GREEN) + b_now + colors.ENDC
        eprtline(b_now)
        exec b_now

    print

'''
class Foo:
    def __init__(self):
        self.a = "bar"
        self.b = 4711
global a
a=Foo();
print type(Foo), dir(Foo)
print type(a),   dir(a)
print type(1),   dir(1)
print type(int), dir(int)
'''



"""
elrun('''
a='abc'; print a
b_now='abc';
print b_now
''')
"""
