#!/usr/bin/env eepython
##urllib2 is old way and totally broken
from pprint import pprint
import requests
print requests.__file__
c = requests.Session()
#p = c.get('http://bing.com')
p = c.get('https://bing.com')
print p.content[0:100]
print p.status_code
pprint(dict(p.headers.items()))
print type(p.headers)
print p.headers['Content-Type']
