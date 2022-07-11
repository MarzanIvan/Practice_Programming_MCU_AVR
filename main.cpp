#define F_CPU 8000000

#ifndef __AVR_ATmega328P__
	#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>

inline void ConfigurePorts() {
	DDRD |= 0xff;
}

int main() { 
	ConfigurePorts();
	while (true) {
		PORTD |= 1;
		_delay_us(100);
		PORTD &= 0;
		_delay_us(100);
	}
}