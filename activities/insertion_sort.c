#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{

    int data;
    struct node* next;
}node;

node* createnewnode(int data){

    node* newnode = malloc(sizeof(node));
    newnode->next = NULL;
    newnode->data = data;

    return newnode;
}

void linknodes(node** head, node* nextnode){

    if(*head == NULL){
        nextnode->next = *head;
        *head = nextnode;
    }else{
        node* ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = nextnode;
    }
}

void display(node* head){
    
    node* ptr = head;

    while(ptr != NULL){
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");

}

void insertion_sort(node** head){

    node* curr1 = *head;
    node* curr2 = NULL;
    node* prev1 = NULL;
    node* prev2 = NULL;
    node* next = NULL;
    int min = 0;
    bool swapped = true;

    while(curr1->next != NULL){

        next = curr1->next;
        curr2 = next;
        min = curr1->data;
        while(curr2->next != NULL){

            if(min > curr2->data){
                min = curr2->data;
            }

            prev2 = curr2;
            curr2 = curr2->next;
        }

        
        curr1->next = curr2->next;
        prev1->next = curr2;
        prev2->next = curr1;
        curr2->next = next;

        prev1 = curr1;
        curr1 = next;        

        
    }

}

int main(){
    node* head = NULL;
    
    
    node* n1 = createnewnode(1);
    linknodes(&head, n1);
    node* n2 = createnewnode(3);
    linknodes(&head, n2);
    node* n3 = createnewnode(10);
    linknodes(&head, n3);
    node* n4 = createnewnode(23);
    linknodes(&head, n4);
    node* n5 = createnewnode(12);
    linknodes(&head, n5);
    node* n6 = createnewnode(2);
    linknodes(&head, n6);
    node* n7 = createnewnode(8);
    linknodes(&head, n7);
    node* n8 = createnewnode(9);
    linknodes(&head, n8);

    printf("UNSORTED LINKED LIST\n");
    display(head);
    printf("SORTED LINKED LIST\n");
    insertion_sort(&head);
    display(head);

}