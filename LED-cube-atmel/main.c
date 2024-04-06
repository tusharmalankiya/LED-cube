/*
 * LED-cube-atmel.c
 *
 * Created: 4/6/2024 1:48:12 PM
 * Author : Tushar Malankiya
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

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


// Define the animation patterns for each layer
uint8_t patterns[][3] = {
	{0b11111110, 0b11111100, 0b11111000}, // Layer 0: All LEDs off
	{0b11110000, 0b11100000, 0b11000000}, // Layer 1: All LEDs off
	{0b10000000, 0b00000000, 0b11111111}, // Layer 2: All LEDs off
};

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


// Function to display a layer pattern
void displayLayer(uint8_t layer) {
	LAYER_PORT = (LAYER_PORT & ~LAYER_MASK) | (1 << layer); // Select the layer
	
	// Output the pattern for the selected layer
	for (int i = 0; i < 3; i++) {
		if(i == 2 && layer == 2){
			ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
			_delay_ms(100);
			continue;
		}
		COLUMN_PORT = patterns[layer][i];
		_delay_ms(100); // Adjust the delay as needed for brightness
	}
}


int main(void) {
	initLEDs(); // Initialize LED pins
	
	while (1) {
		// Display each layer in sequence to create animation
		for (int layer = 0; layer < 3; layer++) {
			displayLayer(layer);
			_delay_ms(1); // Adjust the delay to control animation speed
		}
		reset_pins();
	}
	
	return 0;
}
