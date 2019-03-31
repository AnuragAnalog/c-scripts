#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define MAX         50

/********* FUNCTION DECLARATION *********/
void magic_square(int m, int k, int d, int msq[][MAX]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i, j, m, k, d, msum = 0;
   int        msq[MAX][MAX];

   printf("Enter the order of the matix: ");
   scanf("%d", &m);

   printf("Enter the First term: ");
   scanf("%d", &k);

   printf("Enter the common difference: ");
   scanf("%d", &d);

   if (m%2 == 0 || m <= 0)
   {
       printf("Invalid dimension for the matrix.\n");
       exit(1);
   }

   magic_square(m, k, d, msq);
   
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < m; j++)
      {
         if (i == j)
         {
            msum = msum + msq[i][j];
         }
         printf("%d ", msq[i][j]);
      }
      printf("\n");
   }
   printf("\nMagic sum is %d.\n", msum);

   return 0;
}

/********* FUNCTION DEFINITION *********/
void magic_square(int m, int k, int d, int msq[][MAX])
{
   int           i, j, pr, pc, r, c, check = 1, term = k;

   pr = (int) m/2, pc = m-1;

   for (i = 0; i < m; i++)
   {
      for (j = 0; j < m; j++)
      {
         msq[i][j] = -1;
      }
   }

   msq[pr][pc] = k, term = k;
   while (check != m*m)
   {
      term = term + d;
      r = pr-1, c = pc+1;

      if ((r >= 0 && r < m) && (c >= 0 && c < m) && msq[r][c] == -1)
      {
         msq[r][c] = term;
      }
      else if ((r >= 0 && r < m) && (c >= 0 && c < m) && msq[r][c] != -1)
      {
         c = c - 2;
         r = r + 1;
         msq[r][c] = term;
      }
      else if ((r >= 0 && r < m) && (c < 0 || c >= m))
      {
          c = 0;
          msq[r][c] = term;
      }
      else if ((r < 0 || r >= m) && (c >= 0 && c < m))
      {
         r = m-1;
         msq[r][c] = term;
      }
      else if ((r < 0 || r >= m) && (c < 0 || c >= m))
      {
         r = r+1;
         c = c-2;
         msq[r][c] = term;
      }
      check = check + 1;
      pr = r, pc = c;
   }

   return ;
}
