/********************************************************************************
* repetition.c: Repetitionsuppgift innefattande skrivning och l�sning av arrayer
*               samt skrivning till fil.
*
*               F�r att l�sa inneh�llet i en given fil, klicka Tools ->
*               Command Line -> Developer Command Prompt. Skriv sedan in
*               kommandot "type" f�ljt av filnamnet. Som exempel, inneh�llet i
*               filen numbers.txt kan l�sas via f�ljande kommando:
*
*               $ type numbers.txt
*
*               Observera att dollartecknet enbart anv�nds f�r att indikera
*               att det r�r sig om ett termiankommando och skall inte skrivas.
********************************************************************************/
#include "int_array.h"

/********************************************************************************
* main: Fyller array med 50 heltal 0 - 49. Arrayens inneh�ll skrivs sedan ut i
*       terminalen, f�ljt av skrivning till filen numbers.txt.
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
