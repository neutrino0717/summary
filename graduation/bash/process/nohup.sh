#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt '
nohup
1. nohup is a POSIX command to ignore the HUP (hangup) signal. The HUP signal is, by convention, the way a terminal warns dependent processes of logout.
2. Output that would normally go to the terminal goes to a file called nohup.out if it has not already been redirected.
3. The first of the commands below starts the program abcd in the background in such a way that the subsequent logout does not stop it.
    $ nohup abcd >output.log &
    $ exit

    $ nohup find -size +100k > log.txt &
    $ exit
4. nohup is often used in combination with the nice command to run processes on a lower priority.
    $ nohup nice abcd &
'
elrun <<"EOF"
nohup ./sleep.sh > sleep.log &
jobs
pgrep sleep.sh
EOF

eprt '
now exit the ssh session and login again, you will find the sleep.sh process is still running
pgrep sleep.sh
'
