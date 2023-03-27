#ifndef ASCII_H
#define ASCII_H

#include "../Registers/gpio.h"

// Initializes the display
void ascii_init(gpio_t* gpio);

// Moves the cursor
void ascii_gotoxy(int x, int y, gpio_t* gpio);

// Writes a char to the display
void ascii_write_char(char x, gpio_t* gpio);

// Writes a null-terminated string to the display
void ascii_write_string(char const* string, gpio_t* gpio);

// Reads a char from the display
char ascii_read_char(gpio_t* gpio);

// Clears the display
void ascii_clear(gpio_t* gpio);


#endif // !ASCII_H