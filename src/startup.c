#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

#include "Registers/gpio.h"
#include "Display/ascii.h"
#include "Display/lcd.h"
#include "Utils/input.h"
#include "Game/snake.h"
#include "Utils/delay.h"

#define SCREEN ((gpio_t*)(&GPIO_E))
#define KEYBOARD ((gpio_t*)(&GPIO_D))

__attribute__((naked))
__attribute__((section(".start_section")))
void startup (void) {
    __asm__ volatile(" LDR R0,=__stack_top\n");	/* set stack */
    __asm__ volatile(" MOV SP,R0\n");
    __asm__ volatile(" BL _crt_init\n");			/* init C-runtime library */
    __asm__ volatile(" BL main\n");			/* call main */
    __asm__ volatile(" BL _crt_deinit\n");		/* deinit C-runtime library */
    __asm__ volatile(" B .\n");				/* never return */
    __asm__ volatile(" .LTORG\n");				/* dump literal */
}

static void app_init(void) {
#ifndef SIMULATOR
    // Start clocks on port D, E
    *((volatile uint32_t*) 0x40023830) = 0x18;
#endif
    
    SCREEN->moder = 0x55555555;
    ascii_init(SCREEN);
    lcd_init();
    lcd_clear();    

    keyboard_init(KEYBOARD);
}

// Returns a static string representing our score
char* format_score(int score) {
    static char buffer[15] = {0};

    // Format buffer
    sprintf(buffer, "%s%d", "Score: ", score);    

    // Return buffer
    return buffer;
}

void start_game(void) {
    ascii_clear(SCREEN);
    ascii_write_string("Press * to start!", SCREEN);
    unsigned char input;

    do {
        input = read_key(KEYBOARD);
    } while (input != 14);

    init_game();
    ascii_clear(SCREEN);
}

void game_over(int score) {
    ascii_clear(SCREEN);
    ascii_write_string("Game over!\n", SCREEN);    
    ascii_write_string(format_score(score), SCREEN);

    delay(3, seconds);

    reset_game();
    start_game();
}

int main(void) {
    app_init();
    start_game();

    // Start direction is right
    DIRECTION dir = RIGHT;
    int score = 0;
    ascii_write_string(format_score(score), SCREEN);

    while (true) {        
        int new_score = get_score();
        if (new_score != score) {
            score = new_score;
            
            ascii_clear(SCREEN);
            ascii_write_string(format_score(score), SCREEN);
        }
        
        // Read and update direction input
        unsigned char key = read_key(KEYBOARD);
        dir = get_direction(key, dir);

        delay(300, milliseconds);

        // Update game
        if (!move_snake(dir)) {
            game_over(score);
            dir = RIGHT;
            score = 0;
            ascii_write_string(format_score(score), SCREEN);
        }
    }

    // LCD Display (Grafiska): 128 x 64 dots
    // 16 x 64 sprites
}
