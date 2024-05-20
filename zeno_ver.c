
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char
cleanup                 (char a_rce)
{
   char        x_cmd       [200] = "";
   if (a_rce < 0)  printf ("(n/a)\n", a_rce);
   snprintf (x_cmd, 200, "rm -f version.txt");
   system (x_cmd);
   return a_rce;
}

char
main                    (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_cmd       [200] = "";
   FILE       *f           = NULL;
   char        x_recd      [200] = "";
   char       *p           = NULL;
   char       *r           = NULL;
   /*---(extract version)----------------*/
   snprintf (x_cmd, 200, "grep \"P_VERNUM\" y*.h > version.txt  2> /dev/null");
   rc = system (x_cmd);
   --rce;  if (rc != 0)         return cleanup (rce);
   /*---(read in)------------------------*/
   f = fopen ("version.txt", "rt");
   --rce;  if (f == NULL)       return cleanup (rce);
   fgets (x_recd, 200, f);
   --rce;  if (strstr (x_recd, "P_VERNUM") == NULL)  { fclose (f);  return cleanup (rce); }
   fclose (f);
   /*---(parse)--------------------------*/
   p = strtok_r (x_recd, "\"", &r);
   --rce;  if (p == NULL)       return cleanup (rce);
   p = strtok_r (NULL  , "\"", &r);
   --rce;  if (p == NULL)       return cleanup (rce);
   --rce;  if (strlen (p) != 4) return cleanup (rce);
   /*---(save back)----------------------*/
   printf ("%c %c %c\n", p [0], p [2], p [3]);
   /*---(clean-up)-----------------------*/
   cleanup (0);
   /*---(complete)-----------------------*/
   return 0;
}


