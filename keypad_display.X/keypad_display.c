/*
 * File:   keypad_display.c
 * Author: Srihari Koripalli
 *
 * Created on 20 June, 2017, 1:39 PM
 */

#include <xc.h>
#define _XTAL_FREQ 16000000
#include <Custom_Headers/glcd.h> //locate the header file on your PC

unsigned char keyscan();

int main() {
ANSELA=0;
TRISA = 0b00000111;
LATA = 0b1111100;
glcd_on();
glcd_clear();
goto_xy(0,0);
glcd_string("PRESSED");

while(1)
{
    LATA = 0xFF;
    goto_xy(0,20);
    glcd_num(keyscan());
    __delay_ms(1000);
    glcd_clear_line(1);
}
return 0;
}

unsigned char keyscan()
{
    while(1)
    {
        //LATA =0x00;
        LATA = 0b00110000;
        __delay_ms(5);
        if((PORTA & 0b00110001) == 0)
        {
            while(!(PORTA & 0b00110001));
            return '0';
        }
        
        if((PORTA & 0b00110010) == 0)
        {
            while(!(PORTA & 0b00110010));
            return '1';
        }
        
        if((PORTA & 0b00110100) == 0)
        {
            while(!(PORTA & 0b00110100));
            return '2';
        }
        
        if((PORTA & 0b00001000) == 0)
        {
            while(!(PORTA & 0b00001000));
            return '3';
        }
    }
}
