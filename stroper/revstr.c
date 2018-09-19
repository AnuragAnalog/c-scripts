#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        N = 0, i = 0, j;
   char       str[MAX+1], revstr[MAX+1];

   printf("Enter the string: ");
   scanf("%s", str);

   while (str[i] != '\0')
   {
      N = N + 1;
      i = i + 1;
   }

   for (j = 0; j < N; j++)
   {
      revstr[j] = str[N-1-j];
   }
   revstr[j+1] = '\0';

   printf("The reverse of the string entered is: %s\n", revstr);
   exit(0);
}
