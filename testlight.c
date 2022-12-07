#include "msp.h"

void delay(int t);

int main() {
	P1->SEL0 &= ~0x01;
	P1->SEL1 &= ~0x01;
	
	P1->DIR |= 0x01;
	P1->OUT &= 0x01;
	
	while(1) {
		P1->OUT |= 0x01;
		delay(300);
		P1->OUT &= ~0x01;
		delay(500); 
	}
}

void delay(int t) {
	int i, j;
	for (i = 0; i < 1000; i++) {
		for (j = 0;j < t; j++) {
		}
	}
}