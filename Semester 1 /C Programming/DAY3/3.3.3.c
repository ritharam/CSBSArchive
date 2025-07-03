// Sequence 3
#include <stdio.h>
int main() {
   int i, j, k;
   printf("Haritha R\t126018017\n");
   for (i = 1; i<=3; ++i) 
   {
      for (j=1;j<=3-i;++j)
      {
         printf(" ");
      }
      for (k=0;k!=2*i-1;k++)
      {
         printf("*");
      }
      printf("\n");
   }
   return 0;
}
