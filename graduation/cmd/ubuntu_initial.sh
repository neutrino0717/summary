#!/bin/bash
#tested on "Ubuntu 14.04.4 LTS", "3.13.0-29-generic"
set +e
echo "do below first!!!"
cat <<"EOF"
useradd neutrino0717 -m -s /bin/bash
passwd neutrino0717
#visudoer
egrep '^neutrino0717' /etc/sudoers || {
echo "%sudo ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
echo "neutrino0717 ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
}

su - neutrino0717

sudo apt-get update
sudo apt-get install git git-gui git-cola gitg
git config --global user.email liuenmao@hotmail.com
git config --global user.name "neutrino0717"

ssh-keygen 
https://bitbucket.org/account/user/neutrino0717/ssh-keys/
git clone git@bitbucket.org:neutrino0717/graduation.git
git clone https://neutrino0717@bitbucket.org/neutrino0717/graduation.git


git clone git@bitbucket.org:neutrino0717/bash4u.git
git clone https://neutrino0717@bitbucket.org/neutrino0717/bash4u.git

https://github.com/settings/keys
git clone git@github.com:neutrino0717/summary.git
git clone https://github.com/neutrino0717/summary.git

ln -sf graduation/.bash_aliases
ln -sf graduation/bash
ln -sf graduation/python
ln -sf graduation/java


http://blog.vpsnm.com/30.html  #mount sdb
sudo mkdir /data
sudo mount /dev/sdb1 /data
sudo fdisk -l
sudo fdisk /dev/sdb
mkfs -t ext3 /dev/sdb1
sudo mkfs -t ext3 /dev/sdb1
EOF

[[ $EUID -eq 0 ]] || { echo -e "${red}Error: This script must be run as root!${endColor}"; exit 1; }
if [ ! "$1" ] || [[ "$1" =~ '^(local|vpn)$' ]];  then echo "Usage: $0 vps|local"; exit 1; fi

. ~/graduation/common.sh
#for local linux only

apt_install(){
  dpkg-query -l $@  || ( apt-get install -y $@ )
  if [ $? -ne 0 ]; then echo "--> install error for $@"; fi
}
pip_install(){
  pip list | egrep --color -i $1 || ( pip install $@ )
  if [ $? -ne 0 ]; then echo "--> install error for $@"; fi
}



#git clone https://neutrino0717@bitbucket.org/neutrino0717/graduation.git
cat <<EOF
apt-get remove -y --purge libreoffice*
apt-get clean -y
apt-get autoremove -y

apt-get update 
apt-get upgrade -y
EOF

#if [ "$1" == 'local' ]; then
#  ln -sf /home/neutrino/graduation/expect/autoconn_elite_crontab_home.sh
#  crontab -l | grep -q  autoconn_elite || crontab -l | { cat; echo "*/5 * * * * ~/graduation/learning/expect/autoconn_elite_crontab_home.sh"; } | crontab -
#fi

if [ "$1" == 'vps' ]; then
  apt_install iptables pptpd 

  pip_install shadowsocks
  egrep ssserver -q /etc/rc.local || sed -i 's|\(^exit.*$\)|sudo ssserver -p 8080 -k siemens -m rc4-md5 --user nobody -d start\n\1|g' /etc/rc.local
  #sudo ssserver -d stop
  sudo ssserver -p 8080 -k siemens -m rc4-md5 --user nobody -d start
  tail -10l /var/log/shadowsocks.log

  apt_install tinyproxy
  service tinyproxy start
  egrep tinyproxy -q /etc/rc.local || sed -i 's|\(^exit.*$\)|sudo service tinyproxy start\n\1|g' /etc/rc.local
fi


apt_install python-pygments
apt_install expect rpm vim hping3 curl tree aptitude 
#apt_install expect unrar
apt_install apache2 libapache2-mod-wsgi 

apt_install mysql-server mysql-common mysql-client libmysqlclient-dev
apt_install  python-mysql.connector
#sudo mysql -uroot -p


apt_install bpython python-dev ipython python-ipdb

apt_install python-pip || apt-get install -y python-pip=1.5.4-1

pip_install xlrd
apt-get install python-xlrd
pip_install mysql-python
pip_install django --upgrade
pip_install beautifulsoup4
pip_install cheat

pip_install PrettyTable
apt_install git git-gui git-cola gitg
which vimcat || wget -O /usr/bin/vimcat http://www.vim.org/scripts/download_script.php?src_id=23422 && sudo chmod +x /usr/bin/vimcat

#egrep -i '^export PS1' ~/.bashrc || cat >> ~/.bashrc <<"EOF"
export PS1="\[$(tput bold)\]\[$(tput setaf 1)\][\[$(tput setaf 6)\]\u\[$(tput setaf 2)\]@\[$(tput setaf 4)\]\h \[$(tput setaf 5)\]\W\[$(tput setaf 1)\]]\[$(tput setaf 3)\]\\$\\n\[$(tput sgr0)\]"
#EOF
#egrep -i '^export PATH' ~/.bashrc || cat >> ~/.bashrc <<<'export PATH=$PATH:~/graduation'

#cat > ~/.vimrc <<"EOF"
#filetype indent on
#set smartindent
#autocmd BufRead,BufWritePre *.sh normal gg=G
#EOF
#sed -i 's|^PasswordAuthentication.*$|PasswordAuthentication yes|g' /etc/ssh/sshd_config
#service ssh restart


#pycharm
#sudo add-apt-repository ppa:mystic-mirage/pycharm
#sudo apt-get update
#sudo aptitude install pycharm-community

#--------------perl----------------------
apt_install perl-doc
sudo perl -MCPAN -e 'install File::chdir'
sudo cpan install Log::Log4perl
sudo cpan install LWP:Simple
sudo cpan install List::MoreUtils
sudo perl -MCPAN -e 'install DB::Color'
echo "use DB::Color;" >> ~/.perldb
chmod 700 ~/.perldb
##see color below
#perl -MDB::Color -d /home/eml/test.pl
#perl -d /home/eml/test.pl
apt_install rlwrap 
#rlwrap perl -d -e 1

sudo cpan Moo  #simple verson of Moose
sudo cpan Moose
sudo cpan DateTime
