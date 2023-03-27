#include "ascii.h"
#include "../Registers/gpio.h"
#include "../Utils/delay.h"
#include <string.h>

#define B_E         0x40
#define B_SELECT    4
#define B_RW        2
#define B_RS        1

static void ascii_ctrl_bit_set(unsigned char x, gpio_t* gpio) {
    unsigned char c = gpio->odr_low;
    gpio->odr_low = B_SELECT | x | c;
}

static void ascii_ctrl_bit_clear(unsigned char x, gpio_t* gpio) {
    unsigned char c = gpio->odr_low;
    c &= ~x;
    
    gpio->odr_low = B_SELECT | c;
}

static char ascii_read_controller(gpio_t* gpio) {
    gpio->moder = 0x00005555;
    ascii_ctrl_bit_set(B_E, gpio);
    
    delay(500, nanoseconds);
    
    char c = (char)gpio->idr_high;
    
    ascii_ctrl_bit_clear(B_E, gpio);
    gpio->moder = 0x55555555;
    return c;
}

static char ascii_read_status(gpio_t* gpio) {
    ascii_ctrl_bit_set(B_RW, gpio);
    ascii_ctrl_bit_clear(B_RS, gpio);
    
    char c = ascii_read_controller(gpio);
    return c;
}

static void ascii_write_controller(char c, gpio_t* gpio) {
    ascii_ctrl_bit_set(B_E, gpio);
    gpio->odr_high = c;
    
    ascii_ctrl_bit_clear(B_E, gpio);
}

void ascii_init(gpio_t* gpio) {
    // Clears the display
    ascii_write_controller(1, gpio);

    // Set display function
    // 0010'1000 = 0x38
    ascii_write_controller(0x38, gpio);
    
    // Turn on display and turn off cursor
    // 0000'1100 = 0x0C
    ascii_write_controller(0x0C, gpio);
    
    // Configures how we input data
    // 0000'0110 = 0x06
    ascii_write_controller(0x06, gpio);
}

void ascii_gotoxy(int x, int y, gpio_t* gpio) {
    unsigned char data;
    if (y == 0) {
        data = x;
    }
    else {
        data = 0x40 + x;
    }
    
    data |= 0x80;
    ascii_write_controller(data, gpio);
}

void ascii_write_char(char x, gpio_t* gpio) {
    if (x == '\n') {
        ascii_gotoxy(0, 1, gpio);
    }
    else {
        ascii_ctrl_bit_set(B_RS, gpio);
        ascii_write_controller(x, gpio);
        ascii_ctrl_bit_clear(B_RS, gpio);
    }
}

// Writes a null-terminated string to the display
void ascii_write_string(char const* string, gpio_t* gpio) {
    size_t len = strlen(string);
    for (size_t i = 0; i < len; ++i)
        ascii_write_char(string[i], gpio);
}

// Reads a character from
char ascii_read_char(gpio_t* gpio) {
    return ascii_read_controller(gpio);
}

void ascii_clear(gpio_t* gpio) {
    ascii_write_controller(1, gpio);
}