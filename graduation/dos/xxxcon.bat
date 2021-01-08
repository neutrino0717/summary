@echo off
set PUTTY_DIR="C:\Program Files (x86)\PuTTY"
if not exist %PUTTY_DIR% ( set PUTTY_DIR="C:\Program Files\PuTTY" )
cd %PUTTY_DIR%
start putty -telnet -P 2029 10.81.250.71
start putty -telnet -P 2030 10.81.250.71
start putty -telnet -P 2031 10.81.250.71
start putty -telnet -P 2032 10.81.250.71





