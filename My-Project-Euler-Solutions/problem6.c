/* problem6.c
    Project Euler:
		Sum square difference
    Prepared by:
        Adem Y�ld�z
*/

#include<stdio.h>
#include<math.h>
#define LIMIT 100

int sumOfsquares(int);
int squareOfthesum(int);

int main()
{
	int difference;
	difference = squareOfthesum(LIMIT) - sumOfsquares(LIMIT);
	printf("%d - %d = %d", squareOfthesum(LIMIT), sumOfsquares(LIMIT), difference);
	return 0;
}

int sumOfsquares(int lastNumber)
{
	int i, sum = 0;
	for(i = 0; i<=lastNumber; i++)
		sum +=pow(i,2);
	return sum;
}

int squareOfthesum(int lastNumber)
{
	int i, sum = 0;
	for(i=0; i<=lastNumber; i++)
		sum+=i;
	return sum*sum;
}
