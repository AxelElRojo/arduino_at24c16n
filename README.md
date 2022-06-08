# AT24C16N library for Arduino
This library provides a class to communicate with an AT24C16N eeprom.

[Datasheet](https://www.mouser.com/datasheet/2/268/doc0180-1180742.pdf)

## Introduction
The AT24C16N is a 16Kb (2 KiB) I2C eeprom. I wrote this library because I couldn't find an existing one. I haven't tested this completely, so there are bound to be some bugs, if you find any, please open an issue.
## Write protect
This eeprom has a Write Protect (WP) pin below VCC, it allows R/W operations when connected to GND, and protects the memory from writing when connected to VCC, this library doesn't handle that, so you'll have to manage this pin yourself, if you're interested in it.
## Methods
| Method | Return Value | Description |
| ------ | ------ | ------ |
| `AT24C16N()` | - | - | Constructor |
| `write(uint8_t page, uint8_t addr, uint8_t data)` | `bool` | Writes the value to the specified page and address. |
| `read(uint8_t page, uint8_t addr)` | `uint8_t` | Returns the value on the specified page and address. |
| `errorOcurred()` | `bool` | Checks if an error has ocurred. |
## Examples
In the examples directory you will find two simple examples:
### Usage
A simple explanation on how to use the library.
### Debug
A debug function, it prints an entire memory page.
