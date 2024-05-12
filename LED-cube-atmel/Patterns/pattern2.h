
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

// Function to display a layer pattern
void displayPattern2Layer(uint8_t layer) {
	LAYER_PORT = (LAYER_PORT | ~LAYER_MASK) | (1 << layer); // Select the layer
	LAYER_PORT = 0b00000111;
	// Output the pattern for the selected layer
	for (int i = 0; i < 3; i++) {
		if(i == 2 && layer == 2){
			ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
			_delay_ms(200);
			continue;
		}
		COLUMN_PORT = patterns2[layer][i];
		_delay_ms(200); // Adjust the delay as needed for brightness
	}
}

void pattern2(){
	for (int layer = 0; layer < 3; layer++) {
		displayPattern2Layer(layer);
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();

}




#endif /* PATTERN2_H_ */