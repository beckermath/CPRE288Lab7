/**
 * lab5_template.c
 *
 * Template file for CprE 288 Lab 5
 *
 * @author Diane Rover, 2/15/2020
 *
 */

#include "Timer.h"
#include "lcd.h"
#include "cyBot_Scan.h"  // For scan sensors
#include "uart.h"
#include "string.h"
#include <stdio.h>

// Uncomment or add any include directives that are needed
// #include "open_interface.h"
// #include "movement.h"
// #include "button.h"


void ping_init(void){//initialize timers

        SYSCTL_RCGCGPIO_R |= 0b00001000;
        while((SYSCTL_PRGPIO_R & 0b00001000) != 0b00001000){};

        GPIO_PORTB_AFSEL_R &= 0b11110111;//disable alternate function
        GPIO_PORTB_PCTL_R &= 0x00000000;

        GPIO_PORTB_DIR_R |= 0b00001000; //set dir to output when sending, reset to input when we're reading
        GPIO_PORTB_DEN_R |= 0b00001000;

        SYSCTL_RCGCTIMER_R &= 0x00000000;
        SYSCTL_RCGCTIMER_R |= 0x00000004;

        //THIS IS OUT OF ORDER, LOOK AT BAI BOOK INSTRUCTIONS AND REORDER;
        //fine tuning the timer config
        TIMER3_GPTMCTL_R &= 0x00000000; //step 1 in bai book
        TIMER3_GPTMCTL_R |= 0x000003C4; //Enables Timer B(pin 8), stops counting when we stop in debugger(pin 9), maybe change the C to a D if we don't need RTCEn, Timer A stuff might need to be Enabled, EVENT MODE-> BOTH EDGES, Pins 11;10 are set to 0x3

        TIMER3_GPTMCFG_R &= 0x00000000;
        TIMER3_GPTMCFG_R &= 0x00000001; //configures the timer register to hold 24 bits, not just 16(extra bits stay in timer B, 15:0 go into a timer A register)

        TIMER3_GPTMTBMR_R &= 0x00000000;
        TIMER3_GPTMTBMR_R |= 0x00000254;//last bits are 0b00101010100


}

void ping_trigger(void){//activate the PING))) sensor

}

float ping_getDistance(void){//calculate distance

}
