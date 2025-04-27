#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

    node* ptr = head;
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

}

bool ispalindrome(){

}

int main(){

    node* head = NULL;

    int size = 0;
    int data;

    printf("Enter size: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        node* newnode = createnewnode(data);
        linknodes(&head, newnode);
    }

    display(head);

    return 0;
}