#!/bin/bash
if [ -z "$1" ]; then echo "Need comment for git commit!"; exit 1; fi 
cd `dirname $0`
echo "git pull" |bash -x
echo "git status"|bash -x
echo "git add --all"|bash -x
echo "git commit -m \"$1\""|bash -x
echo "git push"|bash -x
#echo "git show HEAD"|bash -x
echo "git status"|bash -x

#git diff		-->diff changes before stage
#git diff --cached	-->diff changes after stage and before commit

#-> diff changes to be pushed
#git diff newlayout origin/newlayout	-> diff changes to be pushed 
#				-> or diff changes on the remote and local commited
#git diff origin/newlayout	-> diff changes on the remote and local(not stated)

#-> diff changes to be pulled
#note: git pull=git fetch+git merge
#git branch --all
#git fetch origin   #get a cache of the state of branches in the remote repository 
#git diff newlayout origin/newlayout
#git merge origin/newlayout

#git clone https://neutrino0717@bitbucket.org/neutrino0717/bash4u.git
#git checkout newpython
#test stash
#test stash2
