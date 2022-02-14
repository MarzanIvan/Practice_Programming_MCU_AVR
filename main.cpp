
#define F_CPU 8000000

#ifndef __AVR_ATmega328P__
	#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <util/delay.h>

inline void InitPorts() {
	DDRC = 0x00;
	DDRB = 0xff;
	PORTB = 0x00;
	PORTC = 0x00;
}

inline bool IsHighPowerPC1() {
	if ((PINC | 0b11111101) == 0xff ) {
		return true;
	} else {
		return false;
	}
}

inline void ShowNumbersFrom_0_To_9_At7SegLed() {
	int ArrayNumbers[10] = {63,6,91,79,102,109,125,7,127,111};
	for( unsigned int i = 0; i < 10; ++i ) {
		PORTB = PORTB | ArrayNumbers[i];
		_delay_ms(100);
		PORTB = 0x00;
	}
}

int main() { 
	bool Active_Button = false;
	InitPorts();
	while (true) {
	    if (!IsHighPowerPC1() && !Active_Button) {
			Active_Button = true;
			ShowNumbersFrom_0_To_9_At7SegLed();
		}
		else {
			PORTB = 0x00;
			Active_Button = false;
		}
	}
}