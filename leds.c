/*
* File:   leds.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "leds.h"


void initLEDs(){

    //opendrain collector for the outputs
    ODCAbits.ODA0 = 1;
    ODCAbits.ODA1 = 1;
    //TODO: Initialize the appropriate pins to work with the LEDs
   
    //Defines pins as outputs
    TRISAbits.TRISA0 = 0; 
    TRISAbits.TRISA1 = 0;


    LEDSTOP = OFF;
    LEDRUN = OFF;
}

void turnOnLed(int led){

    if(led == 4){ //turn on led4
        LEDRUN = ON;
        LEDSTOP = OFF;
    }

    else if(led == 7){//turn on led7
        LEDRUN = OFF;
        LEDSTOP = ON;
    }
}

void initCN(){
    IFS1bits.CNIF = 0; //flag down
    IEC1bits.CNIE = 1;//Enables the overall change notification interrupt
    CNEN1bits.CN6IE = 1; //CN interrupt for SW2
}

void initSW2(){
    //TODO: Initialize the appropriate pins to work with the external switch using a
    //change notification interrupt.

    TRISBbits.TRISB2 = 1; // SW2 is output
    AD1PCFGbits.PCFG4 = 1; // I/O conversion
    CNPU1bits.CN6PUE = 1; //pull down resistor
}



 