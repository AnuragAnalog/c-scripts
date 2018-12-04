#include <stdio.h>
#include <stdlib.h>
#include "bitop.h"

/******** FUNCTION DEFINITION *********/
int menu()
{
   int        opt;
   char       check;
   
   printf("\tSET OPERATIONS\t\n");
   printf("Select a option:-\n");
   printf("    1) Union of Sets\n\n");
   printf("    2) Intersection of Sets\n\n");
   printf("    3) Membership of Sets\n\n");
   printf("    4) Difference of Sets\n\n");
   printf("    5) exit\n");

   printf("Your option please: ");
   scanf("%d", &opt);

   if ((opt > 0) && (opt < 6))
   {
      return opt;
   }
   else
   {
      printf("\nSelect from the below options\n");
      menu();
   }
}

unsigned setbit(unsigned x, int p)
{
   return ((1 << p) | x);
}

unsigned getbit(unsigned x, int p)
{
   return ((x >> p) & 1);
}

unsigned clearbit(unsigned x, int p)
{
   return ((~(1 << p)) & x);
}

enum boolean isbitset(unsigned x, int p)
{
   return ((1 << p) & x);
}

/******* SET OPERATIONS *******/
/***** UNION *****/
unsigned union_bit(unsigned x, unsigned x1)
{
   int             i;
   unsigned        seta, setb, x3 = 0;

   for (i = 0; i < MAX; i++)
   {
      seta = getbit(x, i);
      setb = getbit(x1, i);

      if ((seta == 0) && (setb == 0))
      {
         x3 = clearbit(x3, i);
      }
      else
      {
         x3 = setbit(x3 , i);
      }
   }

   return x3;
}

/***** INTERSECTION *****/
unsigned inter_bit(unsigned x, unsigned x1)
{
   int             i;
   unsigned        seta, setb, x3 = 0;

   for (i = 0; i < MAX; i++)
   {
      seta = getbit(x, i);
      setb = getbit(x1, i);

      if ((seta == 1) && (setb == 1))
      {
         x3 = setbit(x3, i);
      }
      else
      {
         x3 = clearbit(x3, i);
      }
   }

   return x3;
}

/***** MEMBERSHIP *****/
enum boolean membership_bit(unsigned x, int num)
{
      return ((1 << num) & x);
}

/***** DIFFERENCE *****/
unsigned diff_bit(unsigned x, unsigned x1)
{
   int             i;
   unsigned        seta, setb, x3 = 0;

   for (i = 0; i < MAX; i++)
   {
      seta = getbit(x, i);
      setb = getbit(x1, i);

      if ((seta == 1) && (setb == 1))
      {
         x3 = clearbit(x3, i);
      }
      else if ((seta == 1) && (setb == 0))
      {
         x3 = setbit(x3, i);
      }
      else
      {
         x3 = clearbit(x3, i);
      }
   }

   return x3;
}

unsigned set2bit(FILE *fp1, char file1[])
{
   int             num;
   char            eof;
   unsigned        x1 = 0;

   printf("Enter the file name which contains set: \n");
   scanf("%s", file1);

   fp1 = fopen(file1, "r");

   if (fp1 == NULL)
   {
      fprintf(stderr, "Error in opening file %s.\n", file1);
      exit(1);
   }
   eof = fgetc(fp1);

   if (eof == EOF)
   {
      printf("You have entered a NULL set.\n");
      return 0;
   }

   rewind(fp1);
   while (fscanf(fp1, "%d", &num) != EOF)
   {
      if (num < 0 || num > 31)
      {
         printf("Values should be in the range of [0, 31].\n");
         exit(2);
      }
      x1 = setbit(x1, num);
   }

   return x1;
}

void print_bits(unsigned seta)
{
   unsigned      pb;
   int           i;

   for (i = 0; i < MAX; i++)
   {
      pb = getbit(seta, i);
      printf("%u ", pb);
   }

   printf("\n\n");
   return ;
}

int bit2set(unsigned setc)
{
   int        i;
   enum boolean bitval;

   printf("{ ");
   for (i = 0; i < MAX; i++)
   {
      bitval = isbitset(setc, i);

      if (bitval)
      {
         printf("%d ", i);
      }
   }

   printf("}\n");
   return 0;
}

