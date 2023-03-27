#include "sprite.h"


void draw_sprite(SPRITE* spr) {
    POS base_pos = { .x = spr->pos.x * 8, .y = spr->pos.y * 8 };

    for(int sx = 0; sx < 8; sx++) {
        for(int sy = 0; sy < 8; sy++) {
            if(spr->sprite_mask & (1ull << (63 - (sx + 8 * sy)))) {
                POS p = (POS){ base_pos.x + sx, base_pos.y + sy };
                lcd_set_pixel(p.x, p.y);
            }
        }
    }
}

void clear_sprite(SPRITE* spr) {
    POS base_pos = { .x = spr->pos.x * 8, .y = spr->pos.y * 8 };

    for(int sx = 0; sx < 8; sx++) {
        for(int sy = 0; sy < 8; sy++) {
            if(spr->sprite_mask & (1ull << (63 - (sx + 8 * sy)))) {
                POS p = (POS){ base_pos.x + sx, base_pos.y + sy };
                lcd_clear_pixel(p.x, p.y);
            }
        }
    }
}
