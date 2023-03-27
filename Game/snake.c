#include "snake.h"
#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "../Utils/rng.h"
#include "../Display/lcd.h"

const POS snake_start_pos = { .x = 4, .y = board_height / 2 };

SPRITE* board_sprites[board_width][board_height] = { 0 };
SPRITE fruit = { .sprite_mask = fruit_graphics, .collidable = false };

SNAKE_HEAD snake_head;

uint16_t score = 0;

void update_seg_sprite(SNAKE_SEG* seg) {
    POS curr_pos = seg->sprite.pos;

    DIRECTION next_dir = { .dx = 0, .dy = 0};
    DIRECTION prev_dir = { .dx = 0, .dy = 0};

    if(seg->next != 0x0) {
        POS next_pos = seg->next->sprite.pos;
        next_dir = (DIRECTION){ .dx = next_pos.x - curr_pos.x, .dy = next_pos.y - curr_pos.y };
    }

    if(seg->prev != 0x0) {
        POS prev_pos = seg->prev->sprite.pos;
        prev_dir = (DIRECTION){ .dx = curr_pos.x - prev_pos.x, .dy = curr_pos.y - prev_pos.y };
    }

    uint64_t bitmask;
    if(seg->next == 0x0) {
        bitmask = rotate_bitmask_to(head_graphics, prev_dir);
    }
    else {
        if(seg->prev == 0x0) bitmask = tail_graphics;
        else if(direction_equals(prev_dir, next_dir)) bitmask = body_graphics;
        else {
            bitmask = body_turn_graphics;

            //(1, 0) -> (0, 1)
            DIRECTION prev_dir_turned_right = (DIRECTION){ .dx = -prev_dir.dy, .dy = prev_dir.dx };
            if(!direction_equals(prev_dir_turned_right, next_dir)) bitmask = mirror(bitmask);
        }

        bitmask = rotate_bitmask_to(bitmask, next_dir);
    }

    seg->sprite.sprite_mask = bitmask;
}

void update_seg_sprite_and_redraw(SNAKE_SEG* seg) {
    clear_sprite(&seg->sprite);
    update_seg_sprite(seg);
    draw_sprite(&seg->sprite);
}

//Returns true if move succesful
bool move_snake(DIRECTION dir) {
    SNAKE_SEG* new_head = snake_head.tail;
    SNAKE_SEG* new_tail = snake_head.tail->next;
    SNAKE_SEG* old_head = snake_head.head;

    POS old_tail_pos = snake_head.tail->sprite.pos;
    POS new_head_pos = old_head->sprite.pos;
    new_head_pos.x += dir.dx;
    new_head_pos.y += dir.dy;

    if(new_head_pos.x >= board_width || new_head_pos.x < 0 || new_head_pos.y >= board_height || new_head_pos.y < 0) return false;
    if(board_sprites[new_head_pos.x][new_head_pos.y] != 0x0) {
        SPRITE* other = board_sprites[new_head_pos.x][new_head_pos.y];
        if(other->collidable) return false;
    }

    bool snake_should_grow = false;
    if(pos_equals(new_head_pos, fruit.pos)) {
        randomize_fruit();
        snake_should_grow = true;
        score++;
    }

    old_head->next = new_head;

    new_head->next = 0x0;
    new_head->prev = old_head;
    new_head->sprite.collidable = true;

    new_tail->prev = 0x0;
    new_tail->sprite.collidable = false; //You can still move into this square since it will be empty after the tick

    clear_sprite(&new_head->sprite);
    board_sprites[old_tail_pos.x][old_tail_pos.y] = 0;

    new_head->sprite.pos = new_head_pos;

    update_seg_sprite(new_head);
    draw_sprite(&new_head->sprite);
    board_sprites[new_head_pos.x][new_head_pos.y] = new_head;

    update_seg_sprite_and_redraw(old_head);
    update_seg_sprite_and_redraw(new_tail);

    snake_head.head = new_head;
    snake_head.tail = new_tail;

    if(snake_should_grow) grow_snake(old_tail_pos);

    return true;
}

void randomize_fruit(void) {
    clear_sprite(&fruit);

    static POS free_positions[board_width * board_height];
    int free_count = 0;

    // doesnt seem right
    for(int x = 0; x < board_width; x++) {
        for(int y = 0; y < board_height; y++) {
            if(board_sprites[x][y] == 0x0) {
                free_positions[free_count] = (POS) { .x = x, .y = y };
                ++free_count;
            }
        }
    }
    
    uint64_t r = rng_next();
    size_t random_index = r % free_count;
    fruit.pos = free_positions[random_index];

    draw_sprite(&fruit);
}

void grow_snake(POS pos) {
    SNAKE_SEG* new_tail = malloc(sizeof *new_tail);
    SNAKE_SEG* old_tail = snake_head.tail;
    
    new_tail->next = old_tail;
    new_tail->prev = 0x0;
    new_tail->sprite.pos = pos;
    new_tail->sprite.collidable = false;

    old_tail->sprite.collidable = true;
    old_tail->prev = new_tail;

    snake_head.tail = new_tail;

    clear_sprite(&old_tail->sprite);
    update_seg_sprite(old_tail);
    draw_sprite(&old_tail->sprite);

    update_seg_sprite(new_tail);
    draw_sprite(&new_tail->sprite);
}

void reset_game(void) {
    SNAKE_SEG* curr_seg = snake_head.head;
    while(curr_seg != 0x0) {
        SNAKE_SEG* next_seg = curr_seg->next;
        free(curr_seg);

        curr_seg = next_seg;
    }

    snake_head.head = 0x0;
    snake_head.tail = 0x0;
    bool snake_should_grow = false;
    score = 0;

    for(int x = 0; x < board_width; x++) {
        for(int y = 0; y < board_height; y++) {
            board_sprites[x][y] = 0x0;
        }
    }
}

//Returns false if gameover
bool perform_tick(DIRECTION dir) {
    if(!move_snake(dir)) return false;
    return true;
}

void init_snake(void) {
    SNAKE_SEG* new_seg = malloc(sizeof *new_seg);
    new_seg->next = 0x0;
    new_seg->prev = 0x0;
    new_seg->sprite.pos = snake_start_pos;
    new_seg->sprite.collidable = true;

    snake_head.head = new_seg;
    snake_head.tail = new_seg;

    grow_snake((POS){ .x = snake_start_pos.x - 1, .y = snake_start_pos.y });
    grow_snake((POS){ .x = snake_start_pos.x - 2, .y = snake_start_pos.y });
    grow_snake((POS){ .x = snake_start_pos.x - 3, .y = snake_start_pos.y });
}

void init_game(void) {
    lcd_clear();

    rng_init(rng_default_seed);
    init_snake();
    randomize_fruit();
}

uint16_t get_score(void) {
    return score;
}