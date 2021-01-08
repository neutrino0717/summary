ssh-keygen -t rsa -b 4096 -C "liuenmao@hotmail.com"
ssh-agent -s
ssh-add ~/.ssh/id_rsa
echo "
please put ~/.ssh/id_rsa.pub 
`cat ~/.ssh/id_rsa.pub`
to
https://bitbucket.org/account/user/neutrino0717/ssh-keys/
"
git remote set-url origin git@bitbucket.org:neutrino0717/graduation.git

curl -L https://raw.github.com/git/git/master/contrib/completion/git-prompt.sh > ~/graduation/projects/others/git-prompt.sh

curl https://raw.githubusercontent.com/git/git/master/contrib/completion/git-completion.bash -o ~/graduation/projects/others/git-completion.bash
