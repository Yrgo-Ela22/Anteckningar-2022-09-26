/********************************************************************************
* repetition.c: Repetitionsuppgift innefattande skrivning och läsning av arrayer
*               samt skrivning till fil.
*
*               För att läsa innehållet i en given fil, klicka Tools ->
*               Command Line -> Developer Command Prompt. Skriv sedan in
*               kommandot "type" följt av filnamnet. Som exempel, innehållet i
*               filen numbers.txt kan läsas via följande kommando:
*
*               $ type numbers.txt
*
*               Observera att dollartecknet enbart används för att indikera
*               att det rör sig om ett termiankommando och skall inte skrivas.
********************************************************************************/
#include "int_array.h"

/********************************************************************************
* main: Fyller array med 50 heltal 0 - 49. Arrayens innehåll skrivs sedan ut i
*       terminalen, följt av skrivning till filen numbers.txt.
********************************************************************************/
int main(void)
{
   int a1[50];
   FILE* ostream = fopen("numbers.txt", "w");

   int_array_assign(a1, 50);
   int_array_print(a1, 50, stdout);
   int_array_print(a1, 50, ostream);
   fclose(ostream);

   return 0;
}
