#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX       32

/********* FUNCTION DECLARATION *********/
enum boolean {FALSE, TRUE};
enum boolean schar(char str[], char cha[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   char       str[MAX+1], c;

   enum boolean status;

   printf("Enter the string: ");
   scanf("%s", str);

   printf("Enter the character to be searched: ");
   c = getchar(); 

   status = schar(str, c);

   printf("Status = %s", status?"FOUND":"NOT FOUND");
   exit(0);
}

/********* FUNCTION DEFINITION *********/
enum boolean schar(char str[], char c[])
{
   int        i = 0;

   while (str[i] != '\0')
   {
      if (str[i] == c)
      {
         return 1;
      }
      i = i + 1;
   }
   return 0;
}
