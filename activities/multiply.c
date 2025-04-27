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

    node* ptr = head;
    while(ptr != NULL){
        printf("%d", ptr->data);
        if(ptr->next != NULL){
            printf("->");
        }
        ptr = ptr->next;
    }

    printf("\n");
}

void multiply(node** head){

    node* ptr = *head;
    node* next = NULL;
    node* newnode;
    while(ptr != NULL){
        next = ptr->next;
        if(ptr->data % 2 == 0){
            newnode = createnewnode(ptr->data * 2);
              
        }else{
            newnode = createnewnode(ptr->data + 1);
        }

        ptr->next = newnode;
        newnode->next = next;      
        ptr = next;

    }

}

int main(){

    int size = 0;
    int data;
    node* head = NULL;
    printf("Enter size: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        printf("Enter Data of Node %d: ", i + 1);
        scanf("%d", &data);
        node* newnode = createnewnode(data);
        linknodes(&head, newnode);

    }    

    display(head);
    multiply(&head);
    display(head);
    return 0;
}