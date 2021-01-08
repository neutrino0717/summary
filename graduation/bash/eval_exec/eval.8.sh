#!/bin/esh

x=10; y=x; eval echo '$'$y

om_cn_vlan=1111
pran_vlan=1112
media_vlan=1113
arr=(om_cn pran media)
for my_nw in ${arr[@]}; do
  eval my_vlan=\$${my_nw}_vlan
  echo $my_vlan
done
