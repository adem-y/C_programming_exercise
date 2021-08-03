/* linked_list.c
 * author: Adem YILDIZ
 */

#include "linked_list.h"
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data; // info in the node
    struct node *nextptr; // addres of next data
}*default_node;


void createList( int n ){
    struct node *new_node, *temp;
    int num, i;

    // creating first node
    default_node = (struct node *)malloc(sizeof(struct node));

    if(default_node == NULL){ printf("it's empty!!"); }
    else {
        printf("enter data for node 1: ");
        scanf("%d", &num);
        default_node -> data = num;
        default_node -> nextptr = NULL; // because this is the only node

        temp = default_node; // let's keep it here
        // adding new nodes:
        for(i=2; i<=n; i++){
            new_node = (struct node *)malloc(sizeof(struct node));

            if(new_node == NULL) { printf("it's empty!!"); }
            else{
                printf("input data for node %d: ", i);
                scanf("%d", &num);

                new_node -> data = num;
                new_node -> nextptr = NULL; // now, this is last node

                temp -> nextptr = new_node; // node I created before will point the node I added
                temp = temp -> nextptr; // let's keep it here
            }
        }
    }
}

void displayList(){
    struct node *temp;
    if(default_node == NULL){ printf("it's empty!!"); }
    else {
        temp = default_node; // let's keep this here
        while (temp != NULL) {
            printf(" | %d | ", temp->data);
            temp = temp -> nextptr; // going to next node
        }
    }
}

void reverseList(){
    struct node *prev_node, *next_node;
    /* what i basically do here is reversing pointers
    * so that the first node will be the last node
    * to do that i defined prev_node and cur_node */
    prev_node = NULL;
    while(default_node != NULL){
        next_node = default_node->nextptr;
        default_node->nextptr = prev_node;
        prev_node = default_node;
        default_node = next_node;
    }
    default_node = prev_node;

}

void countNodes(){
    int counter = 0;
    struct node *temp;
    temp = default_node;

    while( temp != NULL){
        counter++;
        temp = temp -> nextptr;
    }

    printf("\n\nThere are %d nodes in the list.\n", counter);
}

void insertNodeBeginning(int num){
    struct node * new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){ printf("it's empty!!"); }
    else {
        new_node -> data = num;
        new_node -> nextptr = default_node; // points the first node
        default_node = new_node; // becomes the first node
    }
}

void insertNodeEnd(int num){
    struct node * new_node, *temp;

    new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node == NULL){ printf("it's empty!!"); }
    else{
        new_node -> data = num; // i got the data
        new_node -> nextptr = NULL; // since it's the last node it should point to NULL

        temp = default_node; // will be used to access the last node
        while ( temp->nextptr != NULL ){
            temp = temp->nextptr;
        }
        temp->nextptr = new_node; // last node will point the new node I added
    }
}
