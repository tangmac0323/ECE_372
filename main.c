/* 
 * File:   main.c
 * Author: Megntao Tang
 * Description: lab 0.
 * Created on Feb 4th 2016
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

//TODO: Define states of the state machine

typedef enum stateTypeEnum {
    led1, state1, led2, state2, led3, state3
} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType state =led1;
volatile int account = 0;

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock

    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    initTimer1();
    initTimer2();
    //This function is necessary to use interrupts. 
    enableInterrupts();


    while (1) {

        //TODO: Implement a state machine to create the desired functionality
        switch (state) 
        {
            case led3:
                turnOnLED(3);
            break;

            case led2:
                turnOnLED(2);
            break;

            case led1:
                turnOnLED(1);
            break;         
        }

    }

    return 0;
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS)_CNInterrupt(){
    IFS1bits.CNDIF=0;
    int i =0;
    i=PORTD;
    if (PORTDbits.RD6 == 1){
        LATDbits.LATD0=1;
    }
    else{
        LATDbits.LATD0=0;
    }
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS)_T1Interrupt() 
{
    IFS0bits.T1IF = 0;
    if (state ==led1){
        state =led2;
    }
    else if (state ==led2){
        state = led3;
    }
    else if (state == led3){
        state = led1;
    }
}

