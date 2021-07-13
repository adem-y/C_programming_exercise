/* problem1.c
    Project Euler:
        Multiples of 3 and 5
    Prepared by:
        Adem Y�ld�z
*/

#include<stdio.h>
#define LIMIT 1000

int main()
{
    int sum=0, i;
    for(i=0; i<LIMIT; i++){
        if(i%3 == 0 || i%5 == 0){
        	//printf("%d\n", i);
			sum+=i;
		}
    }
    printf("\nthe sum of multiples is %d", sum);
    return 0;
}
