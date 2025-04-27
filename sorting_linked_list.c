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

    while(ptr != NULL){
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

void sorting(node** head){

    node* ptr = *head;
    node* prev = NULL;
    node* temp = NULL;
    while(ptr != NULL){
        if(ptr->data > ptr->next->data){
            temp = ptr->next;
            ptr->next->data = ptr->data;
            ptr->data = temp->data;
        }
    }

    // *head = ptr;
}

int main(){
    
    node* head = NULL;
    node* n1 = createnode(1);
    node* n2 = createnode(6);
    node* n3 = createnode(1);
    node* n4 = createnode(8);
    node* n5 = createnode(2);
    node* n6 = createnode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    head = n1;

    display(head);
    sorting(&head);
    display(head);

}