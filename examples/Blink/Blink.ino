#include <solight.h>

Solight solight(8);

void setup() {
}

void loop() {
	solight.control(31, 'A', 1);
	delay(1000);
	solight.control(31, 'A', 0);
	delay(1000);
}
