pygmentize -l bash <<EOF
yum install bmp-mp3
yum info bmp-mp3        #detail info of the package
yum search kernel |more
yum list |grep kernel
yum list |more          #all available packages, including not installed
yum list available      #all packages in the sources
yum list updates        #all packages can be updated in the sources
yum list installed      #all packages installed
yum list mp* |more
yum update kernelyum update
yum remove bmp-mp3
EOF
