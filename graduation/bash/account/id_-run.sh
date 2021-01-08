#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
eprt "
       -r, --real
              print the real ID instead of the effective ID, with -ugG
       -u, --user
              print only the effective user ID
       -n, --name
              print a name instead of a number, for -ugG
"
erun "id -run"
erun "sudo id -run"
erun "sudo id -un"

