#!/usr/bin/env eepython
###1. to run command-line via a shell program. use shell=True
## use subprocess.check_output if output is needed
## use subprocess.call if only return code is needed
#  subprocess.check_output(str, shell=True) 
#  subprocess.call(str, shell=True) 

###2. to run command-list via python, use shell=false
## the first item in the list is the executable and rest are its command line arguments 
## Note: subprocess.check_output(['ls', '|', 'wc', '-l']) will not work
#  subprocess.check_output(*list)
#  subprocess.call(*list)

###3. for more advanced usage, use class subprocess.Popen
#subprocess.Popen()

###4. use old way os.system or os.popen

###1. shell=true
import subprocess
content=subprocess.check_output('ls -al |tail -n 3', shell=True); print content

###2. shell=false
content=subprocess.check_output(['ls', '-al',]); print content
result =subprocess.call        (['ls', '-al',]); print result
##it will fail because of the '|'
#content=subprocess.check_output('ls -al |tail -n 3'); print content
##it will fail because of the '-al'
#content=subprocess.check_output('ls -al') ; print content
result=subprocess.call        ('ls -al |tail -n 3', shell=True); print result
###3. subprocess.Popen is a class
result=subprocess.Popen('ls -al|tail -n 3', shell=True, stdout=subprocess.PIPE); print result.stdout.read().strip()

###4. os
##os.system(), return 0, output cannot be put into variable
##os.popen().read(), output get into the variable
result=os.system('ls -al |tail -n 3');       print result
content=os.popen('ls -al |tail -n 3').read(); print content

