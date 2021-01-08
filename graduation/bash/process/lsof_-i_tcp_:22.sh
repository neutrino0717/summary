#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${green}
 -i [i]   selects the listing of files any of whose Internet address matches the address specified in i.  
       To list all open IPv4 network files in use by the process whose PID is 1234, use:

              lsof -i 4 -a -p 1234

       Presuming the UNIX dialect supports IPv6, to list only open IPv6 network files, use:

              lsof -i 6

       To list all files using any protocol on ports 513, 514, or 515 of host wonderland.cc.purdue.edu, use:

              lsof -i @wonderland.cc.purdue.edu:513-515

       To list all files using any protocol on any port of mace.cc.purdue.edu (cc.purdue.edu is the default domain), use:

              lsof -i @mace

       To list all open files for login name ``abe'', or user ID 1234, or process 456, or process 123, or process 789, use:

              lsof -p 456,123,789 -u 1234,abe

       To find an IP version 4 socket file by its associated numeric dot-form address, use:

              lsof -i@128.210.15.17

       To find an IP version 6 socket file (when the UNIX dialect supports IPv6) by its associated numeric colon-form address, use:

              lsof -i@[0:1:2:3:4:5:6:7]

       To find an IP version 6 socket file (when the UNIX dialect supports IPv6) by an associated numeric colon-form address that  has  a
       run of zeroes in it - e.g., the loop-back address - use:

              lsof -i@[::1]

${endColor}"
erun "lsof -i TCP" 
erun "lsof -i :22"
