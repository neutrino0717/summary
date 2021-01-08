@echo off
set PUTTY_DIR="C:\Program Files (x86)\PuTTY"
if not exist %PUTTY_DIR% ( set PUTTY_DIR="C:\Program Files\PuTTY" )
cd %PUTTY_DIR%
start putty -l root -pw remote 10.81.250.1
