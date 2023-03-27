#ifndef SNAKE_H
#define SNAKE_H

#include <stdint.h>
#include <stdbool.h>
#include "../Utils/direction.h"
#include "../Utils/pos.h"
#include "../Game/sprite.h"

typedef struct SNAKE_SEG {
    SPRITE sprite;

    struct SNAKE_SEG* next;
    struct SNAKE_SEG* prev;
} SNAKE_SEG;

typedef struct {
    SNAKE_SEG* head;
    SNAKE_SEG* tail;
} SNAKE_HEAD;

extern const POS snake_start_pos;
extern SPRITE* board_sprites[board_width][board_height];
extern SPRITE fruit;
extern SNAKE_HEAD snake_head;
extern uint16_t score;

void update_seg_sprite(SNAKE_SEG* seg);
void update_seg_sprite_and_redraw(SNAKE_SEG* seg);

bool move_snake(DIRECTION dir);
void grow_snake(POS pos);
bool perform_tick(DIRECTION dir);
uint16_t get_score(void);

void init_snake(void);
void init_game(void);
void randomize_fruit(void);
void reset_game(void);

#endif // !SNAKE_H
