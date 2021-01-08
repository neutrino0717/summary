#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

eprtdoc <<"EOF"
why trap:
    1. While running a script user may press Break or CTRL+C to terminate the process.
    2. User can also stop the process by pressing CTRL+Z.
    3. Error can occur do to bug in a shell script such as arithmetic overflow.
    Signals force the script to exit.
so the trap command captures an interrupt.
    prevent the script from exiting
example:
#capture terminate signals; rm the file; then exit
trap "rm $TEMP_FILE; exit" SIGHUP SIGINT SIGTERM

EOF


elrun <<"EOF"
#capture SIGINI
trap 'echo "get control-C or SIGINI"' 2 
for ((i=15; i>0;i--)); do echo "in loop"; sleep 1; done

EOF
