/*	Author: Biqian Cheng
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 2  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s 	
	unsigned char cntavail = 0x00; //initialize available spots  
	unsigned char tempA0 = 0x00; // Temporary variable to hold the value of the first pin in A
	unsigned char tempA1 = 0x00; // Temporary variable to hold the value of the second pin in A
	unsigned char tempA2 = 0x00; // Temporary variable to hold the value of the third pin in A
	unsigned char tempA3 = 0x00; // Temporary variable to hold the value of the fourth pin in A
	while(1) {
		// 1) Read input
		tempA0 = PINA & 0x01;
		tempA1 = PINA & 0x02;
		tempA2 = PINA & 0x04;
		tempA3 = PINA & 0x08;
		cntavail = 4 - (tempA3>>3) - (tempA2>>2) - (tempA1>>1) - tempA0;
		if(cntavail == 0){
			PORTC = cntavail;
		}
		else{
			PORTC = cntavail;
		}
	// 3) Write output
	}
	return 0;
}

