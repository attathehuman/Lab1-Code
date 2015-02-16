// ******************************************************************************************* //
//
// File:         lab1p1.c
// Date:         
// Authors:      
//
// Description: Part 1 for lab 1
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "leds.h"
#include "timer.h"
#include <stdio.h>


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

// ******************************************************************************************* //


typedef enum stateTypeEnum{
    ledRun, ledStop
}stateType;

volatile stateType currentState;

int main(void)
{

    //Initialize Functions
    initLEDs();
    initTimer1();
    initSW2();
    initCN();

    //Turn on LEDRUN initially
    LEDRUN = ON;

    
    while(1)
    {
        switch (currentState){
            case ledRun: turnOnLed(4); break;
            case ledStop: turnOnLed(7); break;
        }

        
        //TODO: Using a finite-state machine, define the behavior of the LEDs
        //Debounce the switch
    }
    
    return 0;
}

void _ISR _T1Interrupt(void){
    IFS0bits.T1IF = 0;//Put down timer 1 flag

}


void _ISR _CNInterrupt(void){
    IFS1bits.CNIF = 0;

    //TODO: Implement the interrupt to capture the press of the button
    if (SW2 == 0) delayUs(5);  // Turn the timer 1 on
    
   
    
    if(SW2 == 1) {
        delayUs(5);
        if (currentState == ledRun) currentState = ledStop;
        else if (currentState == ledStop) currentState = ledRun;
    }

    if (currentState == ledRun) currentState = ledStop;
    else if (currentState == ledStop) currentState = ledRun;
    

}