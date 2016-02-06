/* 
 * File:   timer.c
 * Author: Mengtao Tang
 * Description: lab 0.
 * Created on Feb 4th 2016
 */

#include <xc.h>

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    T1CONbits.TCKPS=3;//init Prescalar
    TMR1=0;//clear TMR1
    PR1=24441;//initialize PR1
    IEC0bits.T1IE=1;//enable the interrupt
    IFS0bits.T1IF=0;//put the flag down
    IPC1bits.T1IP=7;//configure the interrupt
    T1CONbits.TON=1;//turn the time on
    T1CONbits.TCS=0;
}

void initTimer2(){
    //TODO: Initialize Timer 2.
    TMR2=0;//clear timer2
    T2CONbits.TCKPS=0;
    T2CONbits.TCS=0;
    IFS0bits.T2IF=0;//flag
}

void delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
    TMR2=0;
    PR2=delay*624;
    IFS0bits.T2IF=0;
    T2CONbits.ON=1;
    while(IFS0bits.T2IF==0);
    T2CONbits.ON=0;
}

void resetTimer1(){
    TMR1 = 0;
    T1CONbits.ON = 0;
}