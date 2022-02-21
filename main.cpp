
#define F_CPU 8000000

#ifndef __AVR_ATmega328P__
	#define __AVR_ATmega328P__
#endif

#include <avr/io.h>

inline void InitPorts() {
	DDRD = 0xff;
	PORTD = 0x00;
	TCCR1B = 0b00000010;
	TCNT1 = 0x00;
}

inline void delay_ms_by_TimerCounter1B( double milliseconds ) {
	milliseconds /= 1000;
	TCNT1 = 0;
	while ( milliseconds > 0 ) {
		if ( !TCNT1L && TCNT1H == 128 ) {
			milliseconds -= 0.32768;
		}
		if ( (TCNT1 * 0.00001) >= milliseconds ) {
			break;
		}
	}
}

int main() { 
	InitPorts();
	while (true) {
		delay_ms_by_TimerCounter1B(500);
		PORTD |= 1;
		delay_ms_by_TimerCounter1B(500);
		PORTD &= 254;
	}
}