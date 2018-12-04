#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX       32 

/********* FUNCTION DECLARATION *********/
int slen(char src[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   char        src[MAX+1];
   int         len;

   printf("Enter the string: ");
   scanf("%s", src);

   if (src[0] == '\0')
   {
      printf("Enter a string.\n");
      exit(1);
   }

   len = slen(src);
   printf("The length of the string is %d\n", len);
   exit(0);
}

/******** FUNCTION DEFINITION *********/
int slen(char src[])
{
   int        i = 0;

   while (src[i] != '\0')
   {
      i = i + 1;
   }
   return i;
}
