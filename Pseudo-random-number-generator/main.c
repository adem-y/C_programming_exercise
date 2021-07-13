/*
    "main.c"

    Prepared by:
        Adem YILDIZ
        1801022058

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "myrand.h"

int main()
{
    int i;
    myrand_seed(333);                        // initializing with an arbitrary seed value
    // seed (start value) value must be smaller than modulus value
    for(i=0; i<50; i++)
        printf(">%d\n", myrand()%15 +1);    // number should be [1,15] therefore we increase +1 to avoid 0
    return 0;
}
