#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
#How can I have tcpdump write to file and standard output the appropriate data?
Here's a neat way to do what you want:

tcpdump -i eth0 not port 22 -w - | tee tcsh1.pcap | tcpdump -r -

What it does:
    -w - #tells tcpdump to write binary data to stdout
    tee  #writes that binary data to a file AND to its own stdout
    -r - #tells the second tcpdump to get its data from its stdin

EOF

elrun <<"EOF"

EOF
