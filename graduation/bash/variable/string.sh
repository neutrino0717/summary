#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''


elrun <<"EOF"
name="Scarborough Fair"
# substring by index 6, size 5
echo "substr: ${name:6:5}"
# the index of 'rough'
x=${name%%rough*}; [[ $x = $name ]] && echo -1 || echo ${#x}

name="Scarborough Fair and new Fair"
# replace: Fair --> fair
echo ${name/Fair/fair}
# replace all occurence of 'Fair' with 'fair'
echo ${name//Fair/fair}

name="Scarborough Fair"
# the string length:
echo ${#name}


# ways to capitalize
# in tr
echo $name | tr '[:lower:]' '[:upper:]'
echo $name | tr '[:upper:]' '[:lower:]'
# in awk
echo $name | awk '{print toupper($0)}'
echo $name | awk '{print tolower($0)}'
# in bash 4.0
echo ${name^^}
echo ${name,,}
echo ${name^}


EOF
