#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main()
{
    char * s= "stack=overflow";
    int ret =  putenv(s);
    
    assert(ret == 0);
    //printout all the env
    extern char **environ;
    int i;
    for(i = 0; environ[i] != NULL; i++){
        printf("%s\n",environ[i]);
    }
    
    return 0; 
}
