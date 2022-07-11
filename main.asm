    .include "m328Pdef.inc"
    .def temp = r16
    .dseg
    .cseg
    .org 0
    rjmp Reset
    .org 0x002
    rjmp INT0_ISR
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
    sts EICRA, temp ;enable interrupt INT0 by the rising power 
    ldi temp, 0b00000001
    out EIMSK, temp
    pop temp

    INT0_ISR:
    
    
    EnableHignPowerOnPD1:
    push temp   ;saving temp to stack
    ldi temp, 0b00000011
    out PORTD, temp
    pop temp    ;getting saved temp from stack
    EnableLowPowerOnPD1:
    push temp   ;saving temp to stack
    ldi temp, 0b00000001
    out PORTD, temp
    pop temp    ;getting saved temp from stack