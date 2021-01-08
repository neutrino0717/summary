#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${green}-->free up space${endColor}"

cat <<EOF
#delete downloaded packages (.deb) already installed and that you no longer need:
sudo apt-get clean

#remove all stored archives in your cache for packages that can not be downloaded anymore
sudo apt-get autoclean

#some apps leave behind remnant files even after you uninstall them. This command will clean up those orphaned files.
sudo apt-get autoremove
EOF
