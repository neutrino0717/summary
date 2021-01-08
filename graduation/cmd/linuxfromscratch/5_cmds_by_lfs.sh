#!/bin/bash
#######################################################################################
###1. build a new and host-independent toolchain
###   Binutils-->GCC-->Linux API Headers-->Glibc-->Binutils again    
#        Binutils installs its assembler and linker in two locations, /tools/bin and /tools/$LFS_TGT/bin
#        GCC will use assembler: tools/i686-lfs-linux-gnu/bin/as 
#                     linker:    tools/i686-lfs-linux-gnu/bin/ld
###2. uses this toolchain to build the other essential tools.

# The Binutils package contains a linker, an assembler, and other tools for handling object files. 
set -e
set -u
LFS=/mnt/lfs
green='\e[0;32m'; blue='\e[0;34m'; red='\e[31m'; yellow='\e[0;33m'; endColor='\e[0m'
declare -A mtar
mtar=([bz2]=jxvf [.gz]=zxvf [.xz]=xvf)

xtar(){
  pname=$1 
  pdir=`echo ${pname}|sed -e 's/\.tar\..*$//'` 
  grep -q "tcl" <<<"$pdir" && pdir=tcl8.6.6
  ext=${pname: -3}
  arg=${mtar[$ext]}
  echo -e "${red}=======$pname starting=======${endColor}" |tee -a ${LOG_DIR}/log/5.log
  cd $LFS/sources/ && rm -rfv ${pdir} && tar ${arg} ${pname} && cd ${pdir}
  if [ "$?" != 0 ]; then
    echo "ERROR with xtar $pname"
    exit 1
  fi
}

savelog(){
  #Asia/Shanghai cannot be recongined in some stage, so use UTC for all
  ##logfilecur=${LOG_DIR}/log/`TZ='Asia/Shanghai' date +%y%m%d%H%M%S`${pname}.log
  logfilecur=${LOG_DIR}/log/`date -u +%y%m%d%H%M%S`${pname}.log
  find /mnt/lfs/tools/ -type f | while read l; do md5sum $l|awk '{print $2" "$1}'; done > $logfilecur
  rm -rf $LFS/sources/$pdir
  echo -e "${green}=======$pname done=======${endColor}" |tee -a ${LOG_DIR}/log/5.log
}

#echo ${LOG_DIR}/log/`TZ='Asia/Shanghai' date +%y%m%d%H%M%S`${pname}.log
#exit 0
if [ "$(id -u -n)" != "lfs" ]; then echo "please run as lfs!"; exit 1; fi
<<"EOF"
#********************************************************************************#
#********************************************************************************#
#Binutils-2.27 - Pass 1
xtar binutils-2.27.tar.bz2
mkdir -vp build && cd build
## http://www.linuxfromscratch.org/lfs/view/stable/chapter05/binutils-pass1.html
../configure --prefix=/tools            \
             --with-sysroot=$LFS        \
             --with-lib-path=/tools/lib \
             --target=$LFS_TGT          \
             --disable-nls              \
             --disable-werror && make
case $(uname -m) in
  x86_64) mkdir -v /tools/lib && ln -sv lib /tools/lib64 ;;
esac
make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#Installation of Cross GCC 
xtar gcc-6.2.0.tar.bz2
tar -xf ../mpfr-3.1.4.tar.xz && mv -v mpfr-3.1.4 mpfr
tar -xf ../gmp-6.1.1.tar.xz  && mv -v gmp-6.1.1 gmp
tar -xf ../mpc-1.0.3.tar.gz  && mv -v mpc-1.0.3 mpc
##find linux64.h or linux.h or sysv4.h
find gcc/config -name linux64.h -o -name linux.h -o -name sysv4.h
##1. prepends /tools to every instance of /lib/ld, /lib64/ld or /lib32/ld
##2. replaces hard-coded instances of /usr with /tool
##3. redefine STANDARD_STARTFILE_PREFIX_1 and 2. Note that the trailing / in /tools/lib/ is required.
##4. cp -u:  copy only when the SOURCE file is newer than the destination file
for file in \
 $(find gcc/config -name linux64.h -o -name linux.h -o -name sysv4.h)
do
  cp -uv $file{,.orig}
  sed -e 's@/lib\(64\)\?\(32\)\?/ld@/tools&@g' \
      -e 's@/usr@/tools@g' $file.orig > $file
  echo '
#undef STANDARD_STARTFILE_PREFIX_1
#undef STANDARD_STARTFILE_PREFIX_2
#define STANDARD_STARTFILE_PREFIX_1 "/tools/lib/"
#define STANDARD_STARTFILE_PREFIX_2 ""' >> $file
  touch $file.orig
done
##check
{ for file in $(find gcc/config -name linux64.h -o -name linux.h -o -name sysv4.h); do mycmd="diff $file{,.orig}"; echo "$mycmd"|egrep --color "^.*$"; bash -c "$mycmd"; done; echo "only to remove diff exit 1 status"; } | tee ${LOG_DIR}/log/`date +%y%m%d%H%M%S`${pname}.diff.log
mkdir -v build && cd build
../configure                                       \
    --target=$LFS_TGT                              \
    --prefix=/tools                                \
    --with-glibc-version=2.11                      \
    --with-sysroot=$LFS                            \
    --with-newlib                                  \
    --without-headers                              \
    --with-local-prefix=/tools                     \
    --with-native-system-header-dir=/tools/include \
    --disable-nls                                  \
    --disable-shared                               \
    --disable-multilib                             \
    --disable-decimal-float                        \
    --disable-threads                              \
    --disable-libatomic                            \
    --disable-libgomp                              \
    --disable-libmpx                               \
    --disable-libquadmath                          \
    --disable-libssp                               \
    --disable-libvtv                               \
    --disable-libstdcxx                            \
    --enable-languages=c,c++ && make && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#Installation of Linux API Headers, expose the kernel's API for use by Glibc
xtar linux-4.7.2.tar.xz
## make mrproper  Delete the current configuration, and all generated files
make mrproper && make INSTALL_HDR_PATH=dest headers_install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
cp -rv dest/include/* /tools/include
savelog

#********************************************************************************#
#********************************************************************************#
#Glibc-2.24 
##Note that for 64-bit machines, the interpreter name will be /tools/lib64/ld-linux-x86-64.so.2
xtar glibc-2.24.tar.xz
mkdir -pv build && cd build
../configure                             \
      --prefix=/tools                    \
      --host=$LFS_TGT                    \
      --build=$(../scripts/config.guess) \
      --enable-kernel=2.6.32             \
      --with-headers=/tools/include      \
      libc_cv_forced_unwind=yes          \
      libc_cv_c_cleanup=yes
make && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
which $LFS_TGT-gcc
##--> /tools/bin/x86_64-lfs-linux-gnu-gcc
echo 'int main(){}' > dummy.c
$LFS_TGT-gcc dummy.c
readelf -l a.out | grep ': /tools' | tee -a ${LOG_DIR}/log/5.log
if [ "$?" != 0 ]; then echo "No /tools in readelf output!!!"; exit 1; fi
##-->      [Requesting program interpreter: /tools/lib64/ld-linux-x86-64.so.2]
rm -v dummy.c a.out
savelog

#********************************************************************************#
#********************************************************************************#
#Libstdc++ is part of the GCC sources
xtar gcc-6.2.0.tar.bz2
mkdir -v build && cd build
../libstdc++-v3/configure           \
    --host=$LFS_TGT                 \
    --prefix=/tools                 \
    --disable-multilib              \
    --disable-nls                   \
    --disable-libstdcxx-threads     \
    --disable-libstdcxx-pch         \
    --with-gxx-include-dir=/tools/$LFS_TGT/include/c++/6.2.0 && make && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog
mv $logfilecur ${logfilecur%.log}_libstdc++

#********************************************************************************#
#********************************************************************************#
#Binutils-2.27 - Pass 2
##The Binutils package contains a linker, an assembler, and other tools for handling object files. 
xtar binutils-2.27.tar.bz2
mkdir -vp build && cd build
## CC=$LFS_TGT-gcc AR=$LFS_TGT-ar RANLIB=$LFS_TGT-ranlib
## this is really a native build of Binutils, setting these variables ensures that the build system 
## uses the cross-compiler and associated tools instead of the ones on the host system. 
CC=$LFS_TGT-gcc                \
AR=$LFS_TGT-ar                 \
RANLIB=$LFS_TGT-ranlib         \
../configure                   \
    --prefix=/tools            \
    --disable-nls              \
    --disable-werror           \
    --with-lib-path=/tools/lib \
    --with-sysroot && make && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
##Now prepare the linker for the “Re-adjusting” phase in the next chapter: 
##remove all compiled files in the ld subdirectory. 
make -C ld clean && make -C ld LIB_PATH=/usr/lib:/lib
##rebuilds everything in the ld subdirectory
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
cp -v ld/ld-new /tools/bin
savelog
mv $logfilecur ${logfilecur%.log}_pass2.log

#********************************************************************************#
#********************************************************************************#
#GCC-6.2.0 - Pass 2 
xtar gcc-6.2.0.tar.bz2
##Create a full version of the internal header
$LFS_TGT-gcc -print-libgcc-file-name
cat gcc/limitx.h gcc/glimits.h gcc/limity.h > \
  `dirname $($LFS_TGT-gcc -print-libgcc-file-name)`/include-fixed/limits.h
##Once again, change the location of GCC's default dynamic linker to use the one installed in /tools. 
for file in $(find gcc/config -name linux64.h -o -name linux.h -o -name sysv4.h)
do
  cp -uv $file{,.orig}
  sed -e 's@/lib\(64\)\?\(32\)\?/ld@/tools&@g' -e 's@/usr@/tools@g' $file.orig > $file
  echo '
#undef STANDARD_STARTFILE_PREFIX_1
#undef STANDARD_STARTFILE_PREFIX_2
#define STANDARD_STARTFILE_PREFIX_1 "/tools/lib/"
#define STANDARD_STARTFILE_PREFIX_2 ""' >> $file
  touch $file.orig
done
##check
for file in $(find gcc/config -name linux64.h -o -name linux.h -o -name sysv4.h); do mycmd="diff $file{,.orig}"; echo "$mycmd"|egrep --color "^.*$"; bash -c "$mycmd"; done; echo "only to remove diff exit 1 status"
tar -xf ../mpfr-3.1.4.tar.xz && mv -v mpfr-3.1.4 mpfr
tar -xf ../gmp-6.1.1.tar.xz  && mv -v gmp-6.1.1 gmp
tar -xf ../mpc-1.0.3.tar.gz  && mv -v mpc-1.0.3 mpc
mkdir -pv build && cd build
##unset any environment variables that override the default optimization flags. 
CC=$LFS_TGT-gcc                                    \
CXX=$LFS_TGT-g++                                   \
AR=$LFS_TGT-ar                                     \
RANLIB=$LFS_TGT-ranlib                             \
../configure                                       \
    --prefix=/tools                                \
    --with-local-prefix=/tools                     \
    --with-native-system-header-dir=/tools/include \
    --enable-languages=c,c++                       \
    --disable-libstdcxx-pch                        \
    --disable-multilib                             \
    --disable-bootstrap                            \
    --disable-libgomp && make && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
ln -sv gcc /tools/bin/cc
echo 'int main(){}' > dummy.c
cc dummy.c
readelf -l a.out | grep ': /tools' | tee -a ${LOG_DIR}/log/5.log
if [ "$?" != 0 ]; then echo "No /tools in readelf output!!!"; exit 1; fi
##-->      [Requesting program interpreter: /tools/lib64/ld-linux-x86-64.so.2]
rm -v dummy.c a.out
savelog
mv $logfilecur ${logfilecur%.log}_pass2.log

#********************************************************************************#
#********************************************************************************#
#Installation of Tcl-core 
xtar tcl-core8.6.6-src.tar.gz
cd unix
./configure --prefix=/tools && make && TZ=UTC make test && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
##optional now
###--> all.tcl:        Total   31259   Passed  29965   Skipped 1294    Failed  0
##The Tcl library, writable so debugging symbols can be removed later
chmod -v u+w /tools/lib/libtcl8.6.so
##Install Tcl's headers. The next package, Expect, requires them to build
make install-private-headers
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
##--> Installing private header files to /tools/include/
ln -sv tclsh8.6 /tools/bin/tclsh
savelog

#********************************************************************************#
#********************************************************************************#
#Expect-5.45 
xtar expect5.45.tar.gz
cp -v configure{,.orig}
sed 's:/usr/local/bin:/bin:' configure.orig > configure
./configure --prefix=/tools       \
            --with-tcl=/tools/lib \
            --with-tclinclude=/tools/include && make && make test && make SCRIPTS="" install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#DejaGNU package contains a framework for testing other programs. 
xtar dejagnu-1.6.tar.gz
./configure --prefix=/tools && make install && make check
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
##--># of expected passes            78
savelog

#********************************************************************************#
#********************************************************************************#
# Check is a unit testing framework for C. 
xtar check-0.10.0.tar.gz
PKG_CONFIG= ./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The Ncurses package contains libraries for terminal-independent handling of character screens. 
xtar ncurses-6.0.tar.gz
sed -i s/mawk// configure
./configure --prefix=/tools \
            --with-shared   \
            --without-debug \
            --without-ada   \
            --enable-widec  \
            --enable-overwrite && make && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The Bash package contains the Bourne-Again SHell. 
xtar bash-4.3.30.tar.gz
./configure --prefix=/tools --without-bash-malloc && make && make tests && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
ln -sv bash /tools/bin/sh
savelog

#********************************************************************************#
#********************************************************************************#
#bzip2 yields a much better compression percentage than with the traditional gzip
xtar bzip2-1.0.6.tar.gz
make && make PREFIX=/tools install
savelog

#********************************************************************************#
#********************************************************************************#
# The Coreutils package contains utilities for showing and setting the basic system characteristics. 
xtar coreutils-8.25.tar.xz
./configure --prefix=/tools --enable-install-program=hostname
make && make RUN_EXPENSIVE_TESTS=yes check && make install
savelog

#********************************************************************************#
#********************************************************************************#
#Diffutils
xtar diffutils-3.5.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#File package contains a utility for determining the type of a given file or files
xtar file-5.28.tar.gz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The Findutils package contains programs to find files. 
xtar findutils-4.6.0.tar.gz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
# Gawk package contains programs for manipulating text files. 
xtar gawk-4.1.3.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The Gettext package contains utilities for internationalization and localization. These allow programs to be compiled with NLS (Native Language Support), enabling them to output messages in the user's native language. 
xtar gettext-0.19.8.1.tar.xz
#./configure --prefix=/tools && make && make check && make install
##For our temporary set of tools, we only need to build and install three programs from Gettext. 
cd gettext-tools
EMACS="no" ./configure --prefix=/tools --disable-shared
make -C gnulib-lib 
make -C intl pluralx.c
make -C src msgfmt
make -C src msgmerge 
make -C src xgettext
##Install the msgfmt, msgmerge and xgettext programs: 
cp -v src/{msgfmt,msgmerge,xgettext} /tools/bin
savelog

#********************************************************************************#
#********************************************************************************#
#Grep-2.25
xtar grep-2.25.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The Gzip package contains programs for compressing and decompressing files. 
xtar gzip-1.8.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The M4 package contains a macro processor. 
xtar m4-1.4.17.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The Make package contains a program for compiling packages. 
xtar make-4.2.1.tar.bz2
./configure --prefix=/tools --without-guile 
make 
#make check   #--> with error
make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
# The Patch package contains a program for modifying or creating files by applying a “patch” file typically created by the diff program. 
xtar patch-2.7.5.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
# The Perl package contains the Practical Extraction and Report Language. 
xtar perl-5.24.0.tar.bz2
sh Configure -des -Dprefix=/tools -Dlibs=-lm
make
cp -v perl cpan/podlators/scripts/pod2man /tools/bin
mkdir -pv /tools/lib/perl5/5.24.0
cp -Rv lib/* /tools/lib/perl5/5.24.0
savelog

#********************************************************************************#
#********************************************************************************#
# The Sed package contains a stream editor. 
xtar sed-4.2.2.tar.bz2
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
# The Tar package contains an archiving program. 
xtar tar-1.29.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
# The Texinfo package contains programs for reading, writing, and converting info pages. 
xtar texinfo-6.1.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
# The Util-linux package contains miscellaneous utility programs. 
xtar util-linux-2.28.1.tar.xz
./configure --prefix=/tools                \
            --without-python               \
            --disable-makeinstall-chown    \
            --without-systemdsystemunitdir \
            PKG_CONFIG=""
make && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The Xz package contains programs for compressing and decompressing files. It provides capabilities for the lzma and the newer xz compression formats. Compressing text files with xz yields a better compression percentage than with the traditional gzip or bzip2 commands. 
xtar xz-5.2.2.tar.xz
./configure --prefix=/tools && make && make check && make install
if [ "$?" != 0 ]; then echo "Wrong making $pname !!!"; exit 1; fi
savelog

#********************************************************************************#
#********************************************************************************#
#The steps in this section are optional, but if the LFS partition is rather small, it is beneficial to learn that unnecessary items can be removed. 
#strip --strip-debug /tools/lib/*
#/usr/bin/strip --strip-unneeded /tools/{,s}bin/*
#To save more, remove the documentation: 
#rm -rf /tools/{,share}/{info,man,doc}
#At this point, you should have at least 3 GB of free space in $LFS that can be used to build and install Glibc and Gcc in the next phase. 

sudo chown -R root:root $LFS/tools
sudo tar jcvf ~/tools_lfs.tar.bz2 $LFS/tools
EOF
