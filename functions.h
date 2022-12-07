#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "msp.h"
#include "temp.h"
#include "colors.h"
#include "input.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void setup() {
	EUSCI_A0 -> CTLW0 |= 0x01;
	EUSCI_A0 -> MCTLW = 0;
	EUSCI_A0 -> CTLW0 |= 0x80; // 1 stop bit, no parity, using small clock 10, 8-bit data
	EUSCI_A0 -> BRW = 26;
	P1->SEL0 |= 0x0C;
	P1->SEL1 &= ~0x0C;
	EUSCI_A0 -> CTLW0 &= ~0x01;
	
}

void printtest() {
	EUSCI_A0 -> TXBUF = '!';
	while ((EUSCI_A0 -> IFG & 0x02) == 0) {
		//wait 
	}
	return;
}

void print(char sentence[]) {
	int i = 0;
	while (sentence[i] != 0) {
		EUSCI_A0 -> TXBUF = sentence[i];
		while ((EUSCI_A0 -> IFG & 2) == 0) {
			//wait
		}
		i++;
	}
}


void scan(char x[20]) {
	int i = 0;
	while (1) {
		if ((EUSCI_A0 ->IFG & 1) != 0) {
			x[i] = EUSCI_A0 ->RXBUF;
			EUSCI_A0 ->TXBUF = x[i];
			while ((EUSCI_A0 ->IFG & 2) == 0) {
				// wait state
			}
			if (x[i] == '\r') {
				x[i] = '\0';
				i = 0;
				break;
			}
			else {
				i++;
			}
		}
		else {
			//wait 
		}
	}
}


void printprompt() {
  print("\n\r");
  print("\nMSP 432 Menu \n\r");
  print("\n\r");
  
  //prompt begins
  print("1. RGB Control\n\r");
  print("2. Digital Input\n\r");
  print("3. Temperature Reading\n\r");
}

// option 1 functions
void blink(int RGB, int toggle_time, int num_blinks) {
	print("Blinking LED...\n\r");
  //sprintf(words, "blinking LED"with %d color, %d time, %d blinks", RGB, toggle_time, num_blinks);
	run_blink(RGB, toggle_time, num_blinks);
	//print(words);
}
void RGB_input() {
  int RGB;
  int toggle_time;
  int num_blinks;
  print("\nEnter Combination of RGB (1-7):");
	char color[10];
  scan(color);
	print(color);
	print("\n\r");
	RGB = atoi(color);
  print("Enter Toggle Time:");
	char toggle[10];
  scan(toggle);
	print(toggle);
	print("\n\r");
	toggle_time = atof(toggle);
  print("Enter Number of Blinks:");
	char blinks[10];
  scan(blinks);
	print(blinks);
	print("\n\r");
	num_blinks = atoi(blinks);
  blink(RGB, toggle_time, num_blinks);
}


//option 2 functions
void digital_input() {
	int op = dig_input();
	switch(op) {
		case (1):
			print("Button 1 Pressed");
			break;
		case (2):
			print("Button 2 Pressed");
			break;
		case (3):
			print("Buttons 1 and 2 Pressed");
			break;
		case (4):
			print("None Pressed");
			break;
	}
}



#endif
