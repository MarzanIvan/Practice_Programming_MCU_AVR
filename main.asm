    .include "m328pdef.inc"
    .def temp = r16
    .dseg
    .cseg
    .org 0
    rjmp Reset
    Reset:
    ldi temp, 0b00000010
    out PORTD, temp
    
    Program:
    
    rjmp Program

    ConfigureInterruptINT0:
    push temp
    ldi temp, 0b10000000
    out SREG, temp  ;enable global interrupts
    ldi temp, 0b00000011
    out EICRA, temp ;enable interrupt INT0 by the rising power 
    ldi temp, 0b00000001
    out EIMSK, temp
    pop temp

    INT0:
    push temp
    sbic PIND, 1 
    ldi temp, 0b00000010
    out PORTD, temp
    
    


    

