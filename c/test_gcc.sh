cat > hello.c <<"EOF"
#include <stdio.h>
int main() {
    printf("Penguin!\n");
}
EOF

gcc -o hello hello.c
./hello
rm -rf hello hello.c
