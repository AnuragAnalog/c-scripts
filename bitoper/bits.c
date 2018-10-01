#include <stdio.h>
#include <stdlib.h>
#include "bitop.h"

/********* MAIN STARTS HERE *********/
int main(void)
{
   int             option, num;
   unsigned        setc, seta = 0, setb = 0;
   char            file1[MAX+1], file2[MAX+1];
   FILE            *fp1 = NULL, *fp2 = NULL;

   enum boolean memb;

   option = menu();

   switch (option)
   {
      case 1:
             printf("\n *** Union *** \n");
             seta = set2bit(fp1, file1);
             print_bits(seta);
             setb = set2bit(fp2, file2);
             if (setb == 0)
             {
                printf("The union of two sets is SetA.\n");
                bit2set(seta);
                exit(0);
             }
             print_bits(setb);
             setc = union_bit(seta, setb);
             printf("The union of two sets is: \n");
             bit2set(setc);
             break;
       case 2:
             printf("\n *** Intersection *** \n");
             seta = set2bit(fp1, file1);
             if (seta == 0)
             {
                printf("The Intersection of two sets is { }.\n");
                exit(0);
             }

             print_bits(seta);
             setb = set2bit(fp2, file2);
             if (setb == 0)
             {
                printf("The Intersection of two sets is { }.\n");
                exit(0);
             }

             print_bits(setb);
             setc = inter_bit(seta, setb);
             printf("The intersection of two sets is: \n");
             bit2set(setc);
             break;
       case 3:
             printf("\n *** Membership *** \n");
             seta = set2bit(fp1, file1);
             if (seta == 0)
             {
                printf("No values are in the set to search.\n");
                exit(0);
             }

             print_bits(seta);

             printf("Enter the number to be searched in the set: ");
             scanf("%d", &num);
             memb = membership_bit(seta, num);
             printf("%d is the %s of the set.\n", num, memb?"MEMBER":"NOT A MEMBER");
             break;
       case 4:
             printf("\n *** Difference *** \n");
             seta = set2bit(fp1, file1);
             if (seta == 0)
             {
                printf("The Difference of two sets is { }.\n");
                exit(0);
             }

             print_bits(seta);
             setb = set2bit(fp2, file2);
             if (seta == 0)
             {
                printf("The Difference of two sets is SetA.\n");
                bit2set(seta);
                exit(0);
             }

             print_bits(setb);
             setc = diff_bit(seta, setb);
             printf("The difference of two sets is: \n");
             bit2set(setc);
             break;
       case 5:
             printf("You have come out from the program successfully.\n");
             exit(0);
       default :
               break;
   }

   exit(0);
}
