#include "rng.h"


static uint64_t rng_state = 0xcafef00dd15ea5e5ul;
uint64_t const rng_default_seed = 0xcafef00dd15ea5e5ul;

uint64_t rng_next(void) {
    uint64_t x = rng_state;
    rng_state = x * 6364136223846793005ul;
    x ^= x >> 22;
    return x;
}

void rng_init(uint64_t seed){
    rng_state = 2 * seed + 1;
    (void)rng_next(); // drop first number per standard
}

// Voodoo magic