/*
 * gamblin_vol3.c
 * adem yildiz
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int randomNumber(void);
void menu(void);

void comparison(int,int,int);
void askBudget(void);
void updateGambleMoney(void);

int budget = 0;
int gambleMoney = 1;
char answer[10]; //this is used for updating bet

int main()
{
    int choice, number1, number2, number3, number4;

    menu();
    askBudget();

    system("cls");
    number1 = randomNumber();

    printf("\n---------> FIRST NUMBER IS %d <---------\n", number1);
    printf("next number is higher or lower?\n");
    printf("press 1 if it's higher, 0 if it's lower, 2 if they're same\n");
    scanf("%d", &choice);    
    
    system("cls");
    number2 = randomNumber();
    comparison(number1, number2, choice);
    printf("\n---------> SECOND NUMBER WAS %d <---------\n", number2);

    if( budget == 0){
        printf("\n---------> YOU'RE OUT OF MONEY! BYE! <---------\n");
        return 0;
    }

    updateGambleMoney();
    printf("next number is higher or lower?\n");
    printf("press 1 if it's higher, 0 if it's lower, 2 if they're same\n");
    scanf("%d", &choice);    
    
    system("cls");
    number3 = randomNumber();
    comparison(number2, number3, choice);
    printf("\n---------> THIRD NUMBER WAS %d <---------\n", number3);

    if( budget == 0){
        printf("\n---------> YOU'RE OUT OF MONEY! BYE! <---------\n");
        return 0;
    }    

    updateGambleMoney();
    printf("next number is higher or lower?\n");
    printf("press 1 if it's higher, 0 if it's lower, 2 if they're same\n");
    scanf("%d", &choice);    
    
    system("cls");
    number4 = randomNumber();
    comparison(number3, number4, choice);
    printf("\n---------> FOURTH NUMBER WAS %d <---------\n", number4);

    if( budget == 0){
        printf("\n---------> YOU'RE OUT OF MONEY! BYE! <---------\n");
        return 0;
    }

    printf("\nyour final budget is %d\n", budget);

    system("pause");
    return 0;
}

//////////////////////// functions /////////////////////////////////////

int randomNumber(void)
{
    int number;
    srand(time(NULL));
    return number = (rand()+5)%10; //random number generated
}

void menu(void)
{
    printf("******WELCOME******\n");
    printf("->First you will enter your budget and money you will bet\n");
    printf("->You will gamble on whether next number will be higher or lower than the number on screen\n");
    printf("->You must guess correct 3 in a row to make money\n");
}

void comparison(int currentNumber, int nextNumber, int guess)
{
    if( currentNumber > nextNumber ){
        if(guess == 0){
           printf("you got that damn right!\n");
           budget = budget + gambleMoney*2;
           printf("your updated budget is %d\n", budget);
        }
        else if(guess == 1){
           printf("maybe next time pal :)\n");
           printf("you know your budget was %d\n", budget);
        }
        else if(guess == 2){
           printf("maybe next time pal :)\n");
           printf("you know your budget was %d\n", budget);              
        }  
    }
    else if( currentNumber < nextNumber ){
        if(guess == 0){
           printf("maybe next time pal :)\n");
           printf("you know your budget was %d\n", budget);            
        }
        else if(guess == 1){
            printf("you got that damn right!\n");
            budget = budget + gambleMoney*2;
            printf("your updated budget is %d\n", budget);
        }
        else if(guess == 2){
           printf("maybe next time pal :)\n");
           printf("you know your budget was %d\n", budget);              
        }  
           
    }
    else if ( currentNumber == nextNumber ){
        if(guess == 0){
           printf("maybe next time pal :)\n");
           printf("you know your budget was %d\n", budget);            
        }
        else if(guess == 1){
           printf("maybe next time pal :)\n");
           printf("you know your budget was %d\n", budget); 

        }
        else if(guess == 2){
            printf("you got that damn right!\n");
            budget = budget + gambleMoney*4;
            printf("your updated budget is %d\n", budget);              
        }
    }    
}

void askBudget(void)
{
    while(gambleMoney > budget){
        printf("enter your budget: ");
        scanf("%d", &budget);

        printf("\n\nhow much you wanna bet? ");
        scanf("%d", &gambleMoney);

        if(gambleMoney > budget){
            system("cls");
            printf("you can't bet more than your budget, punk!\n");
        }
    }
    budget = budget - gambleMoney;
}

void updateGambleMoney(void)
{
    
    printf("\nwould you like to update your gamble money?\n");
    wrongAnswer:
    printf("write 'update' or 'same'\n");
    scanf("%s", answer);

    if( strcmp(answer, "update") == 0 ){

        printf("\nenter your bet: ");
        scanf("%d", &gambleMoney);

        while(gambleMoney > budget){
            printf("you can't bet more than your budget\n");
            printf("\nenter your bet: ");
            scanf("%d", &gambleMoney);
        }

        budget = budget - gambleMoney;
        printf(" and current budget is %d\n", budget);
    }

    else if( strcmp(answer, "same") == 0 ){

        while(gambleMoney > budget){
            printf("looks like you're broke!\n");
            printf("you can't bet more than your budget\n");
            printf("\nenter your bet: ");
            scanf("%d", &gambleMoney);
        }
        budget = budget - gambleMoney;
        printf("and current budget is %d\n", budget);

        if(gambleMoney < budget){
            printf("\nyour bet is still %d ", gambleMoney);
            printf("and current budget is %d\n", budget);
        }
    }

    else
        goto wrongAnswer;

}