#include "AT24C16N.hpp"
void debug(const AT24C16N& eeprom, const uint8_t page){
	uint8_t data;
	Serial.print("\t");
	for(uint8_t i=0; i<=0xF; ++i){
		Serial.print("0x0");
		Serial.print(i, HEX);
		Serial.print("\t");
	}
	Serial.println();
	for(uint8_t i=0; i<=0xF; ++i){
		Serial.print("0x");
		Serial.print(i, HEX);
		Serial.print("0\t");
		for(uint8_t j=0; j<=0xF; ++j){
			data = eeprom.read(page, i*j + i+j);
			Serial.print("0x");
			if(data < 0x10)
				Serial.print("0");
			Serial.print(data, HEX);
			Serial.print('\t');
		}
		Serial.println();
	}
}
