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


#warning "Possible unimplemented functions"
#define REPLACEME 0


main(void) {
	timer_init();
	lcd_init();

	//trigger pulse is 40kHz, tBURST = 200 us @ 40 mHz



	ping_init();

	//check for GPTMTBILR < 0x48440; upper bound of counter(max echo pulse width)
	//GPTMTBR stores current value of the counter, and the


	GPIO_PORTB_DATA_R |= 0b00001000;

	timer_waitMicros(2);

	GPIO_PORTB_DATA_R &= 0b11110111;





}
