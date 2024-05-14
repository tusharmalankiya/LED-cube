/*
 * LED-cube-atmel.c
 *
 * Created: 4/6/2024 1:48:12 PM
 * Author : Tushar Malankiya
 */ 

#include "Includes/atmega32.h"

#include "./Libs/USART/USART.h"

#include "Patterns/patterns.h"

#include <util/delay.h>
//#include <string.h>



int main(void) {
	initLEDs(); // Initialize LED pins
	
	//initializing USART
	USART_init();
	
	USART_EnableRXInterrupt(); //enable interrupt
	sei(); // Enable global interrupts
	
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
		if(interrupt_data == '1'){
			pattern1_blink();
		}
		else if(interrupt_data == '2'){
			pattern2_blink();
		}
		else if(interrupt_data == '3'){
			pattern3_blink();
		}
		else{
			pattern4_blink();
		}
		
		//pattern2_blink();
		//pattern4_blink();
		
	}
	
	return 0;
}
