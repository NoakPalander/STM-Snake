#ifndef POS_H
#define POS_H

#include <stdbool.h>
#include <stdint.h>


typedef struct {
    uint16_t x, y;
} POS;

bool pos_equals(POS p1, POS p2);

#endif // !POS_H