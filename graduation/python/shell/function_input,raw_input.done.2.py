#!/usr/bin/env eepython
###                 return string     return as expression
##python 2          raw_input()       input()
##python 3          input()           eval(input())
##
##In Python 2, raw_input() returns a string
##In Python 2, input() tries to run the input as expression
##In Python 3, input() returns a string
##In Python 3, eval(input()) is similar to Python 2 input()
x=raw_input("Your name: ")
print "Hello, " + x
