#ifndef UTIL_H_
#define UTIL_H_

#include <stdio.h>
#include <stdlib.h>

typedef int I32;
typedef unsigned int U32;
typedef short int I16;
typedef unsigned short int U16;
typedef char I8;
typedef unsigned char U8;
typedef float F32;
typedef double F64;

#define ASSERT(test) (test)? assert_good():assert_internal(__FILE__, __LINE__);

void assert_internal(const char* file, int line);
void assert_good(void);

#endif
