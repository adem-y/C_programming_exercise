/*
    "myrand.c"

    Prepared by:
        Adem YILDIZ
        1801022058

*/

#include "myrand.h"
#include<stdio.h>
#include<stdlib.h>

int nextNumber;                                       // integer to store randomized number
int myrand(void)
{
    nextNumber = (nextNumber * product + inc)%mod;    // linear congruential generator
    if(nextNumber < 1)                                // otherwise multiplying will get lower
        myrand();                                     // if next<1 don't return that number and run myrand again
    return nextNumber;
}

void myrand_seed(int seed)
{
    nextNumber = seed;                                 // updating seed (start value) to next
}
