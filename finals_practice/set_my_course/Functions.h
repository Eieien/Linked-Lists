#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct {
    char job[50];
} Person;

typedef struct node {
    char name[50];
    int gold;
    Person VIP[3];
    char distance[10];

    struct node* next;
} Town;

void displayTowns(Town* head);
void populate(Town** head);
void printTownNames(Town* head);
#endif
