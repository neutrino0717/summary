@echo off
set PUTTY_DIR="C:\Program Files (x86)\PuTTY"
if not exist %PUTTY_DIR% ( set PUTTY_DIR="C:\Program Files\PuTTY" )
cd %PUTTY_DIR%
echo ##Test SGSN-MME login################
plink 10.175.12.65 -l root -pw wpp_admin "echo root login OK"
plink 10.175.12.65 -l coreUser -pw wpp_admin "echo coreUser login OK"
plink 10.175.12.65 -l sysadm -pw wpp_admin "echo sysadm login OK"
echo.
echo ##Test GSS login#####################
plink 10.175.11.73 -l coreUser -pw letmein "echo coreUser login OK"
echo.
echo ##Test SGSN-MME Configuration########
echo ------booked configuration-----------
echo Hardware MKVIII
echo Deplay L
echo Software 2013A CP00
echo ------current configuration-=--------
plink 10.175.12.65 -l sysadm -pw wpp_admin "gsh get_ne | grep -i hw
plink 10.175.12.65 -l sysadm -pw wpp_admin "gsh get_ne | grep -i ^type
plink 10.175.12.65 -l sysadm -pw wpp_admin "gsh get_ne | grep -A 1 ^swl\ 
echo.
pause
