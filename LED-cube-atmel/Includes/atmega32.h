

#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#define F_CPU 16000000UL

#include <avr/io.h>

// Define the pins connected to the layers and columns of the LED cube

//layer
#define LAYER_PORT PORTA
#define LAYER_DDR DDRA
#define LAYER_MASK 0x07 // Assuming layers connected to PB0-PB2

//column
#define COLUMN_PORT PORTB
#define COLUMN_DDR DDRB
#define COLUMN_MASK 0xFF // Assuming columns connected to all of PORTD

#define ColUMN_LAST_PIN_PORT PORTC //9th column pin
#define ColUMN_LAST_PIN_DDR DDRC
#define COLUMN_LAST_PIN_MASK 0x01


void reset_pins(){
	//set layer pins off
	LAYER_PORT = 0b00000000;
	
	//set column pins on
	COLUMN_PORT = 0b11111111;
	ColUMN_LAST_PIN_PORT = 0b00000001;
	
}

// Function to initialize the LED cube pins
void initLEDs() {
	LAYER_DDR = LAYER_MASK; // Set layer pins as output
	
	COLUMN_DDR = COLUMN_MASK; // Set column pins as output
	ColUMN_LAST_PIN_DDR = COLUMN_LAST_PIN_MASK; // set 9th column pin as output
	
	reset_pins();
	
}


#endif /* ATMEGA32_H_ */