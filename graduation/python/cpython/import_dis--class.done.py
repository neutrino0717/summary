#!/usr/bin/env eepython
import dis
class Parrot:
    name = "Mars bird"
    def __init__(self):
        self.kind = "Norwegian Blue"
        self.fowner, self.lowner = 'Evan','Liu'
    def is_dead(self):
        return False
    def sing(self, v):
        return self.name +" says: " + v
dis.dis(Parrot)
print Parrot().sing("hello")
dis.dis("long long")
