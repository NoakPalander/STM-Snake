#ifndef STK_H
#define STK_H

#include <stdint.h>

typedef volatile struct __attribute__((packed)) {
    union {
        uint32_t ctrl;
        struct {
            uint8_t ctrl_flags;
            uint8_t _reserved0;
            uint8_t ctrl_count;
            uint8_t _reserved1;
        };
    };
    
    uint32_t load;
    uint32_t val;
    uint32_t calib;
} stk_t;


#define STK (*(volatile stk_t*)0xE000E010)

#endif // !STK_H