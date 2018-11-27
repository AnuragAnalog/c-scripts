#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
void primes(int n);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
    int        n;

    if (argc != 2)
    {
       fprintf(stderr, "Usage: %s <number>.\n", argv[0]);
       exit(1);
    }

    n = atoi(argv[1]);

    primes(n);
    exit(0);
}

/********* FUNCTION DEFINITION ********/
void primes(int n)
{
   int        i, j, check ;

   printf("The primes between 2 and %d(%d exclusive) are: ", n, n);
   for (i = 2; i < n; i++)
   {
      check = 0;
      for (j = 1; j < i+1; j++)
      {
         if (i%j == 0)
         {
            check = check + 1;
         }
      }
      if (check == 2)
      {
         printf("%d ", i);
      }
   }
   printf("\n");

   return ;
}
