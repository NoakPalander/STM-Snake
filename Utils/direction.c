#include "direction.h"


bool direction_equals(DIRECTION d1, DIRECTION d2) {
    return d1.dx == d2.dx && d1.dy == d2.dy;
}

DIRECTION get_direction(unsigned char input, DIRECTION prev) {
    DIRECTION dir;
    
    switch (input) {
        // Move up
        case 2:
            dir = UP;
            break;

        // Move left
        case 4:
            dir = LEFT;
            break;

        // Move right
        case 6:
            dir = RIGHT;
            break;
            
        // Move down
        case 8:
            dir = DOWN;
            break;
        
        default:
            dir = prev;
            break;
    }
    
    // Can't press opposite direction
    if (direction_equals(dir, (DIRECTION) { .dx = -prev.dx, .dy = -prev.dy }))
        dir = prev;
    
    // Return new direction
    return dir;
}