/* problem7.c
    Project Euler:
		10001st prime
    Prepared by:
        Adem Yýldýz
*/

#include<stdio.h>
#include<limits.h>

int main()
{
	int number, i, k = 0, c = 0;
	int primeNumbers[1000];
	for(number = 1; number<8700; number++){
		for(i=2; i<1000; i++){
			if(number%i == 0){
				c++;
			}
		}
		if(c==1){
			primeNumbers[k] = number;
			k++;
		}
		c = 0;
	}
	/*
	printf("which prime number would like to see?\n");
	int x;
	scanf("%d", &x);*/
	int x;
	for(x = 100; x<=1000; x=x+50)
		printf("%dinci prime number is %d\n", x, primeNumbers[x-1]);
	return 0;
}
