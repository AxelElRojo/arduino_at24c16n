#include "AT24C16N.hpp"
AT24C16N::AT24C16N(){
	this->error = false;
}
bool AT24C16N::write(const uint8_t page, const uint8_t addr, const uint8_t data){
	Wire.beginTransmission(HW_ADDR + page);
	Wire.write(addr);
	Wire.write(data);
	this->error = (Wire.endTransmission() != 0);
	return !this->error;
}
uint8_t AT24C16N::read(const uint8_t page, const uint8_t addr){
	uint8_t data = 0;
	Wire.beginTransmission(HW_ADDR + page);
	Wire.write(addr);
	Wire.endTransmission();
	Wire.requestFrom(HW_ADDR + page, 1);
	delay(1);
	if(Wire.available()){
		data = Wire.read();
		this->error = false;
	}else
		this->error = true;
	return data;
}
bool AT24C16N::errorOcurred(){
	return this->error;
}
bool AT24C16N::cwrite(const uint16_t addr, const uint8_t data){
	return this->write(addr/256, addr%256, data);
}
uint8_t AT24C16N::cread(const uint16_t addr){
	return this->read(addr/256, addr%256);
}