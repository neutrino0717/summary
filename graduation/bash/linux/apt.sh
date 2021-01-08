#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

cat <<EOF
apt-cache search package
apt-cache show package              #size, version, specification of the package
apt-cache depends package           #all the packages that the package depends on 
apt-cache rdepends package          #all the packages that the package been depended on

apt-get install package
apt-get install package --reinstall
apt-get -f install                  #-f=--fix-missing
apt-get remove package              #remove package but not config
apt-get remove package --purge      #remove package and config 
apt-get update                      #update sources
apt-get upgrade                     #upgrade installed packages
apt-get dist-upgrade                #update system
apt-get build-dep package 
apt-get source package                   #download source codes
apt-get clean && sudo apt-get autoclean  #remove useless packages

#How to uninstall LibreOffice
apt-get remove --purge libreoffice*
apt-get clean
apt-get autoremove
EOF
