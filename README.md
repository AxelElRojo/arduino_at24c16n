# AT24C16N library for Arduino
This library provides a class to communicate with an AT24C16N eeprom.

[Datasheet](https://www.mouser.com/datasheet/2/268/doc0180-1180742.pdf)

## Introduction
The AT24C16N is a 16Kb (2 KiB) I2C EEPROM. I wrote this library because I couldn't find an existing one. I haven't tested this completely, so there are bound to be some bugs, if you find any, please open an issue.
## Write protection
This EEPROM has a Write Protect (WP) pin below VCC, it allows R/W operations when connected to GND, and protects the memory from writing when connected to VCC, this library doesn't handle that, so you'll have to manage this pin yourself, if you're interested in it.
## Addressing
This library handles addressing automatically, but keep in mind that addresses 0x50 to 0x57 (8 in total) are used by the EEPROM. You also need to start I2C communications manually by calling `Wire.begin()`.
## Public methods
| Name | Return Value | Description |
| ------ | ------ | ------ |
| `AT24C16N()` | - | - | Constructor |
| `write(uint16_t addr, uint8_t data)` | `bool` | Writes the value to an address between 0 and 2047. |
| `read(uint16_t addr)` | `uint8_t` | Returns the value from an address between 0 and 2047. |
| `errorOcurred()` | `bool` | Checks if an error has ocurred. |
### Read and Write
R/W operations calculate the I2C and memory addresses based on the provided address, a number between 0 and 2047. The number's value isn't checked to be an acceptable value, be careful with that.
## Examples
In the examples directory you will find two simple examples:
### Usage
A simple explanation on how to use the library.
### Debug
A debug function, it prints an entire memory page.