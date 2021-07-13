/*
    "myrand.h"

    Prepared by:
        Adem YILDIZ
        1801022058

*/

#ifndef MYRAND_H
#define MYRAND_H

// this special numbers are from a source which is numerical recipes
#define mod (4294967296)          // modulus = (2^32)
#define product (1664525)         // multiplier
#define inc (1013904223)          // increment

int myrand(void);                 // function to generate random number
void myrand_seed(int seed);       // function to assign next to seed (start value)
#endif  // MYRAND_H
