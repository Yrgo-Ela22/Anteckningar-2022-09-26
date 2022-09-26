/********************************************************************************
* int_array.c: Innehåller funktionsdefinitioner för tilldelning samt utskrift
*              av arrayer innehållande heltal (int-arrayer).
********************************************************************************/
#include "int_array.h"

/********************************************************************************
* int_array_assign: Tilldelar heltal i stigande ordning till array av angiven
*                   storlek. Det första värdet som läggs till är alltid 0.
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
* int_array_print: Skriver ut heltal lagrade i array via angiven utström, där
*                  standardutenhet stdout används som default för utskrift i
*                  terminalen.
*
*                  - self: Pekare till arrayen vars innehåll skall skrivas ut.
*                  - size: Arrayens storlek (antalet heltal den rymmer).
*                  - ostream: Pekare till angiven utström (default = stdout).
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
