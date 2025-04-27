#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct List{

    char fname[MAX];
    char lname[MAX];
    char program[MAX];
    struct List* next;
        
}List;

List* createnewnode(char *fname, char* lname, char* program){
    List* newnode =  malloc(sizeof(List));

    strcpy(newnode->fname, fname);
    strcpy(newnode->lname, lname);
    strcpy(newnode->program,program);
    newnode->next = NULL;
    return newnode;
}

void linknode(List** head, List* node){
    
    if(*head == NULL){
        *head = node;
    }else{
        List* ptr = *head;
        while(ptr->next!= NULL){
            ptr = ptr->next;
        }
        
        ptr->next = node;
    }
}

void display(List* head){
    List *ptr = head;

    if(head == NULL){
        printf("No list");
        return;

    } 
    printf("\nFname Lname - Program\n");
    while(ptr != NULL){
        printf("%s %s - %s\n", ptr->fname, ptr->lname, ptr->program);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(List** head, List* Node){

    List* ptr = *head;
    if(*head == NULL){
        Node->next = *head;
        *head = Node;
    }else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        Node->next = ptr->next;
        ptr->next = Node;
    }
}

void filternodes(List** head1, List** head2, char *choice){
    List* next = NULL;
    List* prev = NULL;
    List* ptr = *head1;
    while(ptr != NULL){
        next = ptr->next;
        if(strcmp(ptr->program, choice) == 0){
            if(prev == NULL){
                insert(head2, ptr);
                *head1 = next;
            }else{
                prev->next = next;
                insert(head2, ptr);
            }
        }else{
            prev = ptr;
        }
        ptr = next;
    }
}


int main(){

    List* head[2];
    head[0] = NULL;
    head[1] = NULL;
    int choice;
    
    printf("\n===ORIGINAL LIST===\n");
    List* n1 = createnewnode("John", "Doe", "BSCS");
    linknode(&head[0], n1);
    List* n2 = createnewnode("Jose", "Rizal", "BSIT");
    linknode(&head[0], n2);
    List* n3 = createnewnode("Joseph", "Frena", "BSIS");
    linknode(&head[0], n3);
    List* n4 = createnewnode("Mario", "Montana", "BSIS");
    linknode(&head[0], n4);
    List* n5 = createnewnode("James", "Deen", "BSCS");
    linknode(&head[0], n5);
    List* n6 = createnewnode("Moshley", "Brow", "BSIT");
    linknode(&head[0], n6);

    display(head[0]);

    printf("Pick a program: \n");
    printf("[1] BSCS\n");
    printf("[2] BSIT\n");
    printf("[3] BSIS\n");
    printf("\n> ");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            filternodes(&head[0], &head[1], "BSCS");
            break;
        case 2:
            filternodes(&head[0], &head[1], "BSIT");
            break;
        case 3:
            filternodes(&head[0], &head[1], "BSIS");
            break;
        default:
            printf("NONE EXITING");
            break;
    }
    

    display(head[0]);
    display(head[1]);
    
    



    return 0;
}