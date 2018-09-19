#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int printi(char *strp1, char *strp2);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        val;
   char       *strp1 = NULL, *strp2 = NULL;
   char       str1[MAX+1], str2[MAX+1];

   printf("Enter the first string: ");
   scanf("%s", str1);
   strp1 = &str1[0];

   printf("Enter the second string: ");
   scanf("%s", str2);
   strp2 = &str2[0];

   val = printi(strp1, strp2);

   if (val == -1)
   {
      printf("\n");
      printf("No character of %s is present in %s\n", str2, str1);
      exit(0);
   }
   else
   {
      printf("\n");
      printf("The location of %c in first string is %d\n", str1[val-1], val);
      exit(0);
   }
   exit(0);
}

/********* FUNCTION DEFINITION *********/
int printi(char *strp1, char *strp2)
{
   int         i = 0, j = 0;

   for (j = 0; *(strp2+j) != '\0'; j++)
   {
      for (i = 0; *(strp1+i) != '\0'; i++)
      {
         if (*(strp2+j) == *(strp1+i))
         {
            return i+1;
         }
      }
   }

   return -1;
}

