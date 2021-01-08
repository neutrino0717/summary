#!/bin/esh
cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 11 | head -n 3

# or 
< /dev/urandom     tr -dc  a-zA-Z0-9  | head -c11; echo

#tr -d, --delete #delete characters in SET1, do not translate
tr -d "Hw ;" <<< "Hw mkviii;"

tr -dc "mkvxi" <<< "Hw mkviii;"; echo

#trim white space
echo " 0 1 3 " | tr -d " "

#tr -dc --delete complement
echo "a*73ma83z&377##e#" | tr -dc 'a-z';  echo

read -r -d '' a <<'EOF'
  100 Jason Smith 
  200 John Doe 
  300 Sanjay Gupta 
  400 Ashok Sharma
EOF
#Convert a file to all upper-case 
echo "$a" | tr a-z A-Z
echo "$a" | tr [:lower:] [:upper:]
