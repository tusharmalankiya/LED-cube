/*
 * LED-cube-atmel.c
 *
 * Created: 4/6/2024 1:48:12 PM
 * Author : Tushar Malankiya
 */ 

#include "Includes/atmega32.h"
#include "Patterns/pattern1.h"

#include <util/delay.h>



int main(void) {
	initLEDs(); // Initialize LED pins
	
	while (1) {
		// Display each layer in sequence to create animation
		pattern1();
	}
	
	return 0;
}
