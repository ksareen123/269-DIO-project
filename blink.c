#include <stdlib.h>
#include <stdio.h>
#include "msp.h"
//Program to cycle through all the RGB LED colors
void delay(void); //delay some time
int blink(void)
{
P2 ->SEL0 &= ~0x07;
P2 ->SEL1 &= ~0x07;
P2 -> DIR |= 0x07;
P2 ->OUT &=~0x07; //set all LEDs OFF
while(1)
{
int i = 0;
while(i < 8)
{
P2 ->OUT |= i; //turn on LED
delay();
P2 -> OUT &= ~i; //turn off LED
i++;
}
i = 0;
}
}
void delay(void)
{
int x = 0;
while(x < 1000000)
{
x++;
}
return;
}