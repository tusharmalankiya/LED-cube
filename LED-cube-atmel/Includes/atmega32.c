#include "atmega32.h"

void reset_pins(void){
	//set layer pins off
	LAYER_PORT = 0b00000000;
	
	//set column pins on
	COLUMN_PORT = 0b11111111;
	ColUMN_LAST_PIN_PORT = 0b00000001;
	
}

// Function to initialize the LED cube pins
void initLEDs(void) {
	LAYER_DDR = LAYER_MASK; // Set layer pins as output
	
	COLUMN_DDR = COLUMN_MASK; // Set column pins as output
	ColUMN_LAST_PIN_DDR = COLUMN_LAST_PIN_MASK; // set 9th column pin as output
	
	reset_pins();
	
}

