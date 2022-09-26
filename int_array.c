/********************************************************************************
* int_array.c: Inneh�ller funktionsdefinitioner f�r tilldelning samt utskrift
*              av arrayer inneh�llande heltal (int-arrayer).
********************************************************************************/
#include "int_array.h"

/********************************************************************************
* int_array_assign: Tilldelar heltal i stigande ordning till array av angiven
*                   storlek. Det f�rsta v�rdet som l�ggs till �r alltid 0.
*
*                      - self: Pekare till arrayen som skall tilldelas.
*                      - size: Arrayens storlek (antalet heltal den rymmer).
********************************************************************************/
void int_array_assign(int* self,
                      const int size)
{
   for (int i = 0; i < size; ++i)
   {
      self[i] = i;
   }

   return;
}

/********************************************************************************
* int_array_print: Skriver ut heltal lagrade i array via angiven utstr�m, d�r
*                  standardutenhet stdout anv�nds som default f�r utskrift i
*                  terminalen.
*
*                  - self: Pekare till arrayen vars inneh�ll skall skrivas ut.
*                  - size: Arrayens storlek (antalet heltal den rymmer).
*                  - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void int_array_print(const int* self,
                     const int size,
                     FILE* ostream)
{
   if (!ostream) ostream = stdout;
   fprintf(ostream, "--------------------------------------------------------------------------------\n");

   for (int i = 0; i < size; ++i)
   {
      fprintf(ostream, "%d\n", self[i]);
   }

   fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
   return;
}
