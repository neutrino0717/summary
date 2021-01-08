#!/usr/bin/env eepython
import threading
import time
class colors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    ENDC = '\033[0m'

global tLock
tLock = threading.Lock()
def timer(name, delay, repeat):
    c=colors.YELLOW
    if name=="Test2": c=colors.RED
    print c + 'timer: ' + name + " Started"+colors.ENDC
    tLock.acquire(); print(c + name + " has acquired lock to some codes")
    while repeat > 0:
        time.sleep(delay)
        print c + 'timer: ' + name +": " + str(time.ctime(time.time())) + colors.ENDC
        repeat -= 1
    tLock.release(); print(c + name + " released lock to the codes")
    print c + "Timer: " + name + " Completed"+colors.ENDC

threading.Thread(target=timer, args=("Test1", 1, 5)).start()
threading.Thread(target=timer, args=("Test2", 2, 5)).start()
print "Main Complete"
