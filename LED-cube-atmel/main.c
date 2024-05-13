/*
 * LED-cube-atmel.c
 *
 * Created: 4/6/2024 1:48:12 PM
 * Author : Tushar Malankiya
 */ 

#include "Includes/atmega32.h"

#include "./Libs/USART/USART.h"

#include "Patterns/pattern1.h"
#include "Patterns/pattern2.h"
#include "Patterns/pattern3.h"


#include <util/delay.h>
//#include <string.h>



int main(void) {
	initLEDs(); // Initialize LED pins
	
	//initializing USART
	//USART_init();
	
	//transmitting String
	//USART_transmition_string("Hello");
	
	
	while (1) {
		
		//receiving characters
		//char response[64];
		//UART_received_string(response, 64);
		//char str[40] = "response: ";
		//strcat(str, response);
		//transmitting String
		//USART_transmition_string(str);
		
		// Display each layer in sequence to create animation
		//pattern1_blink();
		//pattern3_blink();
		pattern2_blink();
		
	}
	
	return 0;
}
