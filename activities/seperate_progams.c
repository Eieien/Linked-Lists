#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node{

    char name[20];
    char program[10];
    struct node* link;

}node;

void insertsorted(node** head, node* newnode){

    // node** trav;
    // for(trav = head; *trav != NULL && strcmp((*trav)->name, newnode->name) < 0; trav = &((*trav)->link)){}
    // newnode->link = *trav;
    // *trav = newnode;

    if(*head == NULL){
        newnode->link = *head;
        *head = newnode;
    }else{
        node* curr = *head;
        
        while(strcmp(curr->name, newnode->name) < 0){
            curr = curr->link;
        }

        newnode->link = curr->link;
        curr->link = newnode;


    }


}

node* createnewnode(char* name, char* program){

    node* newnode = malloc(sizeof(node));

    strcpy(newnode->name, name);
    strcpy(newnode->program, program);

    newnode->link = NULL;

    return newnode;

}

void display(node* head){
    node* ptr = head;

    if(head == NULL){
        printf("LIST IS EMPTY!!!\n");
        return;
    } 
    printf("NAME\tPROGRAM\n");

    while(ptr != NULL){
        printf("%s\t%s\n", ptr->name, ptr->program);
        ptr = ptr->link;
    }
    printf("\n");
}

void display_common_names(node* IT, node* IS){
    node* currIT = IT;
    node* currIS = IS;
    int flag = 0;

    if(currIT == NULL || currIS == NULL){
        printf("NO COMMON NAMES!!!\n");
        return;
    }

    while(currIT != NULL){
        currIS = IS;
        while(currIS != NULL){

            if(strcmp(currIT->name, currIS->name) == 0){
                printf("%s\t%s\n", currIT->name, currIT->program);
                printf("%s\t%s\n", currIS->name, currIS->program);
                flag = 1;
            }
            currIS = currIS->link;
        }

        currIT = currIT->link;
    }

    if(flag == 0){
        printf("NO COMMON NAMES!!!\n");
    }
}


int main(){

    node* IT = NULL;
    node* IS = NULL;
    int size;
    char name[20];
    char program[20];
    printf("How many students do you want to list\n> ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){

        printf("[Student %d] First Name: ", i + 1);
        scanf("%s", name);
        printf("[Student %d] Program: ", i + 1);
        scanf("%s", program);
        printf("\n");

        node* newnode = createnewnode(name, program);
        
        if(strcmp(newnode->program, "IS") == 0){
            insertsorted(&IS, newnode);
        }else if(strcmp(newnode->program, "IT") == 0){
            insertsorted(&IT, newnode);
        }else{
            printf("PROGRAM NOT FOUND");
        }
    }

    printf("===IT STUDENTS===\n");
    display(IT);
    printf("===IS STUDENTS===\n");
    display(IS);

    printf("===COMMON NAMES===\n");
    display_common_names(IT, IS);
    

    return 0;
}