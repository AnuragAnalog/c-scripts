#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int printi(char str1[], char str2[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        val;
   char       str1[MAX+1], str2[MAX+1];

   printf("Enter the first string: ");
   scanf("%s", str1);

   printf("Enter the second string: ");
   scanf("%s", str2);

   val = printi(str1, str2);

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
int printi(char str1[], char str2[])
{
   int         i = 0, j = 0;

   for (j = 0; str2[j] != '\0'; j++)
   {
      for (i = 0; str1[i] != '\0'; i++)
      {
         if (str2[j] == str1[i])
         {
            return i+1;
         }
      }
   }

   return -1;
}

