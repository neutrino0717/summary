@echo off
set PUTTY_DIR="C:\Program Files (x86)\PuTTY"
if not exist %PUTTY_DIR% ( set PUTTY_DIR="C:\Program Files\PuTTY" )
cd %PUTTY_DIR%


rem gis
pscp -pw remote C:\tmp\RemoteSGSN01_2011ACP01_Configuration_Triple.TXT root@10.81.250.1:/gsn/coreUser


rem mme
rem pscp -pw wpp_admin sysadm@10.175.16.65:/Core/home/sysadm/* c:\temp\

rem spp
rem pscp -pw wpp_admin c:\temp\lservrc_0X19F5B_121016_104400.txt root@10.175.15.76:/etc/spp/license_files/
rem pscp -pw wpp_admin c:\temp\lservrc_0X1A059_121016_102500.txt root@10.175.15.77:/etc/spp/license_files/

rem pscp -pw wpp_admin root@10.175.15.76:/etc/spp/backup_config/spp-backup-spp1-2012-10-17-14-56-24.tar.gz c:\temp\ 
rem pscp -pw wpp_admin root@10.175.15.77:/etc/spp/backup_config/spp-backup-spp2-2012-10-17-15-2-49.tar.gz c:\temp\ 
pause

