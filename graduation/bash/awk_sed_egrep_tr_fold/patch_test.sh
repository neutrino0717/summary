#!/bin/bash
f1=/tmp/test_v1.c
f2=/tmp/test_v2.c
p=/tmp/test_v1.patch


cat > $f1 <<"EOF"
#include <stdio.h>
void main() {
    int x = 7;
    printf("%d\n", x);
    printf("Penguin!\n");
}
EOF

cat > $f2 <<"EOF"
#include <stdio.h>
int main() {
    int x = 7;
    printf("%d\n", x);
    printf("Penguin!\n");
}
EOF

diff -u $f1 $f2 > $p
cat $p

patch $f1 < $p
diff $f1 $f2
