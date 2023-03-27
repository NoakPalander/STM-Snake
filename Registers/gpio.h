#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef volatile struct __attribute__((packed)) {
    uint32_t moder;
    union {
        uint16_t otyper;
        struct {
            uint8_t otyper_low;
            uint8_t otyper_high;
        };
    };
    uint16_t _pad0;

    uint32_t ospeedr;
    uint32_t pupdr;

    union {
        uint16_t idr;
        struct {
            uint8_t idr_low;
            uint8_t idr_high;
        };
    };
    uint16_t _pad1;

    union {
        uint16_t odr;
        struct {
            uint8_t odr_low;
            uint8_t odr_high;
        };
    };
    uint16_t _pad2;

    uint32_t bsrr;
    uint32_t lckr;
    uint32_t afrl;
    uint32_t afrh;
} gpio_t;

#define GPIO_A (*(gpio_t*)0x40020000)
#define GPIO_B (*(gpio_t*)0x40020400)
#define GPIO_C (*(gpio_t*)0x40020800)
#define GPIO_D (*(gpio_t*)0x40020C00)
#define GPIO_E (*(gpio_t*)0x40021000)

#endif // !GPIO_H