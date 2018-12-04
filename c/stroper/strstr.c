#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define  MAX        32

/********* FUNCTION DECLARATION *********/
int sub_str(char *str1, char *str2);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int       len1, len2;
   char      *str1, *str2;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
      exit(1);
   }

   str1 = argv[1];
   str2 = argv[2];

   len1 = strlen(str1);
   len2 = strlen(str2);

   if (len1 < len2)
   {
      printf("second string should be smaller than the first string.\n");
      exit(2);
   }

   len2 = sub_str(str1, str2);

   if (len2 == strlen(str2))
   {
      printf("%s is the sub-string of %s\n", str2, str1);
   }
   else
   {
      printf("%s is not a sub-string of %s\n", str2, str1);
   }

   exit(0);
}

int sub_str(char *str1, char *str2)
{
   int        i = 0, j = 0, l = 0, len = 0;

   while (str1[i] != '\0' && str2[j] != '\0')
   {
      if (str1[i] == str2[j])
      {
         i = i + 1, j = j + 1;
         len = len + 1;
      }
      else
      {
         l = l + 1, j = 0;
         i = l, len = 0;
      }
   }

   return len;
}
