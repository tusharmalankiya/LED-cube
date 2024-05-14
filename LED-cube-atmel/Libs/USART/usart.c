
#include "usart.h"
#include <util/delay.h>

unsigned char interrupt_data = '1';

void USART_init(void){
	/* Set baud rate */
	UBRRH = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRRL = (uint8_t)(BAUD_PRESCALLER);
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: */
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); //8 bit data
}

void USART_EnableRXInterrupt(void) {
	UCSRB |= (1<<RXCIE); // Enable RX interrupt
}


void USART_transmit(unsigned char data){
	while (!(UCSRA & (1 << UDRE)));
	UDR = data;
}

unsigned char USART_receive(void){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void UART_received_string(char* buffer, int bufferSize){
	int i=0;
	
	while(i < bufferSize - 1){
		char receivedChar = USART_receive();
		if(receivedChar == '\n' || receivedChar == '\r'){
			break;
		}
		buffer[i++] = receivedChar;
	}
	buffer[i] = '\0';
}

void USART_transmition_string(const char* command){
	while(*command != '\0'){
		USART_transmit(*command);
		command++;
	}
	USART_transmit('\r');
	USART_transmit('\n');
	_delay_ms(1000);
}


//Interrupt Service Routine for USART receive interrupt. 
ISR(USART_RXC_vect) {
	
	interrupt_data = UDR; // Fetch the received byte into the buffer
	USART_transmit(interrupt_data);
	
}