#!/bin/esh
a=3; ((a>2&&a<4)) && echo "$a is between 2 and 4"

a=3; { [ $a -gt 2 ] && [ $a -lt 4 ]; } && echo "$a is bt 2 and 4"

a=3; if [ $a -gt 2 ] && [ $a -lt 4 ]; then echo "$a is bt 2 and 4"; fi 

a=3; if [[ $a -gt 2  &&  $a -lt 4 ]]; then echo "$a is bt 2 and 4"; fi 
