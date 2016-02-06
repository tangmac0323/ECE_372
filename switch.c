/* 
 * File:   switch.c
 * Author: Mengtao Tang
 * Description: lab 0.
 * Created on Feb 4th 2016
 */
 
#include <xc.h>
#define OUTPUT 0
#define INPUT 1

void initSwitch1(){
    //TODO: Initialize switch 1
    TRISDbits.TRISD6=1;
    
    CNCONDbits.ON=1;
    IEC1bits.CNDIE=1;
    CNENDbits.CNIED6=1;
    
    IFS1bits.CNDIF=0;
    CNPUDbits.CNPUD6=1;
}