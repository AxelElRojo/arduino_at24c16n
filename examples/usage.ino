#include <Wire.h>
#include <AT24C16N.hpp>
AT24C16N eeprom;
void setup(){
	// Make sure to start I2C communication
	Wire.begin();
	// Serial communication for printing to the serial monitor
	Serial.begin(9600);
	// Read: Page (0-7), Address (0x0-0xFF)
	Serial.print(eeprom.read(0, 1));
	// Write: Page (0-7), Address (0x0-0xFF), Data (0x0-0xFF)
	eeprom.write(0, 1, 0x20);
	// Read: Page (0-7), Address (0x0-0xFF)
	Serial.print(eeprom.read(0, 1));
}
void loop(){}