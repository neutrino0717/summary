#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

pygmentize -l bash $0; exit 0

path_iso="/gsn/sw/rhel-server-6.4-x86_64-dvd.iso"
mkdir /mnt/disk
#umount
#mount from the cd-rom
#mount /dev/sr0 /mnt/disk
mount -t iso9660 -o loop ${path_iso} /mnt/disk

#find /mnt/disk/ -name repodata
#/mnt/disk/Cluster/repodatax
#/mnt/disk/ClusterStorage/repodata
#/mnt/disk/Server/repodata
#/mnt/disk/VT/repodata

#for all
cat > /etc/yum.repos.d/rhel.repo <<"EOF"
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

#for server section only
cat > /etc/yum.repos.d/rhel.repo <<"EOF"
[Server]
name=Server
baseurl=file:///mnt/disk/Server
enabled=1
gpgcheck=0
EOF


#yum clean all
#yum makecache
#yum grouplist
#yum repolist
yum install tree lftp dhcp vsftpd tftp*

