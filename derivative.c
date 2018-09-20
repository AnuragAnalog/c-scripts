/****************** Usage: For finding the smallest real root of any given Polynomial equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and their corresponding powers as the input and computes the smallest real root for the given polynomial equation using Ramanujan's method *****************/

/*************** Given Equation: Any polynomial Equation **************/

/**************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32
#define   ERR        0.001

/********* FUNCTION DECLARATION *********/
void swapi(int *a, int *b);
void swapf(double *a, double *b);
void bubble_sort(int expo[], double coeff[], int nitems);
void derivative1(double coeff[], int nitems, int expo[], float x);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, nitems = 0; //Declaration of variables in int
   int        expo[MAX];         //Declaration of arrays in int
   char       co[MAX], ex[MAX];  //Declaration of arrays in char
   double     x;                 //Declaration of variables in double
   double     coeff[MAX];        //Declaration of arrays in double

   printf("Enter the co-efficients and it's corresponding powers as input if a corresponding co-efficient is not there then enter ZERO as the co-efficient.\nIf you are done by entering the polynomial terms then type any lower case letter to terminate the input process.\n\n");

   while (1)  //Infinte Loop
   {
      printf("Enter the co-effient: ");
      scanf("%s", co);
      if (*co >= 'a' && *co <= 'z')  //Check condition
      {
         break;
      }

      printf("Enter it's corresponding power: ");
      scanf("%s", ex);
      if (*ex >= 'a' && *ex <= 'z')  //Check condition
      {
         fprintf(stderr, "These values for powers can't be accepted as inputs.\n");
         exit(2);
      }
      printf("\n");

      coeff[i] = atof(co);  //Converting input
      expo[i] = atoi(ex);   //Converting input

      i++;  //Incrementing i
      nitems++;  //Incrementing nitems
   }

   bubble_sort(expo, coeff, nitems);  //Calling Function

   printf("Enter the value of x:- ");
   scanf("%lf", &x);

   derivative1(coeff, nitems, expo, x);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void derivative1(double coeff[], int nitems, int expo[], float x)
{
   int          i = 0, j, k = 1;
   double       fh, fx, deriv, powh, powx, err = 0.001;

   while (i < nitems-1 && expo[i] != 0)
   {
      powh = powf(x+ERR, expo[i]-1);
      powx = powf(x, expo[i]-1);
      printf("%lf %lf\n", powh, powx);
      printf("%d\n", expo[i]);
      fh = fh + (expo[i] * coeff[i] * powh);
      fx = fx + (expo[i] * coeff[i] * powx);
      i++;
   }

   deriv = (fh - fx)/(err);
   printf("%f\n", deriv);

   return ;
}

void bubble_sort(int expo[], double coeff[], int nitems)
{
   int        i, j;  //Declaration of variables in int

   for (i = 0; i < nitems; i++)
   {
      for (j = 0; j < (nitems-i-1); j++)
      {
         if (expo[j+1] > expo[j])  //Check condition
         {
            swapi(&expo[j+1], &expo[j]);    //Swaping items
            swapf(&coeff[j+1], &coeff[j]);  //Swaping items
         }
      }
   }

   return ;
}

void swapi(int *a, int *b)
{
   int        temp;  //Declaration of variables in int

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}

void swapf(double *a, double *b)
{
   double        temp;  //Declaration of variables in double

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}
