#include "patterns.h"

// Define the animation patterns for each layer
uint8_t patterns6[][3] = {
	{0b11101111, 0b11100111, 0b10100111}, // Layer 0: All LEDs off
	{0b00100111, 0b1111111, 0b00000111}, // Layer 1: All LEDs off
	{0b00000011, 0b00000001, 0b00000000}, // Layer 2: All LEDs off
};

uint8_t patterns6_blink[][3] = {
	{0b11101111, 0b11110111, 0b10111111}, // Layer 0: All LEDs off
	{0b01111111, 0b11111111, 0b11011111}, // Layer 1: All LEDs off
	{0b11111011, 0b11111101, 0b11111110}, // Layer 2: All LEDs off
};


void pattern6(void){
	for (int j = 0; j < 3; j++) {
		LAYER_PORT = 0b00000111;
		// Output the pattern for the selected layer
		for (int i = 0; i < 3; i++) {
			if(i == 1 && j == 1){
				ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
				_delay_ms(100);
				continue;
			}
			COLUMN_PORT = patterns6[j][i];
			_delay_ms(100); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();
}

void pattern6_blink(void){
	for (int j = 0; j < 3; j++) {
		LAYER_PORT = 0b00000111;
		// Output the pattern for the selected layer
		for (int i = 0; i < 3; i++) {
			if(i == 1 && j == 1){
				ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
				_delay_ms(100);
				ColUMN_LAST_PIN_PORT |= (1 << PINC0);
				continue;
			}
			COLUMN_PORT = patterns6_blink[j][i];
			_delay_ms(100); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();
}

