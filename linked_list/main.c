/* main.c
 * author: Adem YILDIZ
 */

#include "linked_list.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    int k;
    printf("how many nodes?\n");
    scanf("%d", &k);

    createList(k);
    printf("\nList you created:\n");
    displayList();

    //reverse,
    reverseList();
    printf("\n\nList is reversed:\n");
    displayList();

    //count
    countNodes();

    printf("\n###################################\n");

    printf("\nEnter a number to add beginning of linked list: ");
    int num;
    scanf("%d", &num);
    insertNodeBeginning(num);
    displayList();


    printf("\n###################################\n");

    printf("\nEnter a number to add end of linked list: ");
    int num2;
    scanf("%d", &num2);
    insertNodeEnd(num2);
    displayList();

    return 0;
}
