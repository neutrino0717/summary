#!/bin/bash

path_iso="/root/rhel-server-6.7-x86_64-dvd.iso"
mkdir /mnt/disk
mount -t iso9660 -o loop /root/rhel-server-6.7-x86_64-dvd.iso /mnt/disk

#find /mnt/disk/ -name repodata
cat > /etc/yum.repos.d/myrhel.repo <<"EOF"
[HighAvailability]
name=HighAvailalility
baseurl=file:///mnt/disk/HighAvailability
enabled=1
gpcheck=0
[LoadBalancer]
name=LoadBalancer
baseurl=file:///mnt/disk/LoadBalancer
enabled=1
gpgcheck=0
[Server]
name=Server
baseurl=file:///mnt/disk/Server
enabled=1
gpgcheck=0
EOF

yum clean all
yum makecache
yum grouplist
yum repolist
#yum install tree lftp dhcp vsftpd tftp*

