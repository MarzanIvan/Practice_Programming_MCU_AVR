
#define F_CPU 8000000

#ifndef __AVR_ATmega328P__
	#define __AVR_ATmega328P__
#endif

#include <avr/io.h>

inline void InitPorts() {
	DDRD = 0xff;
	PORTD = 0x00;
	TCCR0B = 0b00000101;
	TCNT0 = 0x00;
}

inline void delay_ms_by_TimerCounter0( double milliseconds ) {
	milliseconds /= 1000;
	while( milliseconds > 0 ) {
		if ( TCNT0 == 255 ) {
			milliseconds -= 0.3264;
		}
		if ((TCNT0 * 0.00128) >= milliseconds) {
			break;
		}
	}
}

int main() { 
	InitPorts();
	while (true) {
		delay_ms_by_TimerCounter0(500);
		PORTD |= 1;
		delay_ms_by_TimerCounter0(500);
		PORTD &= 254;
	}
}