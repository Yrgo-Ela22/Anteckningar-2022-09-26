/********************************************************************************
* main.c: Blinkning av lysdiod ansluten till pin 6 på Arduino Uno, vilket för
*         mikrodator ATmega328P motsvarar PORTD6. För att göra koden mer läsbar
*         samt göra det enklare byte pin-nummer utan att ändra en massa 
*         parametrar används makrot LED, som motsvarar heltalet 6. Detta makro
*         ersätt med motsvarande värde 6 innan kompileringen äger rum.
*
*         Samtliga pinnar på Arduino Uno är ansluta till något av de tre
*         I/O-portarna B, C eller D:
*
*         Digitala pinnar 0 - 7 tillhör I/O-port D (PORTD0 - PORTD7).
*         Digitala pinnar 8 - 13 tillhör I/O-port B (PORTB0 - PORTD5).
*         Analoga pinnar A0 - A5 tillhör I/O-port C (PORTC0 - PORTC5).
*
*         Tre typer av register används för respektive I/O-port:
*
*         1. Datariktningsregister DDRB, DDRC samt DDRD används för att välja
*            datariktning för en given pin, där 1 = utport och 0 = inport.
*
*         2. Portregister PORTB, PORTC samt PORTD används för att skriva till
*            en given utport, där 1 = hög och 0 = låg. Dessa register används
*            också för att aktivera interna pullup-resistorer för inportar,
*            vilket görs för digitala inportar så att insignalen alltid blir
*            0 (låg) eller 1 (hög).
*
*         3. Pinregister PINB, PINC samt PIND används för att läsa av insignalen
*            från en given pin (normalt en inport), där 1 = hög och 0 = låg.
*         
*         För att sätta lysdioden till utport ettställs bit 6 i datariktnings-
*         regiter DDRD (Data Direction Register D) via bitvis skiftning.
*         DDRD = (1 << 6) innebär att värdet 0100 0000 skrivs till detta
*         register, vilket gör lysdiodens pin 6 till enda utport. I detta
*         program används makrot LED i stället för 6, vilket medför att
*         instruktionen skrivs som DDRD = (1 << LED);
* 
*         För att tända lysdioden ettställs bit 6 i port-register PORTB
*         via makrot LED_ON, som är ekvivalent med PORTD = (1 << LED), där
*         LED är lika med 6. Notera att detta makro medför att andra eventuella
*         pinnar hade släckts, då dessa tilldelas en nolla. I framtiden kommer
*         bitvis OR |= (tänk bitvis addition) användas för att ettställa en
*         vis bit utan att påverka övriga bitar, exempelvis PORTD |= (1 << LED);
*
*         För att släcka lysdioden nolltälls bit 6 i port-register PORTB
*         via makrot LED_OFF, som är ekvivalent med PORTD = 0. Notera att detta 
*         makro nollställer samtliga bitar i registret, vilket hade släckt
*         övriga pinnar. I framtiden kommer bitvis AND &= (tänk bitvis 
*         multiplikation) kombinerat med negation ~ (tänk bitvis invertering)
*         användas för att nollställa en vis bit utan att påverka övriga bitar, 
*         exempelvis PORTD &= ~(1 << LED);
* 
*         För att generera fördröjning används funktionen _delay_ms från
*         biblioteket util/delay.h, som tar emot fördröjningstiden i ms som
*         ett heltal. Innan detta bibliotek importeras måste mikrodatorns
*         klockfrekvens definieras via makrot F_CPU. Eftersom mikrodatorn
*         i detta fall har en klockfrekvens på 16 MHz (via en oscillator på
*         mikrokontrollerkortet Arduino Uno) sätts detta makro till ekvivalent
*         med 16000000UL. UL indikerar att detta heltal har datatypen 
*         unsigned long (en 32-bitars osignerad heltalstyp), vilket är tillräckligt
*         stort för detta tal (en vanlig int är endast 16-bitar i detta system, vilket
*         medför tal mellan -32 768 till 32 767, alltså alldeles för lite för ett sådant
*         stort tal. Genom att lägga till UL ser vi till att värdet på 
*         klockfrekvensen inte trunkeras / förkortas till en reguljär int.
********************************************************************************/
/* Klockfrekvens: */
#define F_CPU 16000000UL /* 16 MHz klockfrekvens. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Inkluderar bibliotek med information om I/O-portar såsom DDRD. */
#include <util/delay.h> /* Inkluderar bibliotek för att generera fördröjning. */

/* Makrodefinitioner: */
#define LED 6                     /* Lysdiod ansluten till PIN 6. */
#define LED_ON PORTD = (1 << LED) /* Tänder lysdioden. */
#define LED_OFF PORTD = 0         /* Släcker lysdioden. */

/********************************************************************************
* main: Sätter lysdiodens pin till utport. Därefter sätts lysdioden till att
*       blinka kontinuerligt var 100 ms så länge matningsspänning tillförs.
********************************************************************************/
int main(void)
{
    DDRD = (1 << LED); 

    while (1) 
    {
       LED_ON;         
       _delay_ms(100); 
       LED_OFF; 
       _delay_ms(100); 
    }

    return 0;
}

