/* problem4.c
    Project Euler:
		Largest palindrome product
    Prepared by:
        Adem Yıldız
*/

#include<stdio.h>

int is_palindrome(int);

int main()
{
	int i = 0, numberFirst, numberSecond, result, numbersPalindrome[100];
	/* multiplying two numbers in sequence
		to find palindrome numbers and store them in array */
	for(numberFirst = 900; numberFirst<=999; numberFirst++){       
		for(numberSecond = 900; numberSecond<=999; numberSecond++){
			result = numberFirst*numberSecond;
			if( is_palindrome(result) ){
				numbersPalindrome[i] = result;
				i++;
			}
		}
	}
	//finding largest element in array
	int k = 0, max, min;
	max = numbersPalindrome[0];
	for(k = 1; k<i; k++){
		if(numbersPalindrome[k]>max)
			max = numbersPalindrome[k];
	}
	printf("largest palindrome number is %d", max);
	return 0;
}

int is_palindrome(int number)
{
	int reserved, reminder, check = 0;
	reserved = number;
	while(reserved != 0){
		reminder = reserved%10;        
		check = check*10 + reminder;	//writing number reversely
		reserved = reserved/10;        //getting rid of last number
	}
	if(check==number)
		return 1;
	else
		return 0;
}
