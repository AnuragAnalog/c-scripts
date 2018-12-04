#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
enum boolean {FALSE, TRUE};
enum boolean scmp(char str1[], char str2[]);
int slen(char str1[]);

/******** MAIN STARTS HERE *********/
int main(void)
{
   int        len1, len2;
   char       str1[MAX+1], str2[MAX+1];

   enum boolean status;

   printf("Enter the first string: ");
   scanf("%s", str1);

   len1 = slen(str1);

   if (len1 > 32)
   {
      printf("Enter the string which is <= 32 characters.\n");
      exit(1);
   }

   printf("Enter the string to be compared: ");
   scanf("%s", str2);

   len2 = slen(str2);

   if (len2 > 32)
   {
      printf("Enter the string which is <= 32 characters.\n");
      exit(1);
   }

   if (len1 != len2)
   {
      printf("The given strings are not of equal length\n");
      printf("Give strings of equal length then I can compare.\n");
      exit(2);
   }

   status = scmp(str1, str2);
   printf("Strings are %s", status?"equal":"not equal");
   printf("\n");
   exit(0);
}

/********* FUNCTION DEFINITION *********/
enum boolean scmp(char str1[], char str2[])
{
   int        i = 0;

   while (str1[i] != '\0' && str2[i] != '\0')
   {
      if (str1[i] == str2[i])
      {
         i = i + 1;
      }
      else
      {
         return 0 ;
      }
   }

   if (str1[i] == '\0' && str2[i] == '\0')
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int slen(char str1[])
{
   int        i = 0;

   while (str1[i] != '\0')
   {
      i = i + 1;
   }
   return i;
}
