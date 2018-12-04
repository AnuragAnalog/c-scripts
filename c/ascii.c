#include <stdio.h>
#include <stdlib.h>

/********* MAIN STARTS HERE *********/
int main()
{
   char       cha;

   printf("Enter a character: ");
   cha = getchar();

   printf("The ascii value of %c is %d\n", cha, cha);
   exit(0);
}
