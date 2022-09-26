/********************************************************************************
* main.c: Blinkning av lysdiod ansluten till pin 6 p� Arduino Uno, vilket f�r
*         mikrodator ATmega328P motsvarar PORTD6. F�r att g�ra koden mer l�sbar
*         samt g�ra det enklare byte pin-nummer utan att �ndra en massa 
*         parametrar anv�nds makrot LED, som motsvarar heltalet 6. Detta makro
*         ers�tt med motsvarande v�rde 6 innan kompileringen �ger rum.
*
*         Samtliga pinnar p� Arduino Uno �r ansluta till n�got av de tre
*         I/O-portarna B, C eller D:
*
*         Digitala pinnar 0 - 7 tillh�r I/O-port D (PORTD0 - PORTD7).
*         Digitala pinnar 8 - 13 tillh�r I/O-port B (PORTB0 - PORTD5).
*         Analoga pinnar A0 - A5 tillh�r I/O-port C (PORTC0 - PORTC5).
*
*         Tre typer av register anv�nds f�r respektive I/O-port:
*
*         1. Datariktningsregister DDRB, DDRC samt DDRD anv�nds f�r att v�lja
*            datariktning f�r en given pin, d�r 1 = utport och 0 = inport.
*
*         2. Portregister PORTB, PORTC samt PORTD anv�nds f�r att skriva till
*            en given utport, d�r 1 = h�g och 0 = l�g. Dessa register anv�nds
*            ocks� f�r att aktivera interna pullup-resistorer f�r inportar,
*            vilket g�rs f�r digitala inportar s� att insignalen alltid blir
*            0 (l�g) eller 1 (h�g).
*
*         3. Pinregister PINB, PINC samt PIND anv�nds f�r att l�sa av insignalen
*            fr�n en given pin (normalt en inport), d�r 1 = h�g och 0 = l�g.
*         
*         F�r att s�tta lysdioden till utport ettst�lls bit 6 i datariktnings-
*         regiter DDRD (Data Direction Register D) via bitvis skiftning.
*         DDRD = (1 << 6) inneb�r att v�rdet 0100 0000 skrivs till detta
*         register, vilket g�r lysdiodens pin 6 till enda utport. I detta
*         program anv�nds makrot LED i st�llet f�r 6, vilket medf�r att
*         instruktionen skrivs som DDRD = (1 << LED);
* 
*         F�r att t�nda lysdioden ettst�lls bit 6 i port-register PORTB
*         via makrot LED_ON, som �r ekvivalent med PORTD = (1 << LED), d�r
*         LED �r lika med 6. Notera att detta makro medf�r att andra eventuella
*         pinnar hade sl�ckts, d� dessa tilldelas en nolla. I framtiden kommer
*         bitvis OR |= (t�nk bitvis addition) anv�ndas f�r att ettst�lla en
*         vis bit utan att p�verka �vriga bitar, exempelvis PORTD |= (1 << LED);
*
*         F�r att sl�cka lysdioden nollt�lls bit 6 i port-register PORTB
*         via makrot LED_OFF, som �r ekvivalent med PORTD = 0. Notera att detta 
*         makro nollst�ller samtliga bitar i registret, vilket hade sl�ckt
*         �vriga pinnar. I framtiden kommer bitvis AND &= (t�nk bitvis 
*         multiplikation) kombinerat med negation ~ (t�nk bitvis invertering)
*         anv�ndas f�r att nollst�lla en vis bit utan att p�verka �vriga bitar, 
*         exempelvis PORTD &= ~(1 << LED);
* 
*         F�r att generera f�rdr�jning anv�nds funktionen _delay_ms fr�n
*         biblioteket util/delay.h, som tar emot f�rdr�jningstiden i ms som
*         ett heltal. Innan detta bibliotek importeras m�ste mikrodatorns
*         klockfrekvens definieras via makrot F_CPU. Eftersom mikrodatorn
*         i detta fall har en klockfrekvens p� 16 MHz (via en oscillator p�
*         mikrokontrollerkortet Arduino Uno) s�tts detta makro till ekvivalent
*         med 16000000UL. UL indikerar att detta heltal har datatypen 
*         unsigned long (en 32-bitars osignerad heltalstyp), vilket �r tillr�ckligt
*         stort f�r detta tal (en vanlig int �r endast 16-bitar i detta system, vilket
*         medf�r tal mellan -32 768 till 32 767, allts� alldeles f�r lite f�r ett s�dant
*         stort tal. Genom att l�gga till UL ser vi till att v�rdet p� 
*         klockfrekvensen inte trunkeras / f�rkortas till en regulj�r int.
********************************************************************************/
/* Klockfrekvens: */
#define F_CPU 16000000UL /* 16 MHz klockfrekvens. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Inkluderar bibliotek med information om I/O-portar s�som DDRD. */
#include <util/delay.h> /* Inkluderar bibliotek f�r att generera f�rdr�jning. */

/* Makrodefinitioner: */
#define LED 6                     /* Lysdiod ansluten till PIN 6. */
#define LED_ON PORTD = (1 << LED) /* T�nder lysdioden. */
#define LED_OFF PORTD = 0         /* Sl�cker lysdioden. */

/********************************************************************************
* main: S�tter lysdiodens pin till utport. D�refter s�tts lysdioden till att
*       blinka kontinuerligt var 100 ms s� l�nge matningssp�nning tillf�rs.
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

