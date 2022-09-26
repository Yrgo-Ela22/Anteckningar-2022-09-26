# Anteckningar 2022-09-26
Introduktion till hårdvarunära C-programmering samt repetition av arrayer samt filpekare.

Filen main.c innehåller ett enkelt C-program där en lysdiod ansluten till pin 6 / PORTD6 sätts
till att blinka var 100:e millisekund. Här finns också information om olika I/O-register på mikrodator
ATmega328P.

Filerna repetition.c, int_array.h samt int_array.c innehåller den repetitionsuppgift som genomfördes, där en
statisk array som rymmer 50 heltal tilldelas heltal 0 - 49, vilket skrivs ut både i konsolen samt 
skrivs till en fil döpt numbers.txt. Detta genomfördes via funktionen main i filen repetition.c via anrop
av funktioner specifikt skapade för int-arrayer. Funktionerna för implementering av int-arrayer deklareras 
i filen int_array.h och definieras i filen int_array.c.