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

    while(ptr != NULL){
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

void sorting(node** head){

    node** trav = head;
    node* next = NULL;
    node* curr;
    bool swapped = true;

    while(swapped){
        swapped = false;
        trav = head;
        while((*trav)->next != NULL){
            curr = *trav;
            next = curr->next;

            if(curr->data > next->data){
                curr->next = next->next;
                next->next = curr;
                *trav = next;
                swapped = true;
            }

            trav = &((*trav)->next);
        }
    }
}

int main(){
    
    node* head = NULL;
    node* n1 = createnode(9);
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