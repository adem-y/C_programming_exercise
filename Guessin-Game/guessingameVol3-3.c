/* guessingameVol3-2.c
   author: Adem YILDIZ
   
   this is a very beginner code. my intent was practicing more c.
   */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int randomizedNumber;
void menu(void);
int randomNumber(void);
int playTheGame(void);

int main()
{
    menu();
    playTheGame();
}

int randomNumber(void)
{
    int number;
    srand(time(NULL));
    return number = rand()%100; //random number generated
}

int playTheGame(void)
{
    int difference, guess, counter, c;

    playagain:
    randomizedNumber = randomNumber();
    counter = 1;

    while (counter < 6){

        printf("\n\tTRY NUMBER %d\n", counter);
        scanf("%d", &guess);
        counter++;

        difference = abs(randomizedNumber - guess); //absolute

        if (difference == 0){
            system("cls");
            printf("\nYOU NAILED IT! NUMBER WAS %d\n", randomizedNumber);
            printf("\nIf you wanna play again press 1!\n");

            scanf("%d", &c);
            if (c == 1){
                system("cls");
                goto playagain;
            }
            else
                return 0;
        }

        if (difference != 0){
            if (difference >= 20){
                system("cls");
                printf("FREEZING!!!\n");
            }
            else if (difference >= 15 && difference < 20){
                system("cls");
                printf("COLD!!\n");
            }
            else if(difference >= 10 && difference < 15){
                system("cls");
                printf("MAYBE NOT THAT COLD\n");
            }
            else if(difference >= 5 && difference < 10){
                system("cls");
                printf("YOU ARE HOT!!\n");
            }
            else if(difference > 0 && difference < 5){
                system("cls");
                printf("IT'S LIKE SAHARA DESERT!!!\n");
            }
        }
    }
    
    system("cls");
    printf("GAME OVER!!\nNUMBER WAS %d\n", randomizedNumber);

    printf("\nIf you wanna play again press number 1!\n");
    scanf("%d", &c);
    if (c == 1){
        system("cls");
        goto playagain;
    }
    else
        return 0;
}

void menu(void)
{
    printf("\tGUESS THE NUMBER FROM 0 TO 100\n");
	printf("\tYOU HAVE 5 RIGHTS TO GUESS\n");
    printf("\tIf the difference is 20 then it's FREEZING!\n");
    printf("\tIf the difference is between 15 and 20 then it's COLD\n");
    printf("\tIf the difference is between 10 and 15 then MAYBE NOT THAT COLD\n");
    printf("\tIf the difference is between 5 and 10 then YOU ARE HOT!!!\n");
    printf("\tIf the difference is between 0 and 5 you're in SAHARA!\n");
}
