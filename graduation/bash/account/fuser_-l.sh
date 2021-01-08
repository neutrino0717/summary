#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

eprt "
shows all the possible signals that can be used with the fuser tool.

The fuser utility can also be used to send specific signals to a process. 
When used with the -k option, the fuser command sends the KILL signal to a process. 
"
erun "fuser -l"


