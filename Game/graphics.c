#include "graphics.h"
#include "../Utils/direction.h"


uint64_t rotate_bitmask_to(uint64_t bitmask, DIRECTION dir) {
    if(direction_equals(dir, UP)) return bitmask;
    else {
        bitmask = rotate(bitmask);
        if(direction_equals(dir, RIGHT)) return bitmask;
        else {
            bitmask = rotate(bitmask);
            if(direction_equals(dir, DOWN)) return bitmask;
            else return rotate(bitmask);
        }
    }
}

uint64_t rotate(uint64_t bitmask) {
    uint64_t res = 0x0;
    for(char x = 0; x < 8; x++) {
        for(char y = 0; y < 8; y++) {
            if(bitmask & (1ull << (63 - (x + 8 * y)))) {
                res |= (1ull << (63 - (7-y + 8 * x)));
            }
        }
    }

    return res;
}

uint64_t mirror(uint64_t bitmask) {
    uint64_t res = 0x0;
    for(char x = 0; x < 8; x++) {
        for(char y = 0; y < 8; y++) {
            char i = 63 - (x + y * 8);
            char mirrored_i = 63 - ((7 - x) + y * 8);

            res |= ((uint64_t)((bitmask & (1ull << i)) != 0)) << mirrored_i; 
        }
    }

    return res;
}

/*
(0,0) (1,0)
(0,1) (1,1)

(0,1) (0,0)
(1,1) (1,0)
*/