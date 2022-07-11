    .include "m328pdef.inc"
    .def temp = r16
    .dseg
    .cseg
    .org 0
    rjmp Reset
    Reset:
    ldi temp, 0b00000001
    out DDRD, temp
    Program:
    ldi temp, 0b00000001
    out PORTD, temp
    rcall Delay
    ldi temp, 0
    out PORTD, temp
    rcall Delay
    rjmp Program

    Delay:
    ldi temp, 0xff
    LoopDelay:
    dec temp
    brne LoopDelay
    ret