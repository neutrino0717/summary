@echo off
echo Delete Old Users
net user /delete student11
net user /delete student12
net user /delete student13
echo.
echo Remove User Directory
rmdir /S /Q C:\Users\student11
rmdir /S /Q "C:\Documents and Settings\student11"
rmdir /S /Q C:\Users\student12
rmdir /S /Q "C:\Documents and Settings\student12"
rmdir /S /Q C:\Users\student13
rmdir /S /Q "C:\Documents and Settings\student13"
echo.
echo Create New Users
net user /add student11 SH304mmeNRJ /expires:4/1/2014 /passwordchg:no
net user /add student12 SH304mmeNRJ /expires:4/1/2014 /passwordchg:no
net user /add student13 SH304mmeNRJ /expires:4/1/2014 /passwordchg:no
echo.
echo Add to Remote Desktop Users Group
net localgroup "Remote Desktop Users" /add student11
net localgroup "Remote Desktop Users" /add student12
net localgroup "Remote Desktop Users" /add student13
echo.
echo net accounts / maxpwage: unlimited
pause
