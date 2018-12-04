#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********* FUNCTION DECLARATION *********/
int randno(int num);
enum boolean {HEAD = 0, TAIL};

/********* MAIN STARTS HERE *********/
int main(void)
{
   int            num = time(NULL);
   enum boolean   randnum;

   randnum = randno(num);

   if (randnum < 0)
   {
      randnum = (-1) * randnum;
   }

   printf("You got a %s\n", randnum?"TAIL":"HEAD");

   exit(0);
}

/********* FUNCTION DECLARATION *********/
int randno(int num)
{
   num = num * 1103515245 + 12345;
   return (num/65536) % 2;
}
