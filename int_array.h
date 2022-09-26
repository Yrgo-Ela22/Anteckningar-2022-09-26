/********************************************************************************
* int_array.h: Inneh�ller funktionalitet f�r tilldelning och utskrift av
*              arrayer inneh�llande heltal (int-arrayer).
********************************************************************************/
#ifndef INT_ARRAY_H_
#define INT_ARRAY_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* int_array_assign: Tilldelar heltal i stigande ordning till array av angiven
*                   storlek. Det f�rsta v�rdet som l�ggs till �r alltid 0.
*
*                      - self: Pekare till arrayen som skall tilldelas.
*                      - size: Arrayens storlek (antalet heltal den rymmer).
********************************************************************************/
void int_array_assign(int* self,
                      const int size);

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
                     FILE* ostream);

#endif /* INT_ARRAY_H_ */