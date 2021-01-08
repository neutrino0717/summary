#As user root
##chroot
#chroot [OPTION] NEWROOT [COMMAND [ARG]...]
##env - run a program in a modified environment
#env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]
#env  -i, --ignore-environment
#After that, only the HOME, TERM, PS1, and PATH variables are set again.
##bash [options] [command_string | file]
#bash --login, Make bash act as if it had been invoked as a login shell
#bash +h, hashing is switched off by passing the +h option to bash. 
#he bash prompt will say I have no name! This is normal because the /etc/passwd file has not been created yet
#the following chapters are run from within the chroot environment. 
#If you leave this environment for any reason 
#ensure that the virtual kernel filesystems are mounted, 
#and enter chroot again before continuing with the installation. 

echo /{bin,boot,etc/{opt,sysconfig},home,lib/firmware,mnt,opt}
mkdir -pv /{bin,boot,etc/{opt,sysconfig},home,lib/firmware,mnt,opt}
mkdir -pv /{media/{floppy,cdrom},sbin,srv,var}
#Directories are, by default, created with permission mode 755
#The second mode change makes sure that any user can write to the /tmp and /var/tmp directories, but cannot remove another user's files from them.
# The latter is prohibited by the so-called sticky bit, the highest bit (1) in the 1777 bit mask. 
install -dv -m 0750 /root
#-->install: creating directory '/root'
install -dv -m 1777 /tmp /var/tmp
#-->install: creating directory '/tmp'
#-->install: creating directory '/var/tmp'
mkdir -pv /usr/{,local/}{bin,include,lib,sbin,src}
#mkdir: created directory '/usr'
#mkdir: created directory '/usr/bin'
#mkdir: created directory '/usr/include'
#mkdir: created directory '/usr/lib'
#mkdir: created directory '/usr/sbin'
#mkdir: created directory '/usr/src'
#mkdir: created directory '/usr/local'
#mkdir: created directory '/usr/local/bin'
#mkdir: created directory '/usr/local/include'
#mkdir: created directory '/usr/local/lib'
#mkdir: created directory '/usr/local/sbin'
#mkdir: created directory '/usr/local/src'
mkdir -pv /usr/{,local/}share/{color,dict,doc,info,locale,man}
mkdir -v  /usr/{,local/}share/{misc,terminfo,zoneinfo}
mkdir -v  /usr/libexec
mkdir -pv /usr/{,local/}share/man/man{1..8}

case $(uname -m) in
 x86_64) ln -sv lib /lib64
         ln -sv lib /usr/lib64
         ln -sv lib /usr/local/lib64 ;;
esac

mkdir -v /var/{log,mail,spool}
ln -sv /run /var/run
ln -sv /run/lock /var/lock
mkdir -pv /var/{opt,cache,lib/{color,misc,locate},local}

#Creating Essential Files and Symlinks 
#create a number of symbolic links which will be replaced by real files throughout the course of this chapter after the software has been installed
ln -sv /tools/bin/{bash,cat,echo,pwd,stty} /bin
ln -sv /tools/bin/perl /usr/bin
ln -sv /tools/lib/libgcc_s.so{,.1} /usr/lib
ln -sv /tools/lib/libstdc++.so{,.6} /usr/lib
sed 's/tools/usr/' /tools/lib/libstdc++.la > /usr/lib/libstdc++.la
ln -sv bash /bin/sh

ln -sv /proc/self/mounts /etc/mtab
#In order for user root to be able to login and for the name “root” to be recognized, there must be relevant entries in the /etc/passwd and /etc/group files. 
cat > /etc/passwd << "EOF"
root:x:0:0:root:/root:/bin/bash
bin:x:1:1:bin:/dev/null:/bin/false
daemon:x:6:6:Daemon User:/dev/null:/bin/false
messagebus:x:18:18:D-Bus Message Daemon User:/var/run/dbus:/bin/false
nobody:x:99:99:Unprivileged User:/dev/null:/bin/false
EOF
#The created groups are not part of any standard—they are groups decided on in part by the requirements of the Udev configuration 
cat > /etc/group << "EOF"
root:x:0:
bin:x:1:daemon
sys:x:2:
kmem:x:3:
tape:x:4:
tty:x:5:
daemon:x:6:
floppy:x:7:
disk:x:8:
lp:x:9:
dialout:x:10:
audio:x:11:
video:x:12:
utmp:x:13:
usb:x:14:
cdrom:x:15:
adm:x:16:
messagebus:x:18:
systemd-journal:x:23:
input:x:24:
mail:x:34:
nogroup:x:99:
users:x:999:
EOF

#The login, agetty, and init programs (and others) use a number of log files to record information such as who was logged into the system and when
touch /var/log/{btmp,lastlog,faillog,wtmp}
chgrp -v utmp /var/log/lastlog
chmod -v 664  /var/log/lastlog
chmod -v 600  /var/log/btmp

#/var/log/wtmp file records all logins and logouts. 
#/var/log/lastlog file records when each user last logged in. 
#/var/log/faillog file records failed login attempts. 
#/var/log/btmp file records the bad login attempts.
#/run/utmp file records the users that are currently logged in. This file is created dynamically in the boot scripts.

#then test 'I have no name' removed
exec /tools/bin/bash --login +h
