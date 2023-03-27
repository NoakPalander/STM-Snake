#include "input.h"
#include <limits.h>


static void kbd_activate(unsigned int row, gpio_t* gpio) {
    switch (row) {
        case 1: gpio->odr_high = 0x10; break;
        case 2: gpio->odr_high = 0x20; break;
        case 3: gpio->odr_high = 0x40; break;
        case 4: gpio->odr_high = 0x80; break;
        case 0: gpio->odr_high = 0x00; break;
    }
}

static int kbd_get_col(gpio_t* gpio) {
    unsigned char c = gpio->idr_high;
    if (c & 0x8) return 4;
    if (c & 0x4) return 3;
    if (c & 0x2) return 2;
    if (c & 0x1) return 1;
    
    return 0;
}

void keyboard_init(gpio_t* gpio) {
    gpio->moder = 0x55005555;
    gpio->otyper = 0xFF00;
    gpio->pupdr = 0xAAAA0000;
    gpio->ospeedr = 0x55555555;
}

unsigned char read_key(gpio_t* gpio) {
    static unsigned char key[] = {1, 2, 3, 0xA, 4, 5, 6, 0xB, 7, 8, 9, 0xC, 0xE, 0, 0xF, 0xD};
    
    for (int row = 1; row <= 4; row++) {
        kbd_activate(row, gpio);
        int col = kbd_get_col(gpio);
        if (col) {
            kbd_activate(0, gpio);
            return key[4 * (row - 1) + (col - 1)];
        }
    }

    kbd_activate(0, gpio);
    return UCHAR_MAX;
}