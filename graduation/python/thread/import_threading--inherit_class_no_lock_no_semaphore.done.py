#!/usr/bin/env eepython
import time
import threading
from random import randint
class AsyncPrint(threading.Thread):
    def __init__(self, text):
        threading.Thread.__init__(self)
        self.text = text
    def run(self):
        for i in range(1,10):
            time.sleep(randint(0,2))
            print self.text,
        print "Finished Background", self.text

background1 = AsyncPrint("#")
background2 = AsyncPrint("$")
background3 = AsyncPrint("^")
background1.start()
background2.start()
background3.start()
for i in range(1,5):
    time.sleep(randint(0,2))
    print "-",
print "Finished Main"
