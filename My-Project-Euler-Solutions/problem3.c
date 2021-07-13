/* problem3.c
    Project Euler:
        Largest Prime Factor
    Prepared by:
        Adem Yýldýz
*/

#include<stdio.h>

int main()
{
	unsigned long long number = 600851475143;
	//unsigned long long number = 1030;
	int i, j, c=0, k=0;
	int prime[50];
	
	for(i=2ULL; i<=number; i++){
		c=0;
		if(number%i==0){
			for(j=1; j<i; j++){
				if(i%j==0){
					c++;
				}
			}
			if(c<2){
				prime[k] = i;
				k++;
			}
		}
	}
	
	for(i=0; i<k; i++){
		printf("%llu ", prime[i]);
	}
	
	return 0;
}
