#ifndef USART_H_
#define USART_H_

#include <avr/interrupt.h>

#include "./../../Includes/atmega32.h"

unsigned char interrupt_data;

void USART_init(void);

void USART_EnableRXInterrupt(void);

void USART_transmit(unsigned char data);

unsigned char USART_receive(void);

void UART_received_string(char* buffer, int bufferSize);

void USART_transmition_string(const char* command);


#endif /* USART_H_ */