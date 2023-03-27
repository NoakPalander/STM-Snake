#ifndef RNG_H
#define RNG_H

#include <stdint.h>

extern uint64_t const rng_default_seed;

// Initializes the random engine
void rng_init(uint64_t seed);

// Retrieves the next random number
uint64_t rng_next(void);

#endif // !RNG_H