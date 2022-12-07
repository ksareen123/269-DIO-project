#include "msp.h"
int main()
{
//where RED LED on port 1(p1.0) is HIGH if button 1 (s1 p1.1) is pressed
P1 ->SEL0 &=~0x03;  //0000 0011
P1 ->SEL1 &=~0x03;
P1 ->DIR |= 0x01; //led output
P1 ->DIR &= ~0x02; //button input
P1 ->REN |= 0x02;
P1 ->OUT |= 0x02; //pull up
while(1)
{
if((P1 -> IN & 0x02) != 0)
{
//is button not pressed
P1 -> OUT &= ~0x01; //LED OFF
}
else
{
P1 ->OUT |= 0x01;
}
}
}