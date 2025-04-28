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

void display(node* head){
    
    while(head != NULL){
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("\n");
}

node* range(node* head, int min, int max){

    node* curr = head;
    int flag = 0;
    while(curr!= NULL){
        if(curr->data >= min && flag == 0){
            // printf("RAWr");
            head = curr;
            flag = 1;
        }

        if(curr->next->data >= max && flag == 1){
            curr->next = NULL;
        }
        curr = curr->next;
    }

    return head;

}

int main(){

    int size;
    int min =2, max = 300;
    node* head = NULL;
    printf("Enter size: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        node* newnode = createnewnode(i * 30);
        
        if(head == NULL){
            newnode->next = head;
            head = newnode;
        }else{
            node* ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }

    display(head);
    head = range(head, min, max);
    display(head);



    return 0;
}