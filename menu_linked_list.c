#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* createnewnode(int data){

    node* newnode = malloc(sizeof(node));
    if(!newnode){
        printf("MEM ALLOC ERROR!");
        return NULL;
    }

    newnode->data = data;
    newnode->next = NULL;
}

void display(node* head){
    
    if(head == NULL){
        printf("No Linked list found!\n\n");
        return;
    }

    node* ptr = head;
    while(ptr !=NULL){
        printf("%d-->",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void InsertAtBeginning(node** head, int data){
    
    node* ptr = *head;
    node* newnode = createnewnode(data);

    newnode->next = *head;
    *head = newnode;    
}

void InsertEnd(node** head, int data){
    node* ptr = *head;
    node*newnode = createnewnode(data);
    if(*head == NULL){
        newnode->next = *head;
        *head = newnode;
    }else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void Insertposition(node** head, int data, int pos){

    node* ptr = *head;
    node* newnode = createnewnode(data);
    
    if(pos == 1){
        newnode->next = *head;
        *head = newnode;
    }else{
        for(int i = 2; i < pos; i++){
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}

void deleteBeginning(node** head){
    
    if(*head == NULL){
        printf("LIST IS EMPTY, NOTHING TO DELETE\n");
        return;
    }
    node* ptr = *head;
    *head = ptr->next;
    free(ptr);
    printf("\nNODE HAS BEEN DELETED\n");

}

void deleteEnd(node** head){
    
    if(*head == NULL){
        printf("LIST IS EMPTY, NOTHING TO DELETE\n");
        return;
    }

    node* ptr = *head;
    node* prev = NULL;

    while(ptr->next != NULL){
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = ptr->next;
    free(ptr);
    printf("\nNODE HAS BEEN DELETED\n");

}

void deleteatpos(node** head, int pos){
    if(head == NULL){
        printf("LIST IS EMPTY, NOTHING TO DELETE\n");
        return;
    }
    node* ptr = *head;
    node* prev = NULL;

    if(pos == 1){
        *head = ptr->next;
        free(ptr);
    }else{
        for(int i = 1; i < pos; i++){
            if(ptr->next != NULL){
                prev = ptr;
                ptr = ptr->next;
            }
        }

        prev->next = ptr->next;
        free(ptr);
    }
    printf("\nNODE HAS BEEN DELETED\n");

}

void reverse(node** head){
    if(*head == NULL){
        printf("LIST IS EMPTY, CANNOT REVERSE\n");
        return;
    }
    
    node* ptr = *head;
    node* next = NULL;
    node* prev = NULL;
    
    while(ptr != NULL){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }

    *head = prev;
    printf("\nLIST HAS BEEN REVERSED\n");

}

void swap(node** head, int pos1, int pos2){

    node* curr1 = *head;
    node* curr2 = *head;
    node* prev1 = NULL;
    node* prev2 = NULL;

    for(int i = 1;  i < pos1 && curr1->next != NULL; i++){
        prev1 = curr1;
        curr1 =  curr1->next;
    }

    for(int i = 1 ; i < pos2 && curr2 != NULL; i++){
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if(curr1 == NULL || curr2 == NULL){
        printf("ERROR. A POSITION IS OUT OF BOUNDS!");
        return;
    }

    if(prev1 != NULL){
        prev1->next = curr2;
    }else{
        *head = curr2;
    }

    if(prev2 != NULL){
        prev2->next = curr1;
    }else{
        *head = curr1;
    }

    node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;

    printf("Successfully swapped positions %d and %d\n", pos1, pos2);
}

void sort(node** head){

    if((*head) == NULL){
        printf("List is empty\n");
        return;
    }
    
    node** ptr;
    node* next;
    node* curr;
    bool swapped = true;
    
    do{
        ptr = head;
        swapped = false;
        while((*ptr)->next != NULL){
            curr = *ptr;
            next = curr->next;

            if(curr->data > next->data){
                curr->next = next->next;
                next->next = curr;
                *ptr = next;
                swapped = true;
            }

            ptr = &((*ptr)->next);


        }

    }while(swapped);

    printf("List has been sorted\n");
}

int main(){

    node* head = NULL;
    int choice;
    int data;
    int pos;
    int pos1, pos2;

    while(1){
        printf("===Create your own linked list===\n\n");
        printf("===OPTIONS===\n");
        printf("[1]  Display Linked list\n");
        printf("[2]  Insert at Beginning\n");
        printf("[3]  Insert at End\n");
        printf("[4]  Insert at position\n");
        printf("[5]  Delete Beginning\n");
        printf("[6]  Delete at End\n");
        printf("[7]  Delete at position\n");
        printf("[8]  Reverse the list\n");
        printf("[9]  Swap two nodes\n");
        printf("[10] Sort the nodes");
        printf("\n> ");
        scanf(" %d", &choice);
        switch(choice){
            case 1:
                if(head !=NULL){
                    printf("Displaying List:\n");
                }
                display(head);
                break;
            case 2:
                printf("===INSERTING AT THE BEGINNING===\n");
                printf("Enter Data: ");
                scanf("%d", &data);
                InsertAtBeginning(&head, data);
                printf("\n===New List===\n");
                display(head);
                break;
            case 3:
                printf("===INSERTING AT THE END===\n");
                printf("Enter Data: ");
                scanf("%d", &data);
                InsertEnd(&head, data);
                printf("\n===New List===\n");
                display(head);
                break;
            case 4:
                printf("===INSERTING AT A POSITION===\n");
                printf("Enter Position you want to insert: ");
                scanf("%d", &pos);
                printf("Enter Data: ");
                scanf("%d", &data);
                Insertposition(&head, data, pos);
                printf("\n===New List===\n");
                display(head);
                break;
            case 5:
                printf("===DELETE BEGINNING===\n");
                deleteBeginning(&head);
                printf("\n===New List===\n");
                display(head);
                break;
            case 6:
                printf("===DELETE END===\n");
                deleteEnd(&head);
                printf("\n===New List===\n");
                display(head);
                break;
            case 7:
                printf("===DELETE AT A POSITION===\n");
                printf("Enter Position you want to delete: ");
                scanf("%d", &pos);
                deleteatpos(&head, pos);
                printf("\n===New List===\n");
                display(head);
                break;
            case 8:
                printf("===REVERSING THE LIST===\n");
                reverse(&head);
                printf("\n===New List===\n");
                display(head);
                break;
            case 9:
                printf("===SWAPPING TWO NODES IN THE LIST===\n");
                printf("Enter two positions to swap: ");
                scanf("%d %d", &pos1, &pos2);
                swap(&head, pos1, pos2);
                printf("\n===New List===\n");
                display(head);
                break;
            case 10:
                printf("===SORT THE NODES OF THE LIST===\n");
                sort(&head);
                printf("\n===New List===\n");
                display(head);
                break;
            default:
                printf("ERROR, OPTION NOT FOUND!...\n");
                break;
        }


    }

    return 0;
}