

#ifndef PATTERN3_H_
#define PATTERN3_H_

#include "./../Includes/atmega32.h"
#include <util/delay.h>

// Define the animation patterns for each layer
uint8_t patterns3[][3] = {
	{0b11111111, 0b11011111, 0b11011011}, // Layer 0: All LEDs off
	{0b11011001, 0b11001001, 0b01001001}, // Layer 1: All LEDs off
	{0b00001001, 0b00000001, 0b00000000}, // Layer 2: All LEDs off
};

uint8_t patterns3_blink[][3] = {
	{0b11111111, 0b11011111, 0b11111011}, // Layer 0: All LEDs off
	{0b11111101, 0b11101111, 0b01111111}, // Layer 1: All LEDs off
	{0b10111111, 0b11110111, 0b11111110}, // Layer 2: All LEDs off
};


void pattern3(){
	for (int j = 0; j < 3; j++) {
		LAYER_PORT = 0b00000111;
		// Output the pattern for the selected layer
		for (int i = 0; i < 3; i++) {
			if(i == 0 && j == 0){
				ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
				_delay_ms(200);
				continue;
			}
			COLUMN_PORT = patterns3[j][i];
			_delay_ms(200); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();

}

void pattern3_blink(){
	for (int j = 0; j < 3; j++) {
		LAYER_PORT = 0b00000111;
		// Output the pattern for the selected layer
		for (int i = 0; i < 3; i++) {
			if(i == 0 && j == 0){
				ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
				_delay_ms(200);
				ColUMN_LAST_PIN_PORT |= (1 << PINC0);
				continue;
			}
			COLUMN_PORT = patterns3_blink[j][i];
			_delay_ms(200); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();
}



#endif /* PATTERN3_H_ */