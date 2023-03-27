#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include "../Utils/direction.h"

uint64_t rotate(uint64_t bitmask);
uint64_t mirror(uint64_t bitmask);

uint64_t rotate_bitmask_to(uint64_t bitmask, DIRECTION dir);

#define fruit_graphics ((uint64_t)0x071C387C7C7C3800)
#define head_graphics ((uint64_t)0x183C7E5A5A7E7E7E)
#define body_graphics ((uint64_t)0x7E7E7E7E7E7E7E7E)
#define body_turn_graphics ((uint64_t)0x7E7F7F7F7F3F1F00)
#define tail_graphics ((uint64_t)0x7E7E7E7E3C3C1818)



/* 

Body
01111110 - 7E
01111110 - 7E
01111110 - 7E
01111110 - 7E
01111110 - 7E
01111110 - 7E
01111110 - 7E
01111110 - 7E

Body Turn
01111110 - 7E
01111111 - 7F
01111111 - 7F
01111111 - 3F
00111111 - 1F
00000000 - 00

Head
00011000 - 18
00111100 - 3C
01111110 - 7E
01011010 - 5A
01011010 - 5A
01111110 - 7E
01111110 - 7E
01111110 - 7E

Tail
01111110 - 7E
01111110 - 7E
01111110 - 7E
01111110 - 7E
00111100 - 3C
00111100 - 3C
00011000 - 18
00011000 - 18

Fruit
0000 0111 - 07
0001 1100 - 1C
0011 1000 - 38
0111 1100 - 7C
0111 1100 - 7C
0111 1100 - 7C
0011 1000 - 38
0000 0000 - 00



*/

#endif // !GRAPHICS_H