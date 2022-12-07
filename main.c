#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "msp.h"
#include "functions.h"


int main(void) {
  //initialize stuff
	setup();
	//printtest();
	//print("54");
	temp_setup();
	setupLED();
	init_input();
	
  int choice = 0;
	int readings;
  //printprompt();
  //print prompt
  while (1) {
    printprompt();
		char c_choice[20];
		scan(c_choice);
		choice = atoi(c_choice);
		print(c_choice);
		print("\r");
		char response[30];
    switch(choice) {
      case 1: // RGB
				//print("you have selected RGB input!\n\r");
        RGB_input();
				print("Done");
        break;
      case 2:
        digital_input();
        break;
      case 3:
				print("\nEnter number of Temperature Readings (1-5):");
				char readings_c[20];
				scan(readings_c);
				print("\n\r");
				readings = atoi(readings_c);
				print("\n\r");
				//temp_display(readings);
				char display[20];
				for (int i = 1; i <= readings; i++) {
						temp_display(i, display);
						print(display);
				}
        break;
    }
    choice = 0;
  }
  return 0;
	
}
