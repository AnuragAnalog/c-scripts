#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
void scopy(char dest[], char src[]);
int slen(char src[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   char       dest[MAX+1], src[MAX+1];
   int        len = 0;

   printf("Enter the string to be copied: ");
   scanf("%s", src);

   len = slen(src);

   if (len > 32)
   {
      printf("Enter the string which is <= 32 characters.\n");
      exit(1);
   }

   scopy(dest, src);
   printf("The string you have copied is: %s", dest);
   printf("\n");
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void scopy(char dest[], char src[])
{
   int        i = 0;

   while (src[i] != '\0')
   {
      dest[i] = src[i];
      i = i + 1;
   }
   dest[i] = '\0';
   return;
}

int slen(char src[])
{
   int        i = 0;

   while (src[i] != '\0')
   {
      i = i + 1;
   }
   return i;
}
