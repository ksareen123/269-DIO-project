#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "msp.h"

#ifndef COLORS_H
#define COLORS_H

void delay(float delay) {
	//delay
	SysTick ->LOAD = (delay * 3000000) - 1; //delay 1.5 secs
	SysTick ->CTRL |= 0x01; //enable counter
	while((SysTick ->CTRL & 0x10000) == 0) {
		//do nothing
	}		
	SysTick ->CTRL &=~0x01; //disable counter
	SysTick ->VAL = 0;
	return;
}

void setupLED() {
	//where RED LED on port 1(p1.0) is HIGH if button 1 (s1 p1.1) is pressed
	P2 ->SEL0 &=~0x07;  //0000 0011
	P2 ->SEL1 &=~0x07;
	P2 ->DIR |= 0x07; //led output
	P2 ->OUT &= ~0x07;
		
	SysTick -> CTRL |= 0x04; // set clk source, no inter., disabled
}

void blk(float d, int color) {
	P2 ->OUT |= color;
	//P2 ->OUT &= ~0x04;
	delay(d);
	P2 ->OUT &= ~color;
	//P2 ->OUT |= 0x04;
	delay(d);
}
	
void run_blink(int color, float d, int iter) {
	for (int i = 0; i < iter; i++){ 
		blk(d, color);
	}
}

#endif
	