

#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#define F_CPU 16000000UL

#include <avr/io.h>

//For USART
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)


// Define the pins connected to the layers and columns of the LED cube

//layer
#define LAYER_PORT PORTA
#define LAYER_DDR DDRA
#define LAYER_MASK 0x07 // Assuming layers connected to PB0-PB2

//column
#define COLUMN_PORT PORTB
#define COLUMN_DDR DDRB
#define COLUMN_MASK 0xFF // Assuming columns connected to all of PORTD

#define ColUMN_LAST_PIN_PORT PORTC //9th column pin
#define ColUMN_LAST_PIN_DDR DDRC
#define COLUMN_LAST_PIN_MASK 0x01

// Function declarations
void reset_pins(void);
void initLEDs(void);


#endif /* ATMEGA32_H_ */