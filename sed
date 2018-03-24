#the same
sed    's/root/me/'      /etc/passwd
sed -n 's/root/me/;p'    /etc/passwd
 
-----------------------------------------------------------

#option n,e,r
##-r,        --regexp-extended 
##-e script, --expression=script
sed    ""                                 /etc/passwd
sed -n ""                                 /etc/passwd
sed -n "p"                                /etc/passwd
sed -n "1     p"                          /etc/passwd
sed -n -e "p"                             /etc/passwd
sed -n -e "$     p"                       /etc/passwd
sed -n -e "1,4   p"                       /etc/passwd
sed -n -e "1,4 ! p"                       /etc/passwd
sed -n -e "1,+3  p"                       /etc/passwd
sed -n -e "1~2   p"                       /etc/passwd  #from first, every two
sed -n --expression="1~2 p"               /etc/passwd
 
-----------------------------------------------------------
#command p,l
sed -n -e "5,$   p"                       /etc/passwd  
sed -n -e "5,$   l"                       /etc/passwd  #l disply the hidden characters, like cat -A
sed -n -e "/^root/,$ p"                   /etc/passwd
sed -n -e "/^root/,+2 p"                  /etc/passwd
sed -n -e "/^root/,/^bin/ p"              /etc/passwd
awk       "/^root/,/^bin/"                /etc/passwd
sed -n -e "/^root/,/^bin/ p; $ p"         /etc/passwd
 
-----------------------------------------------------------
#command s
sed -n "      s/bash/tcsh/p"              /etc/passwd
sed -n "1,$   s/bash/tcsh/p"              /etc/passwd
sed -n "/root/s/bash/tcsh/p"              /etc/passwd
sed -n "/root/s/bash/tcsh/p"              /etc/passwd
sed -n "/root/s/bash/mybash/p"            /etc/passwd
sed -n "/root/s/\(bash\)/my\1/p"          /etc/passwd
sed -n "/root/s/bash/my&/p"               /etc/passwd
 
-----------------------------------------------------------
#command d 
sed    -e "/^root/d"                      /etc/passwd
sed    -e "/^root/, +17 d"                /etc/passwd
sed    -e "/^root/, +17 d; p"             /etc/passwd  #display twices for all not deleted
sed    -e "/^root/, /^nobody/ d"          /etc/passwd
sed    -e "/^root/, /^nobody/ ! d"        /etc/passwd
sed    -e "/^root/d" -e "/^nobody/d"      /etc/passwd
sed    -e "7p;11p;5,16d"     <<<"$(cat -n /etc/passwd)"  #remove 5~16 lines expectfor line 7,11 
 
-----------------------------------------------------------
#command e, r; i, a, c
sed "2       e cat /proc/uptime"               /etc/passwd  #append file   after the 1st line, e execute
sed "1       r /proc/uptime"                   /etc/passwd  #append file   after the 1st line
sed "1       i this is a new line"             /etc/passwd  #insert string before the 1st line
sed "1       i\this is a new line"             /etc/passwd  #insert string before the 1st line
sed "1     s/^/this is a new line\n/"          /etc/passwd
sed "1       a this is a new line"             /etc/passwd  #append string after the 1st line
sed "/^root/ a this is a new line"             /etc/passwd  #append string after the line with root
sed "/^root/ c this is a replaced line"        /etc/passwd  #replaced(command change) with string
sed "/^root/ s/^.*$/this is a replaced line/"  /etc/passwd  #replaced(command change) with string
sed "2,$     c those are replaced lines"       /etc/passwd  #replaced(command change) with string
                                                    
-----------------------------------------------------------
#command q 
sed -n '1       p'       /etc/passwd         
sed -e '1       q'       /etc/passwd             #quit the executing flow after line 1
sed -n '1,3     p'       /etc/passwd         
sed -e '3       q'       /etc/passwd             #quit the executing flow after line 3
sed -e '/^root/ q 99'    /etc/passwd; echo $?    #quit which exit code 99. [addr]q [value]
 
-----------------------------------------------------------
#command w 
sed -n '          w /tmp/passwd'   /etc/passwd;     diff /{tmp,etc}/passwd 
sed -n '4,$       w /tmp/passwd'   /etc/passwd;     diff /{tmp,etc}/passwd
sed -n '1,3 !     w /tmp/passwd' /etc/passwd;       diff /{tmp,etc}/passwd
sed -n '/^root/ ! w /tmp/passwd' /etc/passwd;       diff /{tmp,etc}/passwd
