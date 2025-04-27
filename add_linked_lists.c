#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createnode(int data){
    node* newnode = malloc(sizeof(node));

    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void displaynodes(node* head){

    node* ptr = head;

    while(ptr != NULL){
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

}

void insertstart(node** head){
    
    node* newnode = createnode(5);
    node* ptr = *head;
    
    newnode->next = ptr;
    *head = newnode;

}

void insertLast(node** head){

    node* newnode = createnode(6);
    node* ptr = *head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = newnode;
}

void insertatposition(node** head, int pos){

    node* newnode = createnode(7);
    node* ptr = *head;

    for(int i = 2; i < pos; i++){
        ptr = ptr->next;
    }
    
    newnode->next = ptr->next;
    ptr->next = newnode;

}


int main(){

    node *head = NULL;
    node *n1 = createnode(1);
    node *n2 = createnode(2);
    node *n3 = createnode(3);
    node *n4 = createnode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    head = n1;
    
    displaynodes(head);
    insertstart(&head);
    displaynodes(head);
    insertLast(&head);
    displaynodes(head);
    insertatposition(&head, 3);
    displaynodes(head);


    return 0;
}