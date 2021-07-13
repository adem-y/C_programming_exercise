/* problem5.c
    Project Euler:
		Smallest multiple
    Prepared by:
        Adem Yýldýz
*/
#include<stdio.h>
#include<limits.h> //added to use INT_MAX

int main()
{
	int number, smallest, divider, reminder, count = 0;
	for(number = 1000; number<INT_MAX; number++){   //taking numbers respectively
		for(divider = 1; divider<=20; divider++){   //checking remainders 1 to 20
			if(number%divider == 0){
				count++;
			}
		}
		if(count==20){                              //this means all dividers 1 to 20 remainds 0
			smallest = number;                     //and first number to achive this is the smallest
			break;								  //no need to go on
		}
		count = 0;
	}
	
	printf("smallest number is %d", smallest);
	return 0;
}
