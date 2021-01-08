#!/usr/bin/env esh
umask
umask 022 && touch umask_test && ls -l umask_test; rm -f umask_test
umask 002 && touch umask_test && ls -l umask_test; rm -f umask_test
