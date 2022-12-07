#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "msp.h"
#include "colors.h"

#ifndef INPUT_H
#define INPUT_H

void setup_buttons() {
	P1 ->SEL0 &= ~0x12;
	P1 ->SEL1 &= ~0x12;
	P1 ->DIR &= ~0x12;
	P1 ->REN |= 0x12;
	P1 ->OUT |= 0x12;
}
void init_input() {
	setup_buttons();
}

	
int dig_input() {
	int i = 0;
	int option = 0;
	if ((P1 ->IN & 0x10) == 0 && (P1 ->IN & 0x02) == 0) {
		P2 ->OUT &= ~0x03;
		P2 ->OUT &= ~0x05;
		P2 ->OUT &= ~0x01;
		P2 ->OUT |= 0x04;
		option = 3;
	}
	else if ((P1 ->IN & 0x02) == 0){
		P2 ->OUT &= ~0x04;
		P2 ->OUT &= ~0x05;
		P2 ->OUT &= ~0x01;
		P2 ->OUT |= 0x03;
		option = 1;
	}
	else if ((P1 ->IN & 0x10) == 0) {
		P2 ->OUT &= ~0x03;
		P2 ->OUT &= ~0x04;
		P2 ->OUT &= ~0x01;
		P2 ->OUT |= 0x05;
		option = 2;
	}
	else {
		P2 ->OUT &= ~0x03;
		P2 ->OUT &= ~0x04;
		P2 ->OUT &= ~0x05;
		P2 ->OUT |= 0x01;
		
		option = 4;
	}
	return option;
}

#endif
