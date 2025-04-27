#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node* next;

}node;

node* listcleaning(node* head){

    node* ptr = head;
    node* prev = NULL;
    node* cleaningnode = NULL;
    while(ptr != NULL){
        
        if(ptr->data == -1){
            cleaningnode = ptr->next;
            while(cleaningnode->data != -1 && cleaningnode != NULL){
                cleaningnode = cleaningnode->next;
            }
            if(prev == NULL){
                head = cleaningnode->next;
                ptr = head;
            }else{
                prev->next = cleaningnode->next;
                ptr = cleaningnode->next;
            }
        }else{
            prev = ptr;
            ptr = ptr->next;
        }
        
    }


    return head;

}

node* createnewnode(int data){
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void getInput(node** head){

    int size, data;
    printf("Input how many items in the Linked list: ");
    scanf("%d", &size);
    printf("Input Linked List values: ");

    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        node* newnode = createnewnode(data);

        // Linking Nodes
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

}

void display(node* head){
    
    if(head == NULL) printf("None exists");

    node* ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;

        // if(ptr != NULL){
        //     printf("-->");
        // }
    }

    printf("\n");
}

int main(){
    
    node* head = NULL;

    getInput(&head);
    display(head);
    head = listcleaning(head);

    if(head == NULL){
        printf("Oh no Data is fully corrupted and cannot be recovered!");
    }else{
        printf("Cleaned Data: ");
        display(head);
    }

    return 0;
}