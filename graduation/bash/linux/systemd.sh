#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${red}
init process --> /etc/init.d/apache2   # slow, for init call each service one by one
                                       # complicated, start/stop script need to be prepared by each service
systemd(d means aemon)                 # init is no longer needed, systemd will become process pid 1

#reboot 
sudo systemctl reboot
#shutdown and so on
sudo systemctl poweroff|halt|suspend|hibernate

${endColor}"
eprt ''
elrun "EOF"

EOF
