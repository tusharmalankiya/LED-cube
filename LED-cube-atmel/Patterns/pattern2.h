
#ifndef PATTERN2_H_
#define PATTERN2_H_

#include "./../Includes/atmega32.h"
#include <util/delay.h>


// Define the animation patterns for each layer
uint8_t patterns2[][3] = {
	{0b11111110, 0b11110110, 0b10110110}, // Layer 0: All LEDs off
	{0b00110110, 0b00100110, 0b00100100}, // Layer 1: All LEDs off
	{0b00100000, 0b00000000, 0b11111111}, // Layer 2: All LEDs off
};

uint8_t patterns2_blink[][3] = {
	{0b11111110, 0b11110111, 0b10111111}, // Layer 0: All LEDs off
	{0b01111111, 0b11101111, 0b11111101}, // Layer 1: All LEDs off
	{0b11111011, 0b11011111, 0b11111111}, // Layer 2: All LEDs off
};


void pattern2(void){
	for (int j = 0; j < 3; j++) {
		LAYER_PORT = 0b00000111;
		// Output the pattern for the selected layer
		for (int i = 0; i < 3; i++) {
			if(i == 2 && j == 2){
				ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
				_delay_ms(100);
				continue;
			}
			COLUMN_PORT = patterns2[j][i];
			_delay_ms(100); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();
}

void pattern2_blink(void){
	for (int j = 0; j < 3; j++) {
		LAYER_PORT = 0b00000111;
		// Output the pattern for the selected layer
		for (int i = 0; i < 3; i++) {
			if(i == 2 && j == 2){
				ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
				_delay_ms(100);
				ColUMN_LAST_PIN_PORT |= (1 << PINC0);
				continue;
			}
			COLUMN_PORT = patterns2_blink[j][i];
			_delay_ms(100); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();
}



#endif /* PATTERN2_H_ */