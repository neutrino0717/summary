#!/usr/bin/env esh
a="name: Sirius\ndistance: 8.5828\ndate: 1844\nname: Alpha-Centauri\ndistance: 4.3650\ndate: 1689\nname: Procyon\ndistance: 11.402\ndate: 1844"
echo -e "$a"

##
echo -e "$a" |awk '{if(NR%3==0){print $2}else{printf "%s ",$2}}' |column -t
