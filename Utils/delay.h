#ifndef DELAY_H
#define DELAY_H

// Represents a time unit
typedef enum {
    seconds,
    milliseconds,
    microseconds,
    nanoseconds
} time_unit;

// Causes a delay for 'amount' unit's, lowest capable delay is 250ns
// This invokes undefined behavior if any other time unit is used
// Ideally this wouldnt be semantically possible but the C type-system is a joke
void delay(unsigned int amount, time_unit unit);

#endif // !DELAY_H