/*  crc.c
 *  Adem YILDIZ
 *  I created the function with the algorithm in barrgroup.com and pololu.com
 */

#include "crc.h"

// parameters
#define WIDTH (8*sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))

crc _crc_(unsigned char const message[], int nBytes){
    crc remainder = INITIAL_REMAINDER;
    int byte;
    unsigned char bit;

    // first thing to do: modulo-2 division
    for( byte = 0; byte < nBytes; ++byte){

        remainder ^= message[byte] << (WIDTH -8);
        // modulo-2 division again
        for(bit = 8; bit > 0; --bit){
            if ( remainder & TOPBIT){
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else{
                remainder = (remainder << 1);
            }
        }
    }

    return (remainder ^ FINAL_XOR_VALUE);
}
