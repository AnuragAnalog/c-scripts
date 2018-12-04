#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX1       32
#define   MAX2       64

/********* FUNCTION DECLARATION *********/
void sccat(char str1[], char str2[], char str3[]);
int slen(char str1[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   char       str1[MAX1+1], str2[MAX1+1], str3[MAX2+1];
   int        len1, len2;

   printf("Enter the first string: ");
   scanf("%s", str1);

   len1 = slen(str1);

   if (len1 > 32)
   {
      printf("Enter the string which is <= 32 characters.\n");
      exit(1);
   }

   printf("Enter the second string: ");
   scanf("%s", str2);

   len2 = slen(str2);

   if (len2 > 32)
   {
      printf("Enter the string which is <= 32 characters.\n");
      exit(1);
   }

   sccat(str1, str2, str3);

   printf("The concatenated string is: %s\n", str3);
   exit(0);
}

/********* FINCTION DEFINITION *********/
void sccat(char str1[], char str2[], char str3[])
{
   int        N3 = 0, i = 0, j = 0;

   while (str1[i] != '\0')
   {
      str3[N3] = str1[i];
      N3 = N3 + 1;
      i = i + 1;
   }

   while (str2[j] != '\0')
   {
      str3[N3] = str2[j];
      N3 = N3 + 1;
      j = j + 1;
   }
   return ;
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
