/*
 * File:   glcd_trail.c
 * Author: Srihari Koripalli
 *
 * Created on 16 June, 2017, 11:23 AM
 */


#define _XTAL_FREQ 16000000
#include <xc.h>
#include <Custom_Headers/config45k22.h>
#include <Custom_Headers/glcd.h>

void main(void) {
    int i;
    ANSELB = 0; //Analog select B
    ANSELD = 0;
    glcd_on();
    glcd_clear();
    __delay_ms(1000);
    while(1)
    {
        for(int i=0; i<8; i++)
        {
         glcd_clear();   
         goto_xy(0,i);
         glcd_string("HELLO!..");
         __delay_ms(1000);
         
        }
        for(int i=0; i<8; i++)
        {
         glcd_clear();   
         goto_xy(65,i);
         glcd_string("HELLO!..");
         __delay_ms(1000);
         
        }
        
    }
    return;
}
