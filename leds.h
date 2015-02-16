/* 
* File:   leds.h
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#ifndef LEDS_H
#define	LEDS_H
#define LEDSTOP LATAbits.LATA1
#define LEDRUN LATAbits.LATA0
#define SW2 PORTBbits.RB2

#define OFF 1
#define ON 0


void initLEDs();
void initSW2();
void turnOnLed();
void initCN();


#endif	/* LEDS_H */

