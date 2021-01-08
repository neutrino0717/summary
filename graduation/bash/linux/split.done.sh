#!/usr/bin/env esh
rm -rf /tmp/testsplit*
tar zcvf ~/testsplit.tar.gz  ~/graduation/python/*.py
split -b 1k ~/testsplit.tar.gz /tmp/testsplit
ls -lrt /tmp/testsplit*
cat /tmp/testsplita* > /tmp/testmerge.tar.gz
tar ztvf /tmp/testmerge.tar.gz
