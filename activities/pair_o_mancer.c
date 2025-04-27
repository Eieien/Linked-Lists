#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node* next;

}node;

node* createnode(int data){
    node* newnode = malloc(sizeof(node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void linknodes(node** head, node* targetnode){

    if(*head == NULL){
        targetnode->next = *head;
        *head = targetnode;
    }else{
        node* ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = targetnode;
    }
}

void display(node* head){

    node* ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void sort(node** head){

    node* curr = *head;
    node* next = NULL;
    node* prev = NULL;
    bool swapped = true;

    do{
        swapped = false;
        curr = *head;
        prev = NULL;

        while(curr->next != NULL){
            next = curr->next;
            if(curr->data > next->data){

                if(prev == NULL){
                    curr->next = next->next;
                    next->next = curr;
                    *head = next;
                }else{
                    curr->next = next->next;
                    next->next = curr;
                    prev->next = next;
                }
                prev = next;    
                swapped = true;
            }else{
                prev = curr;
                curr = next;
            }

        }


    }while(swapped);

}

void groupclosestpair(node** head){

    node* ptr = *head;
    int count = 1;
    printf("Closest Pairs: \n");
    while(ptr != NULL){
        if(count == 1){
            
            printf("(");
            printf("%d, ", ptr->data);
            count++;
            if(ptr->next == NULL) printf("-)");
        }else{
            
            count--;
            printf("%d", ptr->data);
            printf(")\n");
        }
        ptr = ptr->next;
    }
}

void twosum(node** head){
    node* ptr = *head;
    
}

int main(){

    node* head = NULL;
    int size = 0;
    int data = 0;

    printf("Enter Size: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        printf("Enter Data of Node %d: ", i + 1);
        scanf("%d", &data);
        node* newnode = createnode(data);
        linknodes(&head, newnode);
    }    

    display(head);
    // sort(&head);
    display(head);
    // groupclosestpair(&head);

    return 0;
}