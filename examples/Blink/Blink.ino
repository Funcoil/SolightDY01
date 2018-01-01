#include <dy01.h>

DY01 transmitter(8);

void setup() {
}

void loop() {
	transmitter.control(31, 'A', 1);
	delay(1000);
	transmitter.control(31, 'A', 0);
	delay(1000);
}
