/* 
 * File:   led.c
 * Author: Mengtao Tang
 * Description: lab 0.
 * Created on Feb 4th 2016
 */
#include <xc.h>
#include "led.h"

#define OUTPUT 0
#define INPUT 1

void initLEDs(){
    TRISDbits.TRISD0=OUTPUT;
    TRISDbits.TRISD1=OUTPUT;
    TRISDbits.TRISD2=OUTPUT;
    //TODO: Initialize LEDs
}

void turnOnLED(int led){
    if(led == 1)
    {
        LATDbits.LATD0=1;
        LATDbits.LATD1=0;
        LATDbits.LATD2=0;
    }
    else if(led == 2)
    {
        LATDbits.LATD0=0;
        LATDbits.LATD1=1;
        LATDbits.LATD2=0;
    }
    else
    {
        LATDbits.LATD0=0;
        LATDbits.LATD1=0;
        LATDbits.LATD2=1;
    }
    //TODO: You may choose to write this function
    // as a matter of convenience
    
}