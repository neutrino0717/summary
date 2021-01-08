#!/usr/bin/env eepython
GOOGLE_MODE='https'
GAE_FETCHHOST='neutrino0717.appspot.com'
GAE_PATH='fetch.py'
tuple1=(GOOGLE_MODE, GAE_FETCHHOST, GAE_PATH)
#tuple can be without ()
tuple2=GOOGLE_MODE, GAE_FETCHHOST, GAE_PATH
list1=[GOOGLE_MODE, GAE_FETCHHOST, GAE_PATH]
GAE_FETCHSERVER='%s://%s%s?' % tuple1        ;print GAE_FETCHSERVER
GAE_FETCHSERVER='%s://%s%s?' % tuple2        ;print GAE_FETCHSERVER
GAE_FETCHSERVER='%s://%s%s?' % tuple(list1)  ;print GAE_FETCHSERVER
