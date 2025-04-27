#include<stdio.h>
#include<stdlib.h>

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

void deletefirst(node** head){

    node* ptr = *head;

    *head = ptr->next;
    free(ptr);
    
}

void deletelast(node** head){

    node* ptr = *head;

    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }

    free(ptr->next);
    ptr->next = NULL;
}

void deleteposition(node** head, int position){
    node* ptr = *head;
    node* prev = NULL;
    if(position == 1){
        *head = ptr->next;
        free(ptr);
    }else{
        for(int i = 1; i < position; i++){
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = ptr->next;
        free(ptr);
    }
}

int listlen(node** head){
    int len = 0;
    node* ptr = *head;

    while(ptr != NULL){
        ptr = ptr->next;
        len++;
    }

    return len;
}

void deletemiddle(node** head){
    node* ptr = *head;
    node* prev = NULL; 
    
    int len = listlen(head);

    for(int i = 1; i < (len / 2); i++){
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = ptr->next;
    free(ptr);
}

int main(){

    node *head = NULL;
    node *n1 = createnode(1);
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
    deletefirst(&head);
    display(head);
    deletelast(&head);
    display(head);
    deletemiddle(&head);
    display(head);

    return 0;
}