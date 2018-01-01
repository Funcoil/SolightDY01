#include "dy01.h"

DY01::DY01(int pin, int transmitCount) :
	mPin(pin),
	mTransmitCount(transmitCount)
{
	pinMode(mPin, OUTPUT);
}

void DY01::transmitBit(uint8_t b) {
	digitalWrite(mPin, HIGH);
	delayMicroseconds(150 + 300*b);
	digitalWrite(mPin, LOW);
	delayMicroseconds(450 - 300*b);
}

void DY01::control(uint16_t socketNumber, char state) {
	uint16_t tmp; 
	int i, j;
	for(j = 0; j < mTransmitCount; ++j) {
		tmp = socketNumber;
		// Channel number
		for(i = 0; i < 5; ++i) {
			transmitBit((tmp / 512) % 2);
			transmitBit(1);
			tmp *= 2;
		}
		transmitBit(0);
		// Socket ID
		for(i = 0; i < 5; ++i) {
			transmitBit((tmp / 512) % 2);
			transmitBit(0);
			tmp *= 2;
		}

		// State
		transmitBit(state);
		transmitBit(0);
		transmitBit(!state);
		transmitBit(0);
		delayMicroseconds(4600);
	}
}

void DY01::control(uint16_t channelNumber, char socketLetter, char state) {
	channelNumber *= 32;
	switch(socketLetter) {
		case 'A':
		case 'a':
			channelNumber += 31-16;
			break;
		case 'B':
		case 'b':
			channelNumber += 31-8;
			break;
		case 'C':
		case 'c':
			channelNumber += 31-4;
			break;
		case 'D':
		case 'd':
			channelNumber += 31-2;
			break;
		case 'E':
		case 'e':
			channelNumber += 31-1;
			break;
	}
	Serial.println(channelNumber);
	control(channelNumber, state);
}
