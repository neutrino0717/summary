#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
eprt "
read is stripping the whitespace. Wipe \$IFS first.
"

erun 'read -r -e name <<<"   Neutrino  "; echo "-->${name}<--"'
erun 'IFS= read -r -e name <<<"   Neutrino  "; echo "-->${name}<--"'





