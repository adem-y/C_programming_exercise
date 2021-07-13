/* problem2.c
    Project Euler:
        Even Fibonacci Numbers
    Prepared by:
        Adem Yýldýz
*/

#include<stdio.h>
#define LIMIT 4000000
int main()
{
	int num1=1, num2=1, num3;
	int sum = 0;
	
	while(num1<LIMIT){
		if(num1%2 == 0){
			printf("%d ", num1);
			sum+=num1;			
		}
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;
	}
	
	printf("\nsum of even numbers : %d", sum);
	return 0;
}
