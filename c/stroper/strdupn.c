#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
char *strdupn(char *str, int n);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        n, len;
   char       *str, *strn;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <string> <length>\n", argv[0]);
      exit(1);
   }

   str = argv[1];
   n = atoi(argv[2]);

   strn = strdupn(str, n);
   printf("%s", strn);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
char *strdupn(char *str, int n)
{
   int        i;
   char       *nstr = NULL;

   for (i = 0; i < n; i++)
   {
      *nstr = *str;
      nstr++, str++;
   }

   return nstr;
}
