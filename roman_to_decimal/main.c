/* roman_to_decimal.h
 * author: Adem YILDIZ
 */

#include "roman_to_decimal.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("please before enter number's order\n");
    scanf("%d", &N);
    printf("enter the roman number: ");
    char roman_number[10];
    scanf("%s", &roman_number);
    int decimal_number = whole_number_roman_to_integer(roman_number);
    printf("\n\n%s = %d\n", roman_number,decimal_number);
    return 0;
}
