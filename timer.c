/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include "p24fj64ga002.h"
#include "timer.h"

#define FCY 14745600.0
#define TIME_DELAY 57



//uses timer 1

void initTimer1(){ // Timer with a 5ms delay
    //TODO: Initialize the timer
    unsigned int prVal = (FCY*TIME_DELAY)/256.0 - 1;
    PR1 = prVal;
    T1CONbits.TCKPS = 0b11; //prescalar 256
    IEC0bits.T1IE = 1; // Enable the interrupt
    IFS0bits.T1IF = 0; // Put the interrupt flag down
}




//Uses timer 2
void delayUs(unsigned int delay){
    //TODO: Create a delay using timer 2 for "delay" microseconds.
    TMR2 = 0; //According to the datasheet this should be reset automatically, but it does not sometimes.
    PR2 = delay*TIME_DELAY; //Period register value calculated from lecture
    T2CONbits.TCKPS = 0b11; //prescalar 256
    IFS0bits.T2IF = 0; // Timer 2 interrupt flag down
    T2CONbits.TON = 1; // Turn timer 2 on


    // Wait until the timer 2 interrupt flag goes up. This is done in hardware.
    while(IFS0bits.T2IF == 0);

    IFS0bits.T2IF = 0; // Put the flag down afterwards.
    T2CONbits.TON = 0; // Turn the timer off so it does not keep counting.

}