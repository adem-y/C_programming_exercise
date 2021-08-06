/* roman_to_decimal.c
 * author: Adem YILDIZ
 */

#include "roman_to_decimal.h"
#include<stdio.h>
#include<stdlib.h>

int to_integer(char x){
    switch(x){
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        return 0;
    }
}

int whole_number_roman_to_integer(char roman[]){

    int i, next=0, number=0, current=0;

    for ( i=0; i<N; i++ ){
        current = to_integer(roman[i]);
        if (next == current){
            number = number + next;
        }
        else{
            number = number + next + current;
        }
        next = to_integer(roman[i+1]);

        if ( (next > current) && (next != 0) ){
            number = number - 2*current;
        }

    }
    return number;
}
