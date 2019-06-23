#include <stdio.h>
#include <float.h>

int main(int argc, char *argv[])
{
  long long int lli_var;
  float f_var;
  double d_var;
  long double ld_var;

  printf("\nLONG LONG INTEGER:\n\n");
  printf("lli_var size =%5lu\n", sizeof(lli_var));
  
  printf("\nFLOAT\n\n");
  printf("f_var size   =%5lu\n", sizeof(f_var)); 
  printf("f_var dig    =%5d\n", FLT_DIG); 
  printf("f_var mant   =%5d\n", FLT_MANT_DIG);

  printf("\nDOUBLE\n\n");
  printf("d_var size   =%5lu\n", sizeof(d_var)); 
  printf("d_var dig    =%5d\n", DBL_DIG); 
  printf("d_var mant   =%5d\n", DBL_MANT_DIG);

  printf("\nLONG DOUBLE\n\n");
  printf("ld_var size   =%5lu\n", sizeof(d_var)); 
  printf("ld_var dig    =%5d\n", LDBL_DIG); 
  printf("ld_var mant   =%5d\n", LDBL_MANT_DIG);
  printf("\n");

  return 0;
}
