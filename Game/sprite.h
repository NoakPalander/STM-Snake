#include <stdint.h>
#include "../Utils/pos.h"

#ifndef SPRITE_H
#define SPRITE_H

#define board_width 16
#define board_height 8

typedef struct {
    POS pos;
    uint64_t sprite_mask;

    bool collidable;
} SPRITE;

void draw_sprite(SPRITE* spr);
void clear_sprite(SPRITE* spr);

#endif // !SPRITE_H