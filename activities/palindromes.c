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

int nodelen(node* head){
    
    node* ptr = head;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }

    return count;
}

bool ispalindrome(node* head){
    node* curr = head;
    int len = nodelen(head);
    node* arr[len];
    int index = 0;
    while(curr != NULL){
       arr[index] = curr;
       index++;
       curr = curr->next;
    }
    for(int i = 0 ; i < len/2; i++){
        if(arr[i]->data != arr[len - i - 1]->data) return false;
    }

    free(arr);
    return true;
    
}

int main(){

    node* head = NULL;

    int size = 0;
    int data;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter data for node datas\n> ");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        node* newnode = createnewnode(data);
        linknodes(&head, newnode);
    }

    display(head);
    bool ispal = ispalindrome(head);
    if(ispal){
        printf("True");
    }else{
        printf("FALSE");
    }
    printf("RAWR");

    return 0;
}