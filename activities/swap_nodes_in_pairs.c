#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;

}node;

node* createnewnode(int data){
    node* newnode = malloc(sizeof(node));
    
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void linknodes(node** head, node* newnode){

    if(*head == NULL){
        newnode->next = *head;
        *head = newnode;
    }else{
        node* ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }

}

void display(node* head){
    
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;        
    }

    printf("\n");
}

void swap_pairs(node** head){

    node* curr = *head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
    while(curr->next != NULL){
        next = curr->next;
        if(count % 2 == 0){

            if(prev == NULL){
                curr->next = next->next;
                next->next = curr;
                *head = next;
                prev = next;
            }else{
                curr->next = next->next;
                next->next = curr;
                prev->next = next;
            }
        }else{
            prev = curr;
            curr = next;
        }
        count++;
    }
}

int main(){

    node* head = NULL;

    for(int i = 1; i <= 11; i++){
        node* newN = createnewnode(i);
        linknodes(&head, newN);
    }

    display(head);
    swap_pairs(&head);
    display(head);




    return 0;
}