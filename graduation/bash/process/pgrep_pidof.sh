#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo "pgrep init" | bash -x
echo "pidof init" | bash -x

