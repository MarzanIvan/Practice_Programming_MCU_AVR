#define F_CPU 8000000

#ifndef __AVR_ATmega328P__
	#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

inline void InitPorts() {
	DDRB = 0xff;
	DDRD = 0;
	PORTB = 0;
	PORTD = 0;
	EIMSK = 0b00000001;
	EICRA = 0b00000010;
	SREG |= (1 << 7);
	TCCR0B = 0b00000101;
	TCNT0 = 0;
}

inline void delay_ms_by_TimerCounter0B( double milliseconds ) {
	milliseconds /= 1000;
	TCNT0 = 0;
	while ( milliseconds > 0 ) {
		if ( TCNT0 == 255 ) {
			milliseconds -= 0.32640;
		}
		if ((TCNT0 * 0.00128) >= milliseconds ) {
			break;
		}
	}
}

ISR(INT0_vect) {
	if ( (PINB | 254) == 0xff) {
		PORTB &= 254;
	} else {
		PORTB |= 1;
	}
}

int main() { 
	InitPorts();
	while (true) {
		delay_ms_by_TimerCounter0B(500);
		PORTB |= 2;
		delay_ms_by_TimerCounter0B(500);
		PORTB &= 253;
	}
}