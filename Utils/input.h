#ifndef INPUT_H
#define INPUT_H

#include "../Registers/gpio.h"

// Initializes the keyboard
void keyboard_init(gpio_t* gpio);

// Reads a keypress from the keypad
// Returns `UCHAR_MAX` if nothing was pressed, otherwise it returns the integral-
// value for the corresponding key
unsigned char read_key(gpio_t* gpio);

#endif // !INPUT_H