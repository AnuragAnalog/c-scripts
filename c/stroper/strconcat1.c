#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX1        32
#define   MAX2        64

/********* FUNCTION DECLARATION *********/
void sconcat(int len, char str2[], char str1[]);
int slen(char str1[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   char       str1[MAX2+1], str2[MAX1+1];
   int        len1, len2;

   printf("Enter the first string: ");
   scanf("%s", str1);

   len1 = slen(str1);

   if (len1 > 64)
   {
      printf("Enter the string which is <= 64 characters.\n");
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

   if (len1 + len2 > 64)
   {
      printf("\n");
      printf("Exceeded the capacity os the first string\n");
      printf("!! CONCATENATION NOT POSSIBLE !!\n");
      exit(2);
   }

   sconcat(len1, str2, str1);
   printf("\n");
   printf("The concatneated string: %s\n", str1);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void sconcat(int len1, char str2[],char str1[])
{
   int        i = 0, j = 0;

   i = len1;

   while (str2[j] != '\0')
   {
      str1[i] = str2[j];
      i = i + 1;
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
