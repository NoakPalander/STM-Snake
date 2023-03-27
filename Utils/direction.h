#ifndef DIRECTION_H
#define DIRECTION_H

#include <stdint.h>
#include <stdbool.h>

#define LEFT ((DIRECTION) { .dx = -1, .dy = 0 })
#define RIGHT ((DIRECTION) { .dx = 1, .dy = 0 })
#define UP ((DIRECTION) { .dx = 0, .dy = -1 })
#define DOWN ((DIRECTION) { .dx = 0, .dy = 1 })

typedef struct {
    int8_t dx, dy;
} DIRECTION;

// Performs strict equality for directions
bool direction_equals(DIRECTION d1, DIRECTION d2);

// Converts between a keypad input to a direction
DIRECTION get_direction(unsigned char input, DIRECTION prev);

#endif // !DIRECTION_H