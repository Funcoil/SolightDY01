#ifndef SOLIGHT_H
#define SOLIGHT_H

#include "Arduino.h"

class DY01 {
	public:
		// If you set transmitCount to less than 2, it won't work!
		DY01(int pin, int transmitCount = 5);
		void control(uint16_t socketNumber, char state);
		void control(uint16_t channelNumber, char socketLetter, char state);
	private:
		void transmitBit(uint8_t b);
		int mPin, mTransmitCount;
};

#endif
