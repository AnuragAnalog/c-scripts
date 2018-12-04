#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define   MAX         32

/********* FUNCTION DECLARATION *********/
int strcmpc(char *str1, char *str2);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   char        *str1, *str2;
   int         len1, len2, length = 0;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
      exit(1);
   }

   str1 = argv[1];
   str2 = argv[2];

   len1 = strlen(str1);
   len2 = strlen(str2);

   if (len1 != len2)
   {
      fprintf(stderr, "Both the given strings are not equal.\n");
      fprintf(stderr, "Because both are of unequal lengths.\n");
      exit(2);
   }

   length = strcmpc(str1, str2);

   if (len1 == length)
   {
      printf("The given strings are equal irrespective of the case.\n");
   }
   else
   {
      printf("Given strings are not equal.\n");
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
int strcmpc(char *str1, char *str2)
{
   int        len = 0, i = 0;
   char       str[MAX];

   while (*str1 != '\0' && *str2 != '\0')
   {
      if (*str1 == *str2)
      {
         len = len + 1;
      }
      else
      {
         str[i] = *str1 - ('a'-'A');
         if (*str == *str2)
         {
            len = len + 1;
            i++;
         }
         else
         {
            return len;
         }
      }

      str1++, str2++;
   }

   return len;
}
