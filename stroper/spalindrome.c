#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX       32

/********* FUNCTION DECLARATION *********/
enum boolean {FALSE, TRUE};
int slen(char str[]);
int spalin(char str[], int len);

/********* MAIN STARTS HERE **********/
int main(void)
{
   char       str[MAX+1];
   int        len;

   enum boolean status;

   printf("Enter the string: ");
   scanf("%s", str);

   len = slen(str);

   if (len == 1)
   {
      printf("You have only entered one character.\n");
      printf("It is a palindrome.\n");
      exit(1);
   }
   else if (len > 32)
   {
      printf("Enter a string which is <= 32 characters.\n");
      exit(2);
   }

   status = spalin(str, len);
   printf("%s is %s\n", str, status?"PALINDROME":"NOT A PALINDROME");
   exit(0);
}

/********* FUNCTION DECLRATION *********/
int slen(char str[])
{
   int        i = 0;

   while (str[i] != '\0')
   {
      i = i + 1;
   }
   return i;
}

int spalin(char str[], int len)
{
   int        i = 0;

   while (i < len/2 || i < (len+1)/2)
   {
      if (str[i] == str[len-1-i])
      {
         i = i + 1;
      }
      else
      {
         return 0;
      }
      i = i + 1;
   }
   return 1;
}
