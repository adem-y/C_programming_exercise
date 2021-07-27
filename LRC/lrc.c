/*
    lrc.c
    author: Adem YILDIZ

    Longitudinal redundancy check
    An easy program with an algorithm based on parity bit manipulation
*/

#include<stdio.h>
#include<conio.h>

void parity(int [], int []);

int arr_1[8], arr_2[8], parityarr[8], i;

int main(){
    int data_1[] = {1, 0, 1, 1, 0, 0, 1, 1};
    int data_2[] = {1, 1, 1, 0, 0, 1, 1, 0};

    parity(data_1, data_2);

    return 0;
}

void parity(int arr_1[], int arr_2[]){
    printf("\nEntered data:\n");

    for(i=7; i>=0; i--){ printf("%d", arr_1[i]); } // print first array
    printf("\n");

    for(i=7; i>=0; i--) { printf("%d", arr_2[i]); } // print second array
    printf("\n\n--------LRC--------\n");

    for(i=0; i<8; i++){
        if((arr_1[i]==0 && arr_2[i]==0) || (arr_1[i]==1 && arr_2[i]==1))
        {
            parityarr[i] = 0; // even parity
        }
        else if ((arr_1[i]==1 && arr_2[i]==0) || (arr_1[i]==0 && arr_2[i]==1))
        {
            parityarr[i] = 1; // odd parity
        }

    }

    for(i=7; i>=0; i--){
        printf("%d", parityarr[i]); // print LRC
    }
}
