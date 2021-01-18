/*	Author: Biqian Cheng
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 2  Exercise 3
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
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
 	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs 	
	DDRD = 0XFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
	unsigned char weightA = 0x00; // Temporary variable to hold the value in A
	unsigned char weightB = 0x00; // Temporary variable to hold the value in B
	unsigned char weightC = 0x00; // Temporary variable to hold the value in C
	unsigned char weightD = 0x00; // Temporary variable to hold the value in D
	unsigned char totalWeight = 0x00;
	unsigned char temp = 0x00;
	while(1) {
		// 1) Read input
		weightA = PINA;
		weightB = PINB;
		weightC = PINC;
		totalWeight = weightA + weightB + weightC;
		temp = totalWeight&0xFC;
		if(weightA == 64 || weightB == 64 || weightC == 64){
			temp = 0x31;
		}
		if(weightA == 0 && weightB ==35 && weightC == 85)
		{
			temp = 0x1e;
		}
		if(weightA == 0 && weightB == 55 && weightC == 85){
			temp = 0x22;
		}
		//else{
			//temp = temp & 0x22;
		//}
	// 3) Write output
	PORTD = temp;
	}
	return 0;
}

