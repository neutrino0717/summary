
cd ~; scp -r 115.126.100.179:/home/neutrino0717/.ssh .
git clone git@github.com:neutrino0717/summary.git
git clone git@bitbucket.org:neutrino0717/graduation.git
git clone git@github.com:neutrino0717/eepython.git
ln -sf /home/neutrino0717/graduation/cmd/.bash_aliases
ln -sf /home/neutrino0717/graduation/cmd/.tmux.conf
ln -sf /home/neutrino0717/graduation/c/.vimrc_c
ln -sf .bash_aliases ml
sudo ln -fs /home/neutrino0717/eepython/eepython.py /usr/bin/eepython


