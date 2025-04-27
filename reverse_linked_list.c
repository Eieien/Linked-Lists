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

void reverse(node** head){

    node* ptr = *head;
    node* prev = NULL;
    node* next = NULL;
    while(ptr != NULL){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    *head = prev;
}

void swap(node** head,int pos1, int pos2){

    int count = 1;
    node* ptr = *head;
    node* prev = *head;
    node* temp = NULL;
    node*tempnext = NULL;
    node* tempprev = NULL;

    while(ptr != NULL){
        prev = ptr;

        if(count == pos1){
            temp = ptr;
            tempprev = prev;
            tempnext = ptr->next;
            
        }else if(count == pos2){
            prev->next = tempprev;  
        }
    }
    
}

int main(){
    
    node* head = NULL;
    node* n1 = createnode(1);
    node* n2 = createnode(2);
    node* n3 = createnode(3);
    node* n4 = createnode(4);
    node* n5 = createnode(5);
    node* n6 = createnode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    head = n1;

    display(head);
    reverse(&head);
    display(head);
    swap(&head, 3, 5);
    display(head);

}