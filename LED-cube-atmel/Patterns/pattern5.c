#include "patterns.h"

// Define the animation patterns for each layer
uint8_t patterns5[][3] = {
	{0b11111110, 0b11111100, 0b11111000}, // Layer 0: All LEDs off
	{0b11011000, 0b11011000, 0b01011000}, // Layer 1: All LEDs off
	{0b00011000, 0b00010000, 0b00000000}, // Layer 2: All LEDs off
};

uint8_t patterns5_blink[][3] = {
	{0b11111110, 0b11111101, 0b11111011}, // Layer 0: All LEDs off
	{0b11011111, 0b11111111, 0b01111111}, // Layer 1: All LEDs off
	{0b10111111, 0b11110111, 0b11101111}, // Layer 2: All LEDs off
};


void pattern5(void){
	for (int j = 0; j < 3; j++) {
		LAYER_PORT = 0b00000111;
		// Output the pattern for the selected layer
		for (int i = 0; i < 3; i++) {
			if(i == 1 && j == 1){
				ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
				_delay_ms(100);
				continue;
			}
			COLUMN_PORT = patterns5[j][i];
			_delay_ms(100); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();
}

void pattern5_blink(void){
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
			COLUMN_PORT = patterns5_blink[j][i];
			_delay_ms(100); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();
}

