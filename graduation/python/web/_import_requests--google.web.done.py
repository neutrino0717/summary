#!/usr/bin/env eepython
##urllib2 is old way and totally broken
import sys
import requests
from bs4 import BeautifulSoup
url_login = "https://accounts.google.com/ServiceLogin"
url_auth  = "https://accounts.google.com/ServiceLoginAuth"
url_plus  = "https://plus.google.com"
s = requests.Session()
print(s.__class__)
print(s.__doc__)
page_login = s.get(url_login)
#print page_login.content
print type(page_login)
print type(page_login.content)
print type(page_login.text)
print requests.models.Response.__doc__
print requests.models.Response.text.__doc__
print requests.models.Response.content.__doc__
print page_login.encoding
print page_login.status_code
print page_login.headers
#soup = BeautifulSoup.BeautifulSoup(page_login.content).find('form').find_all('input')
soup = BeautifulSoup(page_login.content)
soup_form = soup.find('form'); print type(soup_form); print soup_form
soup_form_input = soup_form.find_all('input'); print type(soup_form_input)
for i in soup_form_input: print i
for i in soup_form_input: print type(i)
import inspect
for i in soup_form_input: print inspect.getmro(type(i))
#copy all the attributes from page form to dicot
dicot = {}
for i in soup_form_input:
    if i.has_attr('value'):
        dicot[i['name']] = i['value']
#sample:
#{'gxf': 'AFoagUV5siypPqD6ZTJsqzooe0wUdtcrpg:1464250470498', 'ProfileInformation': '', 'GALX': 'wSoL2Um6Ze0', 'Email': '', 'signIn': 'Next', 'bgresponse': 'js_disabled', '_utf8': u'\u2603', 'Page': 'PasswordSeparationSignIn'}
from pprint import pprint
pprint(dicot)
import getpass
passwd = getpass.getpass()
#override the inputs for email and password
dicot['Email'] = 'liuenmao@gmail.com'
dicot['Passwd'] = passwd
pprint(dicot)
print s.post(url_auth, data=dicot)
page_plus = s.get(url_plus)
print type(page_plus.text)
print type(page_plus.content)
import re
#output: [u'neutrino', u'neutrino', u'neutrino']
print re.findall('neutrino', page_plus.text)
print re.findall('neutrino', page_plus.content)
print sys.argv
print os.getcwd()
dname=os.path.abspath(os.path.dirname(sys.argv[1]))
print dname
with open(os.path.join(dname, sys.argv[1]+'_text.txt.log'),'w') as f:
    f.write(page_plus.text.encode("UTF-8"))
with open(os.path.join(dname, sys.argv[1]+'_content.txt.log'),'w') as f:
    f.write(page_plus.content)
