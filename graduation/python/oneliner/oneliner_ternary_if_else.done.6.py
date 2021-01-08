#!/usr/bin/env eepython
name="Scarborough Fair"
print "the word 'rough' does "+ ('' if 'rough' in name else 'not') + "exist in string: "+name

def func(p1):
  print "It's "+("not " if p1 else "")+"empty! ",
  print "It's "+("" if not p1 else "not ")+"empty! "
func('')
func([])
func(None)
func(0.0)
func(False)
func(' ')
func(True)

a=8; i =  5 if a > 7 else 0;  print i
a=3; i = (5 if a > 7 else 0); print i
