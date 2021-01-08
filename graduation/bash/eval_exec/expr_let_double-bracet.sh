#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}
expr

let
        "let" causes the expression following the assignment to be interpreted as an arithmetic one.
         It is good practice to surround expressions with quotes,

\$((\$x+\$y))


${endColor}"

elrun '
x=1 y=2
z=$((x+y)); echo $z
z=$(($x+$y)); echo $z
z=`expr $x + $y`; echo $z
let z=$x+$y; echo $z 
let z=x+y; echo $z 
let z="x+y"; echo $z 
'

elrun '
let x="1<<4";echo $x
x=$((1<<4));echo $x
((x=1<<4));echo $x
'

elrun '
let x="(1+4)*5"; echo $x 
x=$(((1+4)*5));  echo $x
((x=(1+4)*5));  echo $x
'

