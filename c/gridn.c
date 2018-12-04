#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********* DEFINED CONSTANTS *********/
#define   MAX         50

/********* FUNCTION DECLARATION *********/
void gridn(int n, int ngrid[][MAX]);
int randnum(int n);
int randno(int n);
void delay();

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        n;
   int        ngrid[MAX][MAX];

   printf("Enter the value of n: ");
   scanf("%d", &n);

   printf("Preparing your %dX%d grid\n", n, n);
   gridn(n, ngrid);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void gridn(int n, int ngrid[][MAX])
{
   int        i, j, k = 0, num, index = 1;
   int        check[MAX];

   check[0] = randnum(n);

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (i == 0 && j == 0)
         {
            ngrid[i][j] = check[0];
         }
         else
         {
            while (k < index)
            {
               if (k == 0)
               {
                  delay();
                  num = randnum(n);
               }

               if (num == check[k])
               {
                  k = -1;
               }
               k++;
            }
            check[index++] = num;
            ngrid[i][j] = num;
            k = 0;
         }
      }
   }

   printf("Your %dX%d is ready....\n", n, n);
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         printf("%d  ", ngrid[i][j]);
      }
      printf("\n");
   }

   return ;
}

int randno(int n)
{
   int       sqr = n*n;
   time_t    num = time(NULL);

   num = num * 1103515245 + 12345;
   return (int) ((num/65536) % sqr);
}

int randnum(int n)
{
   int         num = randno(n);

   if (num < 0)
   {
      num = (-1) * num;
   }

   return num+1;
}

void delay()
{
   int            ms = 1;
   clock_t        start = clock();

   while (clock() < start+ms);

   return ;
}
