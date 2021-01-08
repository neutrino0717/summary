#!/usr/bin/env eepython

##read all in file into list
with open("/etc/hosts") as f: print f.readlines()
print open("/etc/hosts").readlines()

#check if items in wordlist exits in tweet
wordlist = ["scala", "akka", "play framework", "sbt", "typesafe"]
tweet = "This is an example tweet talking about scala and sbt."
print map(lambda x: x in tweet.split(), wordlist)
print [ x in tweet.split() for x in wordlist ]
