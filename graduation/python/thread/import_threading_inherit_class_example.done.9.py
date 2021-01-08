#!/usr/bin/env eepython
import threading
import re, urllib
import time
class WebpageThread(threading.Thread):
    def __init__(self, site):
        super(WebpageThread,self).__init__()
        self.site=site
        self.total=0
    def run(self):
        t1=time.time()
        #print "--> accessing to %s ..." % self.site
        u=urllib.urlopen("http://"+ self.site)
        text = u.read()
        #print "--> done with %s " % self.site
        self.total = time.time() - t1
#sites = 'baidu.com|163.com|qq.com'.split('|')
sites = 'google.com|facebook.com|linuxfromscratch.org'.split('|')
threadlst = [];
t1=time.time()
for i in xrange(0,len(sites)):
    threadlst.append(WebpageThread(sites[i]))
for i in xrange(0,len(sites)):
    threadlst[i].start()
for i in xrange(0,len(sites)):
    threadlst[i].join()
total=0
for i in xrange(0,len(sites)):
    print "%-15s --> %-15s seconds" % (threadlst[i].site, threadlst[i].total)
    total += threadlst[i].total
actual = time.time() - t1
print "total time used: %d" % total
print "actual time used: %d" % actual
