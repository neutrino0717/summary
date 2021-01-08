#!/usr/bin/env eepython
import os, sys

def _addMethod(fldName, verb, methodMaker, dict):
    """Make a get or set method and add it to dict."""
    methodName = _getMethodName(fldName, verb)
    dict[methodName] = methodMaker(fldName)


def _getMethodName(fldName, verb):
    """'_salary', 'get'  => 'getSalary'"""
    s = fldName.lstrip('_') # Remove leading underscores
    return verb + s.capitalize()

def _makeGetter(compiledName):
    """Return a method that gets compiledName's value."""
    return lambda self: self.__dict__[compiledName]

def _makeSetter(compiledName):
    """Return a method that sets compiledName's value."""
    return lambda self, value: setattr(self, compiledName, value)

class Accessors(type):
    """Adds accessor methods to a class."""
    def __new__(cls, clsName, bases, dict):
        print "--->the original dict:"; print dict
        for fldName in dict.get('_READ', []) + dict.get('_READ_WRITE', []):
            #works!
            #_addMethod(fldName, 'get', _makeGetter, dict)
            #not work, for by the time lambda called, the fldName has changed
            #dict['get'+fldName.capitalize()] =lambda self: self.__dict__[fldName]
            #works!, set the default value to fldName
            dict['get'+fldName.capitalize()] =lambda self, fldName=fldName: self.__dict__[fldName]
        #print dict
        for fldName in dict.get('_WRITE', []) + dict.get('_READ_WRITE', []):
            _addMethod(fldName, 'set', _makeSetter, dict)
            #not work, for by the time lambda called, the fldName has changed
            #dict['set'+fldName.capitalize()] = lambda self, value: setattr(self, fldName, value)
            #works
            dict['set'+fldName.capitalize()] = lambda self, value, fldName=fldName: setattr(self, fldName, value)
        print "-->the new dict:"; print dict
        return type.__new__(cls, clsName, bases, dict)

class Employee:
    __metaclass__ = Accessors
    _READ_WRITE = ['name', 'salary', 'title', 'bonus']
    _READ = ['sex']
    _WRITE = ['agent', 'level']
    def __init__(self, name, salary, title, bonus=0):
        self.name = name
        self.salary = salary
        self.title = title
        self.bonus = bonus
        self.sex = 'female'
b = Employee('Joe Test', 40000, 'Developer')
print 'Name:', b.getName()
print 'Salary:', b.getSalary()
print 'Title:', b.getTitle()
print 'Bonus:', b.getBonus()
print 'Sex:', b.getSex()
b.setBonus(5000)
print 'Bonus:', b.getBonus()
  
