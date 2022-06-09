#include <Arduino.h>
#include <Wire.h>
#ifndef __AT24C16N_HPP__
#define __AT24C16N_HPP__
class AT24C16N{
	static constexpr uint8_t HW_ADDR = 0x50;
	bool error;
public:
	AT24C16N();
	bool write(const uint8_t page, const uint8_t addr, const uint8_t data);
	uint8_t read(const uint8_t page, const uint8_t addr);
	bool cwrite(const uint16_t addr, const uint8_t data);
	uint8_t cread(const uint16_t addr);
	bool errorOcurred();
};
#endif
