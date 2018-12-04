#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********* FUNCTION DECLARATION *********/
int randno(int num);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int       num = time(NULL), randnum;

   randnum = randno(num);

   if (randnum < 0)
   {
      randnum = (-1) * randnum;
   }
   else if (randnum == 0)
   {
      randnum = 3;
   }

   printf("Your number is %d\n", randnum);

   exit(0);
}

/********* FUNCTION DECLARATION *********/
int randno(int num)
{
   num = num * 1103515245 + 12345;
   return (int) (num/65536) % 7;
}
