#include "patterns.h"

// Define the animation patterns for each layer
uint8_t patterns1[][3] = {
	{0b11111110, 0b11111100, 0b11111000}, // Layer 0: All LEDs off
	{0b11011000, 0b11001000, 0b11000000}, // Layer 1: All LEDs off
	{0b10000000, 0b00000000, 0b11111111}, // Layer 2: All LEDs off
};

// Define the animation patterns for each layer
uint8_t patterns1_blink[][3] = {
	{0b11111110, 0b11111101, 0b11111011}, // Layer 0: All LEDs off
	{0b11011111, 0b11101111, 0b11110111}, // Layer 1: All LEDs off
	{0b10111111, 0b01111111, 0b11111111}, // Layer 2: All LEDs off
};

// Function to display a layer pattern
void displayLayer(uint8_t layer) {
	LAYER_PORT = (LAYER_PORT | ~LAYER_MASK) | (1 << layer); // Select the layer
	
	// Output the pattern for the selected layer
	for (int i = 0; i < 3; i++) {
		if(i == 2 && layer == 2){
			ColUMN_LAST_PIN_PORT &= ~(1 << PINC0);
			_delay_ms(100);
			continue;
		}
		COLUMN_PORT = patterns1[layer][i];
		_delay_ms(100); // Adjust the delay as needed for brightness
	}
}

void pattern1(void){
	for (int layer = 0; layer < 3; layer++) {
		displayLayer(layer);
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();

}

void pattern1_blink(void){
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
			COLUMN_PORT = patterns1_blink[j][i];
			_delay_ms(100); // Adjust the delay as needed for brightness
		}
		_delay_ms(1); // Adjust the delay to control animation speed
	}
	reset_pins();
}
