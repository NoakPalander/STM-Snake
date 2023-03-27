#include "delay.h"
#include "../Registers/stk.h"
#include <stdint.h>


static void delay_250ns(void) {
    STK.ctrl = 0;
    STK.load = 168 / 4;
    STK.val = 0;
    STK.ctrl = 5;
    
    while (STK.ctrl_flags == 0);
    STK.ctrl = 0;
}


static void delay_milli(unsigned int ms) {
#ifdef SIMULATOR
    int m = ms * 4;
#else
    int m = ms * 1000 * 4;
#endif

    for (int i = 0; i < m; i++)
        delay_250ns();
}

// Causes a delay for 'amount' unit's
void delay(unsigned int amount, time_unit unit) {
    switch (unit) {
        case seconds: {
            unsigned int ms = amount * 1000;
            delay_milli(ms);
        } break;
        
        case milliseconds: {
            delay_milli(amount);
        } break;

        case microseconds: {
            unsigned int ns = amount * 1000;
            unsigned int iterations = ns / 250;
            for (unsigned int i = 0; i < iterations; ++i)
                delay_250ns();
        } break;

        case nanoseconds: {
            unsigned int iterations = amount / 250;
            for (unsigned int i = 0; i < iterations; ++i)
                delay_250ns();
        } break;

        default:
            __builtin_unreachable();
    }
}