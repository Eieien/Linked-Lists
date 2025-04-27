#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;

}node;

node* createnode(int data){

    node* newnode = malloc(sizeof(node));
    
    if(!newnode){
        return NULL;
    }

    newnode->next = NULL;
    newnode->data = data;

    return newnode;
}

void display(node* head){

    node* ptr = head;
    while(ptr!=NULL){
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

void swap(node** head, int pos1, int pos2){
    
    node* ptr = *head;
    node* currpos1 = *head;
    node* prev1 = NULL;
    node* currpos2 = *head;
    node* prev2 = NULL;

    for(int i = 1; i < pos1 && currpos1 != NULL; i++){
        prev1 = currpos1;
        currpos1 = currpos1->next;
    }

    for(int i = 1; i < pos2 && currpos2 != NULL; i++){
        prev2 = currpos2;
        currpos2 = currpos2->next;
    }

    if(currpos1 == NULL || currpos2 == NULL){
        printf("POSITION NOT FOUND");
        return;
    }

    if(currpos1 != NULL){
        prev2->next = currpos1;
    }   

    if(currpos2 != NULL){
        prev1->next = currpos2;
    }

    node* temp = currpos1->next;
    currpos1->next = currpos2->next;
    currpos2->next = temp;

}

void sort(node** head){
    
    node** outerptr;
    node* ptr = NULL;
    node* next = NULL;
    bool swapped = true;

    do{
        swapped = false;
        outerptr = head;

        while((*outerptr)->next != NULL){
            ptr = *outerptr;
            next = ptr->next;

            if(ptr->data > next->data){
                ptr->next = next->next;
                next->next = ptr;
                *outerptr = next;

                swapped = true;
            }
                outerptr = &((*outerptr)->next);
            
        }
        

    }while(swapped);
    
}


int main(){

    node *head = NULL;
    node *n1 = createnode(19);
    node *n2 = createnode(2);
    node *n3 = createnode(3);
    node *n4 = createnode(4);
    node *n5 = createnode(5);
    node *n6 = createnode(6);
    node *n7 = createnode(7);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;

    head = n1;
    display(head);
    swap(&head, 2, 4);
    printf("SWAPPED\n");
    display(head);
    sort(&head);
    printf("SORTED\n");
    display(head);



    return 0;
}