#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "take_readings.c"
#include "msp.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H



void setup() {
	EUSCI_A0 -> CTLW0 |= 1;
	EUSCI_A0 -> MCTLW = 0;
	EUSCI_A0 -> CTLW0 |= 0x80; // 1 stop bit, no parity, using small clock 10, 8-bit data
	EUSCI_A0 -> BRW = 26;
	P1->SEL0 |= 0x0C;
	P1->SEL1 &= ~0x0C;
	EUSCI_A0 -> CTLW0 &= ~0x01;
}

void print(char sentence[]) {
	int i = 0;
	while (sentence[i] != 0) {
		EUSCI_A0 -> TXBUF = sentence[i];
		while ((EUSCI_A0 -> IFG & 2) == 0) {
		}
		i++;
	}
}

void scan() {
	
}

void printprompt() {
  printf("\n");
  printf("\nMSP 432 Menu \n");
  printf("\n");
  
  //prompt begins
  printf("1. RBG Control\n");
  printf("2. Digital Input\n");
  printf("3. Temperature Reading\n");
}

// option 1 functions
void blink(int RGB, int toggle_time, int num_blinks) {
  printf("Blinking LED:\n");
  printf("blinking with %d color, %d time, %d blinks", RGB, toggle_time, num_blinks);
}
void RGB_input() {
  int RGB;
  int toggle_time;
  int num_blinks;
  printf("Enter Combination of RGB (1-7):");
  scanf("%d", &RGB);
  printf("Enter Toggle Time:");
  scanf("%d", &toggle_time);
  printf("Enter Number of Blinks:");
  scanf("%d", &num_blinks);
  blink(RGB, toggle_time, num_blinks);
}

//option 2 functions
void digital_input() {
  printf("will work on this later.\n");
}

//option 3 functions
void temp_reading() {
  int readings;
  printf("Enter number of Temperature Readings (1-5):");
  scanf("%d", &readings);
  printf("finding %d readings\n", readings);
}

#endif