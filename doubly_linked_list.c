#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;

}node;

node* createnode(int data){
    node* newnode = malloc(sizeof(node));
    
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void insertfirst(node** head, int data){
    // node* ptr = *head;
    node* newnode = createnode(data);
    if(*head != NULL){
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }else{
        newnode->next = *head;
        *head = newnode;
    }
}

void insertlast(node** head, int data){

}

void display(node* head){
    node* ptr = head;
    if(head == NULL){
        printf("\n\nList is empty\n\n");
        return;
    }
    printf("\n\nHEAD-->");
    while(ptr != NULL){
        printf("%d--->", ptr->data);
        ptr = ptr->next;
    }
    
    printf("NULL\n\n");
}

void navigate(node* head){
    node* ptr = head;
    int choice;
    if(head == NULL){
        printf("List is empty\n\n");
        return;
    }

    while(1){
        printf("Current: %d\n\n", ptr->data);
        printf("[1] Move Next\n");
        printf("[2] Move Back\n");
        printf("[3] Go back to main\n");

        scanf("%d", &choice);

        if(choice == 1 && ptr->next != NULL){
            ptr = ptr->next;
        }else if(choice == 2 && ptr->prev != NULL){
            ptr = ptr->prev;
        }else if(choice ==3){
            break;
        }else{
            printf("NONE");
        }

    }

}

int main(){
    int choice;
    int data;
    node* head = NULL;

    while(1){
        printf("===DOUBLY LINKED LIST===\n\n");
        printf("Menu: \n");
        printf("[1] Display List\n");
        printf("[2] Insert First\n");
        printf("[3] Navigate List\n");
        printf("[1] Display List\n");
        printf("\n\n> ");

        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("===Display List===");
                display(head);
                break;
            case 2:
                printf("===Insert First===\n\n");
                printf("Input data\n> ");
                scanf("%d", &data);
                insertfirst(&head, data);
                printf("Displaying new list: ");
                display(head);
                break;
            case 3:
                printf("===Navigate List===\n\n");
                navigate(head);
                break;
            default:
                printf("ERROR. CHOICE INVALID!\n\n");
                break;
        }
    }

    // insertfirst(&head, 1);
    // display(head);
    // insertfirst(&head, 2);
    // display(head);
    return 0;
}