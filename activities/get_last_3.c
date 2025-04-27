#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX 100

typedef struct node{

    char Fname[MAX];
    char Lname[MAX];
    int score;
    struct node* next;

}student;

student* createnewnode(char* fname, char* lname, int score){
    
    student* newstudent = malloc(sizeof(student));
    
    strcpy(newstudent->Fname, fname);
    strcpy(newstudent->Lname, lname);
    newstudent->score = score;

    newstudent->next = NULL;

    return newstudent;

}

void sort_list(student** head){
    
    student* curr = *head;
    student* prev = NULL;
    student* next = NULL;
    bool swapped = true;

    while(swapped){

        swapped = false;
        curr = *head;
        prev = NULL;

        while(curr->next != NULL){
            next = curr->next;

            if(curr->score < next->score){
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

    }

}

void insertstart(student** head, student* node){

    if(*head == NULL){
        node->next = *head;
        *head = node;
    }else{
        student* ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = node;
    }

}

void get_last_3(student** head1, student** head2){
    student* curr1 = *head1;
    student* node;
    for(int i = 0; i < 7; i++){
        curr1 = curr1->next;
    }

    for(int i = 0; i < 3; i++){
        node = createnewnode(curr1->Fname, curr1->Lname, curr1->score);
        insertstart(head2, node);
        curr1 = curr1->next;
    }

}

void linknodes(student** head, student* node){

    if(*head == NULL){
        node->next = *head;
        *head = node;
    }else{
        
        student* ptr = *head;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = node;
    }

}

void display(student* head){
    student* ptr = head;
    while(ptr != NULL){
        printf("\t%s, %s \t- %d \n", ptr->Lname, ptr->Fname, ptr->score);
        ptr = ptr->next;
    }
    printf("\n");
}



int main(){

    student* head1 = NULL;    
    student* head2 = NULL;
    student* s1 = createnewnode("Liam", "Bennett", 87);
    linknodes(&head1, s1);
    student* s2 = createnewnode("Sophia", "Carter", 92);
    linknodes(&head1, s2);
    student* s3 = createnewnode("Noah", "Mitchell", 75);
    linknodes(&head1, s3);
    student* s4 = createnewnode("Ava", "Ramirez", 81);
    linknodes(&head1, s4);
    student* s5 = createnewnode("Elijah", "Nguyen", 68);
    linknodes(&head1, s5);
    student* s6 = createnewnode("Mia", "Wallace", 94);
    linknodes(&head1, s6);
    student* s7 = createnewnode("James", "Patel", 79);
    linknodes(&head1, s7);
    student* s8 = createnewnode("Isabella", "Kim", 88);
    linknodes(&head1, s8);
    student* s9 = createnewnode("Lucas", "Rivera", 73);
    linknodes(&head1, s9);
    student* s10 = createnewnode("Emma", "Thompson", 90);
    linknodes(&head1, s10);

    printf("===Unsorted List===\n");
    display(head1);

    printf("===Sorted List===\n");
    sort_list(&head1);
    display(head1);

    get_last_3(&head1, &head2);
    printf("===Original Top 10 List===\n");
    display(head1);
    printf("===Last 3===\n");
    display(head2);

}