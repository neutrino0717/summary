#!/bin/bash
#copy from ~neutrino0717/graduation/cmd/linuxfromscratch/ to /mnt/lfs/source
set -e
set -u
set -v
set -x
green='\e[0;32m'; blue='\e[0;34m'; red='\e[31m'; yellow='\e[0;33m'; endColor='\e[0m'
declare -A mtar
mtar=([bz2]=jxf [.gz]=zxf [.xz]=xf)
xcd(){
  pname=$1
  pdir=`echo ${pname}|sed -e 's/\.tar\..*$//'`
  grep -q "tcl" <<<"$pdir" && pdir=tcl8.6.6
  ext=${pname: -3}
  arg=${mtar[$ext]}
  cd /sources/${pdir}
  logfilecur="/log/`date -u +%y%m%d%H%M%S`${pname}.log"
  log_configure="/log/make/`date -u +%y%m%d%H%M%S`${pname}_configure.log"
  log_make="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make.log"
  log_make_check="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make_check.log"
  log_make_install="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make_install.log"
}
xtar(){
  pname=$1
  pdir=`echo ${pname}|sed -e 's/\.tar\..*$//'`
  grep -q "tcl" <<<"$pdir" && pdir=tcl8.6.6
  grep -q "attr-" <<<"$pdir" && pdir=attr-2.4.47
  grep -q "acl-" <<<"$pdir" && pdir=acl-2.2.52
  grep -q "vim-" <<<"$pdir" && pdir=vim74
  ext=${pname: -3}
  arg=${mtar[$ext]}
  echo -e "${red}=======$pname starting=======${endColor}" |tee -a /log/5.log
  cd /sources/ && rm -rf ${pdir} && tar ${arg} ${pname} && cd ${pdir}
  if [ "$?" != 0 ]; then
    echo "ERROR with xtar $pname"
    exit 1
  fi
  logfilecur="/log/`date -u +%y%m%d%H%M%S`${pname}.log"
  log_configure="/log/make/`date -u +%y%m%d%H%M%S`${pname}_configure.log"
  log_make="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make.log"
  log_make_check="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make_check.log"
  log_make_install="/log/make/`date -u +%y%m%d%H%M%S`${pname}_make_install.log"
}
savelog(){
  #{ find /bin /opt /sbin /usr /boot /etc /lib /var -type f | while read l; do md5sum $l|awk '{print $2" "$1}'; done; } > $logfilecur
  set +x
  find /bin /opt /sbin /usr /boot /etc /lib /var -type f | while read l; do md5sum $l|awk '{print $2" "$1}'; done > $logfilecur
  set -x
  #find / -type d \( -path /sources -o -path /lib64 \) -prune -o -type f | while read l; do md5sum $l|awk '{print $2" "$1}'; done > $logfilecur
  rm -rf /sources/$pdir
  echo -e "${green}=======$pname done=======${endColor}" |tee -a /log/5.log
}
#echo ${LOG_DIR}/log/`TZ='Asia/Shanghai' date +%y%m%d%H%M%S`${pname}.log
#exit 0
if [ "$(id -u -n)" != "root" ]; then echo "please run as chroot!"; exit 1; fi
<<"EOD"
#==================================================================#
#==================================================================#
xtar linux-4.7.2.tar.xz
make mrproper
make INSTALL_HDR_PATH=dest headers_install
find dest/include \( -name .install -o -name ..install.cmd \) -delete
find dest/include \( -name .install -o -name ..install.cmd \) 
cp -rv dest/include/* /usr/include
savelog

#==================================================================#
#==================================================================#
xtar man-pages-4.07.tar.xz
make install
savelog

#==================================================================#
#==================================================================#
xtar glibc-2.24.tar.xz
patch -Np1 -i ../glibc-2.24-fhs-1.patch
mkdir -v build && cd build
../configure --prefix=/usr          \
             --enable-kernel=2.6.32 \
             --enable-obsolete-rpc
make 
make check || echo "with maybe three errors" #3 fails
touch /etc/ld.so.conf
make install
#install the configuration file and runtime directory for nscd: 
cp -v ../nscd/nscd.conf /etc/nscd.conf
mkdir -pv /var/cache/nscd
#install the locales that can make the system respond in a different language
mkdir -pv /usr/lib/locale
localedef -i cs_CZ -f UTF-8 cs_CZ.UTF-8
localedef -i de_DE -f ISO-8859-1 de_DE
localedef -i de_DE@euro -f ISO-8859-15 de_DE@euro
localedef -i de_DE -f UTF-8 de_DE.UTF-8
localedef -i en_GB -f UTF-8 en_GB.UTF-8
localedef -i en_HK -f ISO-8859-1 en_HK
localedef -i en_PH -f ISO-8859-1 en_PH
localedef -i en_US -f ISO-8859-1 en_US
localedef -i en_US -f UTF-8 en_US.UTF-8
localedef -i es_MX -f ISO-8859-1 es_MX
localedef -i fa_IR -f UTF-8 fa_IR
localedef -i fr_FR -f ISO-8859-1 fr_FR
localedef -i fr_FR@euro -f ISO-8859-15 fr_FR@euro
localedef -i fr_FR -f UTF-8 fr_FR.UTF-8
localedef -i it_IT -f ISO-8859-1 it_IT
localedef -i it_IT -f UTF-8 it_IT.UTF-8
localedef -i ja_JP -f EUC-JP ja_JP
localedef -i ru_RU -f KOI8-R ru_RU.KOI8-R
localedef -i ru_RU -f UTF-8 ru_RU.UTF-8
localedef -i tr_TR -f UTF-8 tr_TR.UTF-8
localedef -i zh_CN -f GB18030 zh_CN.GB18030
#Alternatively, install all locales listed in the glibc-2.24/localedata/SUPPORTED file (it includes every locale listed above and many more) at once with the following time-consuming command: 
#make localedata/install-locales

#manully below
# The /etc/nsswitch.conf file needs to be created because the Glibc defaults do not work well in a networked environment. 
cat > /etc/nsswitch.conf << "EOF"
# Begin /etc/nsswitch.conf

passwd: files
group: files
shadow: files

hosts: files dns
networks: files

protocols: files
services: files
ethers: files
rpc: files
# End /etc/nsswitch.conf
EOF

# Adding time zone data 
tar -xf ../../tzdata2016f.tar.gz
ZONEINFO=/usr/share/zoneinfo
mkdir -pv $ZONEINFO/{posix,right}
for tz in etcetera southamerica northamerica europe africa antarctica  \
          asia australasia backward pacificnew systemv; do
    zic -L /dev/null   -d $ZONEINFO       -y "sh yearistype.sh" ${tz}
    zic -L /dev/null   -d $ZONEINFO/posix -y "sh yearistype.sh" ${tz}
    zic -L leapseconds -d $ZONEINFO/right -y "sh yearistype.sh" ${tz}
done
cp -v zone.tab zone1970.tab iso3166.tab $ZONEINFO
zic -d $ZONEINFO -p America/New_York
unset ZONEINFO
#tzselect
cp -v /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
#--> '/usr/share/zoneinfo/Asia/Shanghai' -> '/etc/localtime'

#Configuring the Dynamic Loader 
#By default, the dynamic loader (/lib/ld-linux.so.2) searches through /lib and /usr/lib for dynamic libraries that are needed by programs as they are run.
#add those directories to the dynamic loader's search path. 
cat > /etc/ld.so.conf << "EOF"
# Begin /etc/ld.so.conf
/usr/local/lib
/opt/lib

EOF

cat >> /etc/ld.so.conf << "EOF"
# Add an include directory
include /etc/ld.so.conf.d/*.conf

EOF
mkdir -pv /etc/ld.so.conf.d
savelog


#==================================================================#
#==================================================================#
#6.10. Adjusting the Toolchain 
# Now that the final C libraries have been installed, it is time to adjust the toolchain so that it will link any newly compiled program against these new libraries. 
#First, backup the /tools linker, and replace it with the adjusted linker we made in chapter 5. We'll also create a link to its counterpart in /tools/$(uname -m)-pc-linux-gnu/bin: 
mv -v /tools/bin/{ld,ld-old}
#'/tools/bin/ld' -> '/tools/bin/ld-old'
mv -v /tools/$(uname -m)-pc-linux-gnu/bin/{ld,ld-old}
#'/tools/x86_64-pc-linux-gnu/bin/ld' -> '/tools/x86_64-pc-linux-gnu/bin/ld-old'
mv -v /tools/bin/{ld-new,ld}
#'/tools/bin/ld-new' -> '/tools/bin/ld'
ln -sv /tools/bin/ld /tools/$(uname -m)-pc-linux-gnu/bin/ld
#'/tools/x86_64-pc-linux-gnu/bin/ld' -> '/tools/bin/ld'
#manually
gcc -dumpspecs | sed -e 's@/tools@@g'                   \
    -e '/\*startfile_prefix_spec:/{n;s@.*@/usr/lib/ @}' \
    -e '/\*cpp:/{n;s@$@ -isystem /usr/include@}' >      \
    `dirname $(gcc --print-libgcc-file-name)`/specs
echo 'int main(){}' > dummy.c
cc dummy.c -v -Wl,--verbose &> dummy.log
readelf -l a.out | grep ': /lib'
grep -o '/usr/lib.*/crt[1in].*succeeded' dummy.log
grep -B1 '^ /usr/include' dummy.log
grep 'SEARCH.*/usr/lib' dummy.log |sed 's|; |\n|g'
grep "/lib.*/libc.so.6 " dummy.log
grep found dummy.log
rm -v dummy.c a.out dummy.log
#done manually
echo "please review the output of the above"
exit 0
#==================================================================#
#==================================================================#
xtar zlib-1.2.8.tar.gz
./configure --prefix=/usr
make
make check
make install
mv -v /usr/lib/libz.so.* /lib
#'/usr/lib/libz.so.1' -> '/lib/libz.so.1'
#'/usr/lib/libz.so.1.2.8' -> '/lib/libz.so.1.2.8'
ln -sfv ../../lib/$(readlink /usr/lib/libz.so) /usr/lib/libz.so
#'/usr/lib/libz.so' -> '../../lib/libz.so.1.2.8'
savelog

#==================================================================#
#==================================================================#
xtar file-5.28.tar.gz
./configure --prefix=/usr
make
make check
make install
savelog

#==================================================================#
#==================================================================#

xtar binutils-2.27.tar.bz2
expect -c "spawn ls" | grep 'spawn ls'
mkdir -v build && cd build
../configure --prefix=/usr   \
             --enable-shared \
             --disable-werror
make tooldir=/usr
make -k check         #two errors why?? one error why?
#FAIL: PLT PC-relative offset overflow check
make tooldir=/usr install
savelog

#==================================================================#
#==================================================================#
xtar gmp-6.1.1.tar.xz
#Installation of GMP 
./configure --prefix=/usr    \
            --enable-cxx     \
            --disable-static \
            --docdir=/usr/share/doc/gmp-6.1.2
make
make html
make check 2>&1 | tee gmp-check-log
#Ensure that all 190 tests in the test suite passed.
awk '/# PASS:/{total+=$3} ; END{print total}' gmp-check-log | grep 190
make install
make install-html
savelog

#==================================================================#
#==================================================================#
xtar mpfr-3.1.4.tar.xz
# The MPFR package contains functions for multiple precision math. 
# Installed Libraries: libmpfr.so
# Installed directory: /usr/share/doc/mpfr-3.1.4
./configure --prefix=/usr        \
            --disable-static     \
            --enable-thread-safe \
            --docdir=/usr/share/doc/mpfr-3.1.4
make
make html
make check
make install
make install-html
savelog

#==================================================================#
#==================================================================#
xtar mpc-1.0.3.tar.gz
# The MPC package contains a library for the arithmetic of complex numbers with arbitrarily high precision and correct rounding of the result. 
pname=mpc-1.0.3.tar.gz && pdir=`echo ${pname}|sed -e 's/\.tar\..*$//'` && cd /sources/ && rm -rf ${pdir} && tar zxf ${pname} && cd ${pdir}
./configure --prefix=/usr    \
            --disable-static \
            --docdir=/usr/share/doc/mpc-1.0.3
make
make html
make check
make install
make install-html
savelog

#==================================================================#
#==================================================================#
xtar gcc-6.2.0.tar.bz2
mkdir -v build && cd build
#Setting this environment variable prevents a hard-coded path to /tools/bin/sed.
SED=sed                               \
../configure --prefix=/usr            \
             --enable-languages=c,c++ \
             --disable-multilib       \
             --disable-bootstrap      \
             --with-system-zlib
make
ulimit -s 32768
make -k check || echo "Test the results, but do not stop at errors:"
xcd gcc-6.2.0.tar.bz2 && cd build
../contrib/test_summary
make install
# Create a symlink required by the FHS for "historical" reasons. 
ln -sv ../usr/bin/cpp /lib
# Many packages use the name cc to call the C compiler. To satisfy those packages, create a symlink: 
ln -sv gcc /usr/bin/cc
# Add a compatibility symlink to enable building programs with Link Time Optimization (LTO): 
install -v -dm755 /usr/lib/bfd-plugins
ln -sfv ../../libexec/gcc/$(gcc -dumpmachine)/6.2.0/liblto_plugin.so /usr/lib/bfd-plugins/
echo 'int main(){}' > dummy.c
cc dummy.c -v -Wl,--verbose &> dummy.log
readelf -l a.out | grep ': /lib'
grep -o '/usr/lib.*/crt[1in].*succeeded' dummy.log
grep -B4 '^ /usr/include' dummy.log
grep 'SEARCH.*/usr/lib' dummy.log |sed 's|; |\n|g'
grep "/lib.*/libc.so.6 " dummy.log
grep found dummy.log
rm -v dummy.c a.out dummy.log
mkdir -pv /usr/share/gdb/auto-load/usr/lib
mv -v /usr/lib/*gdb.py /usr/share/gdb/auto-load/usr/lib
savelog

#==================================================================#
#==================================================================#
xtar bzip2-1.0.6.tar.gz
patch -Np1 -i ../bzip2-1.0.6-install_docs-1.patch
sed -i 's@\(ln -s -f \)$(PREFIX)/bin/@\1@' Makefile
sed -i "s@(PREFIX)/man@(PREFIX)/share/man@g" Makefile
make -f Makefile-libbz2_so
make clean
make
make PREFIX=/usr install
cp -v bzip2-shared /bin/bzip2
cp -av libbz2.so* /lib
ln -sv ../../lib/libbz2.so.1.0 /usr/lib/libbz2.so
rm -v /usr/bin/{bunzip2,bzcat,bzip2}
ln -sv bzip2 /bin/bunzip2
ln -sv bzip2 /bin/bzcat
savelog

#==================================================================#
#==================================================================#
xtar pkg-config-0.29.1.tar.gz
./configure --prefix=/usr              \
            --with-internal-glib       \
            --disable-compile-warnings \
            --disable-host-tool        \
            --docdir=/usr/share/doc/pkg-config-0.29.1
make
make check
make install
savelog

#==================================================================#
#==================================================================#
xtar ncurses-6.0.tar.gz
sed -i '/LIBTOOL_INSTALL/d' c++/Makefile.in
./configure --prefix=/usr           \
            --mandir=/usr/share/man \
            --with-shared           \
            --without-debug         \
            --without-normal        \
            --enable-pc-files       \
            --enable-widec
make
make install
mv -v /usr/lib/libncursesw.so.6* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libncursesw.so) /usr/lib/libncursesw.so
for lib in ncurses form panel menu ; do
    rm -vf                    /usr/lib/lib${lib}.so
    echo "INPUT(-l${lib}w)" > /usr/lib/lib${lib}.so
    ln -sfv ${lib}w.pc        /usr/lib/pkgconfig/${lib}.pc
done

rm -vf                     /usr/lib/libcursesw.so
echo "INPUT(-lncursesw)" > /usr/lib/libcursesw.so
ln -sfv libncurses.so      /usr/lib/libcurses.so
mkdir -v       /usr/share/doc/ncurses-6.0
cp -v -R doc/* /usr/share/doc/ncurses-6.0
savelog

#==================================================================#
#==================================================================#
xtar attr-2.4.47.src.tar.gz
sed -i -e "/SUBDIRS/s|man[25]||g" man/Makefile
./configure --prefix=/usr \
            --bindir=/bin \
            --disable-static
make
make -j1 tests root-tests
make install install-dev install-lib
chmod -v 755 /usr/lib/libattr.so
mv -v /usr/lib/libattr.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libattr.so) /usr/lib/libattr.so
savelog

#==================================================================#
#==================================================================#
xtar acl-2.2.52.src.tar.gz
sed -i -e 's|/@pkg_name@|&-@pkg_version@|' include/builddefs.in
sed -i "s:| sed.*::g" test/{sbits-restore,cp,misc}.test
sed -i -e "/TABS-1;/a if (x > (TABS-1)) x = (TABS-1);" \
    libacl/__acl_to_any_text.c
./configure --prefix=/usr    \
            --bindir=/bin    \
            --disable-static \
            --libexecdir=/usr/lib
make
make install install-dev install-lib
chmod -v 755 /usr/lib/libacl.so
mv -v /usr/lib/libacl.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libacl.so) /usr/lib/libacl.so
savelog

#==================================================================#
#==================================================================#
xtar libcap-2.25.tar.xz
sed -i '/install.*STALIBNAME/d' libcap/Makefile
make
make RAISE_SETFCAP=no prefix=/usr install
chmod -v 755 /usr/lib/libcap.so
mv -v /usr/lib/libcap.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libcap.so) /usr/lib/libcap.so
savelog

#==================================================================#
#==================================================================#
xtar sed-4.2.2.tar.bz2
./configure --prefix=/usr --bindir=/bin --htmldir=/usr/share/doc/sed-4.2.2
make
make html
make check
make install
make -C doc install-html
savelog

#==================================================================#
#==================================================================#
xtar shadow-4.2.1.tar.xz
sed -i 's/groups$(EXEEXT) //' src/Makefile.in
find man -name Makefile.in -exec sed -i 's/groups\.1 / /'   {} \;
find man -name Makefile.in -exec sed -i 's/getspnam\.3 / /' {} \;
find man -name Makefile.in -exec sed -i 's/passwd\.5 / /'   {} \;
sed -i -e 's@#ENCRYPT_METHOD DES@ENCRYPT_METHOD SHA512@' \
       -e 's@/var/spool/mail@/var/mail@' etc/login.defs
sed -i 's/1000/999/' etc/useradd
./configure --sysconfdir=/etc --with-group-name-max-length=32
make
make install
mv -v /usr/bin/passwd /bin

pwconv
grpconv
sed -i 's/yes/no/' /etc/default/useradd
passwd root
savelog

#==================================================================#
#==================================================================#
xtar psmisc-22.21.tar.gz
./configure --prefix=/usr
make
make install
mv -v /usr/bin/fuser   /bin
mv -v /usr/bin/killall /bin
savelog

#==================================================================#
#==================================================================#
xtar iana-etc-2.30.tar.bz2
make 
make install
savelog

#==================================================================#
#==================================================================#
xtar m4-1.4.17.tar.xz
./configure --prefix=/usr
make
make check || echo "go on with errors!"
make install
savelog

#==================================================================#
#==================================================================#
xtar bison-3.0.4.tar.xz
./configure --prefix=/usr --docdir=/usr/share/doc/bison-3.0.4
make
make install
savelog

#==================================================================#
#==================================================================#
xtar flex-2.6.1.tar.xz
./configure --prefix=/usr --docdir=/usr/share/doc/flex-2.6.1
make
make check
make install
ln -sv flex /usr/bin/lex
savelog

#==================================================================#
#==================================================================#
xtar grep-2.25.tar.xz
./configure --prefix=/usr --bindir=/bin
make
make check
make install
savelog

#==================================================================#
#==================================================================#
xtar readline-6.3.tar.gz
patch -Np1 -i ../readline-6.3-upstream_fixes-3.patch
sed -i '/MV.*old/d' Makefile.in
sed -i '/{OLDSUFF}/c:' support/shlib-install
./configure --prefix=/usr    \
            --disable-static \
            --docdir=/usr/share/doc/readline-6.3
make SHLIB_LIBS=-lncurses
make SHLIB_LIBS=-lncurses install
mv -v /usr/lib/lib{readline,history}.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libreadline.so) /usr/lib/libreadline.so
ln -sfv ../../lib/$(readlink /usr/lib/libhistory.so ) /usr/lib/libhistory.so
savelog

#==================================================================#
#==================================================================#
xtar bash-4.3.30.tar.gz
patch -Np1 -i ../bash-4.3.30-upstream_fixes-3.patch
./configure --prefix=/usr                       \
            --docdir=/usr/share/doc/bash-4.3.30 \
            --without-bash-malloc               \
            --with-installed-readline
make
chown -Rv nobody .
su nobody -s /bin/bash -c "PATH=$PATH make tests"
make install
mv -vf /usr/bin/bash /bin
#if run below the script will end here
exec /bin/bash --login +h

xcd bash-4.3.30.tar.gz
savelog

#==================================================================#
#==================================================================#
xtar bc-1.06.95.tar.bz2
patch -Np1 -i ../bc-1.06.95-memory_leak-1.patch
./configure --prefix=/usr           \
            --with-readline         \
            --mandir=/usr/share/man \
            --infodir=/usr/share/info > $log_configure
make > $log_make
echo "quit" | ./bc/bc -l Test/checklib.b
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar libtool-2.4.6.tar.xz
./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check || echo "64-59 failed OK -->64 failed (59 expected failures)."
make install > $log_make_install 
savelog

#==================================================================#
#==================================================================#
xtar gdbm-1.12.tar.gz
./configure --prefix=/usr \
            --disable-static \
            --enable-libgdbm-compat > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar gperf-3.0.4.tar.gz
./configure --prefix=/usr --docdir=/usr/share/doc/gperf-3.0.4 > $log_configure
make > $log_make
make -j1 check > $log_make_check
make install > $log_make_install

savelog
#==================================================================#
#==================================================================#
xtar expat-2.2.0.tar.bz2
./configure --prefix=/usr --disable-static > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
# If desired, install the documentation: 
install -v -dm755 /usr/share/doc/expat-2.2.0
install -v -m644 doc/*.{html,png,css} /usr/share/doc/expat-2.2.0
savelog

#==================================================================#
#==================================================================#
xtar inetutils-1.9.4.tar.xz
./configure --prefix=/usr        \
            --localstatedir=/var \
            --disable-logger     \
            --disable-whois      \
            --disable-rcp        \
            --disable-rexec      \
            --disable-rlogin     \
            --disable-rsh        \
            --disable-servers > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
mv -v /usr/bin/{hostname,ping,ping6,traceroute} /bin
mv -v /usr/bin/ifconfig /sbin
savelog

#==================================================================#
#==================================================================#
xtar perl-5.24.0.tar.bz2
echo "127.0.0.1 localhost $(hostname)" > /etc/hosts
export BUILD_ZLIB=False
export BUILD_BZIP2=0
sh Configure -des -Dprefix=/usr                 \
                  -Dvendorprefix=/usr           \
                  -Dman1dir=/usr/share/man/man1 \
                  -Dman3dir=/usr/share/man/man3 \
                  -Dpager="/usr/bin/less -isR"  \
                  -Duseshrplib >$log_configure
make > $log_make
make -k test > $log_make_check
make install > $log_make_install
unset BUILD_ZLIB BUILD_BZIP2
savelog

#==================================================================#
#==================================================================#
xtar XML-Parser-2.44.tar.gz
perl Makefile.PL > $log_configure
make > $log_make
make test > $log_make_check
make install > $log_make_install

savelog

#==================================================================#
#==================================================================#
xtar intltool-0.51.0.tar.gz
sed -i 's:\\\${:\\\$\\{:' intltool-update.in
./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
install -v -Dm644 doc/I18N-HOWTO /usr/share/doc/intltool-0.51.0/I18N-HOWTO

savelog

#==================================================================#
#==================================================================#
xtar autoconf-2.69.tar.xz
./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check || echo "two tests fail due to changes in libtool-2.4.3 and later"
make install > $log_make_install

savelog

#==================================================================#
#==================================================================#
xtar automake-1.15.tar.xz
sed -i 's:/\\\${:/\\\$\\{:' bin/automake.in
./configure --prefix=/usr --docdir=/usr/share/doc/automake-1.15 > $log_configure
make > $log_make
sed -i "s:./configure:LEXLIB=/usr/lib/libfl.a &:" t/lex-{clean,depend}-cxx.sh
make -j4 check > $log_make_check || echo "fail: 3, not sure it's OK"
xcd automake-1.15.tar.xz
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar xz-5.2.2.tar.xz
sed -e '/mf\.buffer = NULL/a next->coder->mf.size = 0;' \
     -i src/liblzma/lz/lz_encoder.c
./configure --prefix=/usr    \
            --disable-static \
            --docdir=/usr/share/doc/xz-5.2.2 > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
mv -v   /usr/bin/{lzma,unlzma,lzcat,xz,unxz,xzcat} /bin
mv -v /usr/lib/liblzma.so.* /lib
ln -svf ../../lib/$(readlink /usr/lib/liblzma.so) /usr/lib/liblzma.so

savelog

#==================================================================#
#==================================================================#
xtar kmod-23.tar.xz
./configure --prefix=/usr          \
            --bindir=/bin          \
            --sysconfdir=/etc      \
            --with-rootlibdir=/lib \
            --with-xz              \
            --with-zliba > $log_configure
make > $log_make
make install > $log_make_install
for target in depmod insmod lsmod modinfo modprobe rmmod; do
  ln -sfv ../bin/kmod /sbin/$target
done
ln -sfv kmod /bin/lsmod

savelog

#==================================================================#
#==================================================================#
xtar gettext-0.19.8.1.tar.xz
./configure --prefix=/usr    \
            --disable-static \
            --docdir=/usr/share/doc/gettext-0.19.8.1 > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
chmod -v 0755 /usr/lib/preloadable_libintl.so
savelog

#==================================================================#
#==================================================================#
xtar procps-ng-3.3.12.tar.xz
./configure --prefix=/usr                            \
            --exec-prefix=                           \
            --libdir=/usr/lib                        \
            --docdir=/usr/share/doc/procps-ng-3.3.12 \
            --disable-static                         \
            --disable-kill > $log_configure
make > $log_make
sed -i -r 's|(pmap_initname)\\\$|\1|' testsuite/pmap.test/pmap.exp
make check > $log_make_check
make install > $log_make_install
mv -v /usr/lib/libprocps.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libprocps.so) /usr/lib/libprocps.so
savelog

#==================================================================#
#==================================================================#
xtar e2fsprogs-1.43.1.tar.gz
sed -i -e 's:\[\.-\]::' tests/filter.sed
mkdir -v build
cd build
LIBS=-L/tools/lib                    \
CFLAGS=-I/tools/include              \
PKG_CONFIG_PATH=/tools/lib/pkgconfig \
../configure --prefix=/usr           \
             --bindir=/bin           \
             --with-root-prefix=""   \
             --enable-elf-shlibs     \
             --disable-libblkid      \
             --disable-libuuid       \
             --disable-uuidd         \
             --disable-fsck > $log_configure
make > $log_make
ln -sfv /tools/lib/lib{blk,uu}id.so.1 lib
make LD_LIBRARY_PATH=/tools/lib check > $log_make_check || echo "3 tests failed, not sure it's OK"
xcd e2fsprogs-1.43.1.tar.gz && cd build
make install > $log_make_install
make install-libs >> $log_make_install
chmod -v u+w /usr/lib/{libcom_err,libe2p,libext2fs,libss}.a
gunzip -v /usr/share/info/libext2fs.info.gz
install-info --dir-file=/usr/share/info/dir /usr/share/info/libext2fs.info

savelog

#==================================================================#
#==================================================================#
xtar coreutils-8.25.tar.xz
patch -Np1 -i ../coreutils-8.25-i18n-2.patch
FORCE_UNSAFE_CONFIGURE=1 ./configure \
            --prefix=/usr            \
            --enable-no-install-program=kill,uptime > $log_configure
FORCE_UNSAFE_CONFIGURE=1 make > $log_make
make NON_ROOT_USERNAME=nobody check-root > $log_make_check
echo "dummy:x:1000:nobody" >> /etc/group
chown -Rv nobody . 
su nobody -s /bin/bash \
          -c "PATH=$PATH make RUN_EXPENSIVE_TESTS=yes check" > $log_make_check
sed -i '/dummy/d' /etc/group
make install > $log_make_install
mv -v /usr/bin/{cat,chgrp,chmod,chown,cp,date,dd,df,echo} /bin
mv -v /usr/bin/{false,ln,ls,mkdir,mknod,mv,pwd,rm} /bin
echo "below will report error, for mv is moved in above, run from here again"
mv -v /usr/bin/{rmdir,stty,sync,true,uname} /bin
mv -v /usr/bin/chroot /usr/sbin
mv -v /usr/share/man/man1/chroot.1 /usr/share/man/man8/chroot.8
sed -i s/\"1\"/\"8\"/1 /usr/share/man/man8/chroot.8
mv -v /usr/bin/{head,sleep,nice,test,[} /bin

savelog

#==================================================================#
#==================================================================#
xtar diffutils-3.5.tar.xz
sed -i 's:= @mkdir_p@:= /bin/mkdir -p:' po/Makefile.in.in
./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check 
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar gawk-4.1.3.tar.xz
./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check|| echo "1 error, not sure it's OK"

xcd gawk-4.1.3.tar.xz
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar findutils-4.6.0.tar.gz
./configure --prefix=/usr --localstatedir=/var/lib/locate > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
mv -v /usr/bin/find /bin
sed -i 's|find:=${BINDIR}|find:=/bin|' /usr/bin/updatedb
savelog

#==================================================================#
#==================================================================#
xtar groff-1.22.3.tar.gz
PAGE=A4 ./configure --prefix=/usr > $log_configure
make > $log_make
make install > $log_make_install

savelog

#==================================================================#
#==================================================================#
xtar grub-2.02~beta3.tar.xz
./configure --prefix=/usr          \
            --sbindir=/sbin        \
            --sysconfdir=/etc      \
            --disable-efiemu       \
            --disable-werror > $log_configure
make > $log_make
make install > $log_make_install

savelog

#==================================================================#
#==================================================================#
xtar less-481.tar.gz
./configure --prefix=/usr --sysconfdir=/etc > $log_configure
make > $log_make
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar gzip-1.8.tar.xz
./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar iproute2-4.7.0.tar.xz
sed -i /ARPD/d Makefile
sed -i 's/arpd.8//' man/man8/Makefile
rm -v doc/arpd.sgml
sed -i 's/m_ipt.o//' tc/Makefile
make > $log_make
make DOCDIR=/usr/share/doc/iproute2-4.7.0 install > $log_make_install
savelog
##==================================================================#
##==================================================================#
xtar kbd-2.0.3.tar.xz
patch -Np1 -i ../kbd-2.0.3-backspace-1.patch
sed -i 's/\(RESIZECONS_PROGS=\)yes/\1no/g' configure
sed -i 's/resizecons.8 //' docs/man/man8/Makefile.in
PKG_CONFIG_PATH=/tools/lib/pkgconfig ./configure --prefix=/usr --disable-vlock > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar libpipeline-1.4.1.tar.gz
PKG_CONFIG_PATH=/tools/lib/pkgconfig ./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar make-4.2.1.tar.bz2
./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar patch-2.7.5.tar.xz
./configure --prefix=/usr > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar sysklogd-1.5.1.tar.gz
sed -i '/Error loading kernel symbols/{n;n;d}' ksym_mod.c
sed -i 's/union wait/int/' syslogd.c
make > $log_make
make BINDIR=/sbin install > $log_make_install
cat > /etc/syslog.conf << "EOF"
# Begin /etc/syslog.conf

auth,authpriv.* -/var/log/auth.log
*.*;auth,authpriv.none -/var/log/sys.log
daemon.* -/var/log/daemon.log
kern.* -/var/log/kern.log
mail.* -/var/log/mail.log
user.* -/var/log/user.log
*.emerg *

# End /etc/syslog.conf
EOF
savelog

#==================================================================#
#==================================================================#
xtar sysvinit-2.88dsf.tar.bz2
patch -Np1 -i ../sysvinit-2.88dsf-consolidated-1.patch
make -C src > $log_make
make -C src install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar eudev-3.2.tar.gz
sed -r -i 's|/usr(/bin/test)|\1|' test/udev-test.pl
cat > config.cache << "EOF"
HAVE_BLKID=1
BLKID_LIBS="-lblkid"
BLKID_CFLAGS="-I/tools/include"
EOF
./configure --prefix=/usr           \
            --bindir=/sbin          \
            --sbindir=/sbin         \
            --libdir=/usr/lib       \
            --sysconfdir=/etc       \
            --libexecdir=/lib       \
            --with-rootprefix=      \
            --with-rootlibdir=/lib  \
            --enable-manpages       \
            --disable-static        \
            --config-cache > $log_configure
LIBRARY_PATH=/tools/lib make > $log_make
mkdir -pv /lib/udev/rules.d
mkdir -pv /etc/udev/rules.d
make LD_LIBRARY_PATH=/tools/lib check > $log_make_check
make LD_LIBRARY_PATH=/tools/lib install > $log_make_install
tar -xvf ../udev-lfs-20140408.tar.bz2
make -f udev-lfs-20140408/Makefile.lfs install >> $log_make_install
LD_LIBRARY_PATH=/tools/lib udevadm hwdb --update
savelog

#==================================================================#
#==================================================================#
xtar util-linux-2.28.1.tar.xz
mkdir -pv /var/lib/hwclock
./configure ADJTIME_PATH=/var/lib/hwclock/adjtime   \
            --docdir=/usr/share/doc/util-linux-2.28.1 \
            --disable-chfn-chsh  \
            --disable-login      \
            --disable-nologin    \
            --disable-su         \
            --disable-setpriv    \
            --disable-runuser    \
            --disable-pylibmount \
            --disable-static     \
            --without-python     \
            --without-systemd    \
            --without-systemdsystemunitdir > $log_configure
make > $log_make
#run the test suite as a non-root user
chown -Rv nobody .
su nobody -s /bin/bash -c "PATH=$PATH make -k check"  > $log_make_check
make install > $log_make_install
savelog

#==================================================================#
#==================================================================#
xtar man-db-2.7.5.tar.xz
./configure --prefix=/usr                        \
            --docdir=/usr/share/doc/man-db-2.7.5 \
            --sysconfdir=/etc                    \
            --disable-setuid                     \
            --with-browser=/usr/bin/lynx         \
            --with-vgrind=/usr/bin/vgrind        \
            --with-grap=/usr/bin/grap > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
sed -i "s:man root:root root:g" /usr/lib/tmpfiles.d/man-db.conf
savelog


#==================================================================#
#==================================================================#
xtar tar-1.29.tar.xz
FORCE_UNSAFE_CONFIGURE=1  \
./configure --prefix=/usr \
            --bindir=/bin > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
make -C doc install-html docdir=/usr/share/doc/tar-1.29
savelog

#==================================================================#
#==================================================================#
xtar texinfo-6.1.tar.xz
./configure --prefix=/usr --disable-static > $log_configure
make > $log_make
make check > $log_make_check
make install > $log_make_install
#optional
make TEXMF=/usr/share/texmf install-tex
pushd /usr/share/info
rm -v dir
for f in *
  do install-info $f dir 2>/dev/null
done
popd
savelog
EOD

#==================================================================#
#==================================================================#
xtar vim-7.4.tar.bz2
echo '#define SYS_VIMRC_FILE "/etc/vimrc"' >> src/feature.h
./configure --prefix=/usr > $log_configure
make > $log_make
make -j1 test > $log_make_check
make install > $log_make_install
ln -sv vim /usr/bin/vi
for L in  /usr/share/man/{,*/}man1/vim.1; do
    ln -sv vim.1 $(dirname $L)/vi.1
done
ln -sv ../vim/vim74/doc /usr/share/doc/vim-7.4
cat > /etc/vimrc << "EOF"
" Begin /etc/vimrc

set nocompatible
set backspace=2
syntax on
if (&term == "iterm") || (&term == "putty")
  set background=dark
endif

" End /etc/vimrc
EOF
savelog

cd / && ./genmakeinstalled.sh >/dev/null
