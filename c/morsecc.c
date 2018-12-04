#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        64

/********* FUNCTION DECLARATION *********/
void morse_fill(char *morse[]);
void morse_gen(char *str, char *morse[]);
void alphanum(char *str);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   char       *morse[MAX];
   char       *str;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <string>\n", argv[0]);
      exit(1);
   }

   str = argv[1];

   alphanum(str);

   morse_fill(morse);
   morse_gen(str, morse);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void morse_fill(char *morse[])
{
   int        i = 0;

   morse[0] = ".-";
   morse[1] = "-...";
   morse[2] = "-.-.";
   morse[3] = "-..";
   morse[4] = ".";
   morse[5] = "..-.";
   morse[6] = "--.";
   morse[7] = "....";
   morse[8] = "..";
   morse[9] = ".---";
   morse[10] = "-.-";
   morse[11] = ".-..";
   morse[12] = "--";
   morse[13] = "-.";
   morse[14] = "---";
   morse[15] = ".--.";
   morse[16] = "--.-";
   morse[17] = ".-.";
   morse[18] = "...";
   morse[19] = "-";
   morse[20] = "..-";
   morse[21] = "...-";
   morse[22] = ".--";
   morse[23] = "-..-";
   morse[24] = "-.--";
   morse[25] = "--..";
   morse[26] = ".----";
   morse[27] = "..---";
   morse[28] = "...--";
   morse[29] = "....-";
   morse[30] = ".....";
   morse[31] = "-....";
   morse[32] = "--...";
   morse[33] = "---..";
   morse[34] = "----.";
   morse[35] = "-----";

   for (i = 36; i < 63; i++)
   {
      morse[i] = morse[i-36];
   }

   return ;
}

void morse_gen(char *str, char *morse[])
{
   int        ind;

   while (*str != '\0')
   {
      if (*str >= 'A' && *str <= 'Z')
      {
         ind = (*str - 'A');
         printf("%s ", morse[ind]);
      }
      else if (*str >= '0' && *str <= '9')
      {
         ind = (*str - ('@' - '*'));
         printf("%s ", morse[ind]);
      }
      else if (*str >= 'a' && *str <= 'z')
      {
         ind = (*str - 'a');
         printf("%s ", morse[ind]);
      }

      str++;
   }
   printf("\n");

   return ;
}

void alphanum(char *str)
{
   int        check = 0, len;

   len = strlen(str);

   while (*str != '\0')
   {
      if (*str >= 'A' && *str <= 'Z')
      {
         check = check + 1;
      }
      else if (*str >= '0' && *str <= '9')
      {
         check = check + 1;
      }
      else if (*str >= 'a' && *str <= 'z')
      {
         check = check + 1;
      }

      str++;
   }

   if (len != check)
   {
      printf("The given string is not a alphanumeric string.\n");
      printf("Enter only alphanumeric string.\n");
      exit(2);
   }

   return ;
}
