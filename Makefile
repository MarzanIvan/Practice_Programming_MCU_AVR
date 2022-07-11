VersionOfMCU = atmega328p

Build: main.cpp include/main.h
	avr-gcc -g -Os -mmcu=$(VersionOfMCU) -c main.cpp
	avr-gcc -g -mmcu=$(VersionOfMCU) -o main.elf main.cpp
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex