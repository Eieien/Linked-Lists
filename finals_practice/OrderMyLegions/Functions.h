#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct {
    int legionnaire;
    int centurion;
    int lightTroops;
    int archers;
} Soldiers;

typedef struct node {
    int legionNumber;
    char legionType[20];
    Soldiers soldiers;

    struct node* next;
} Legion;


void displayLegions(Legion* head);
void populateLegions(Legion** head);
void insertLegion(Legion** head, int legionNumber, char* legionType, Soldiers soldiers);
#endif
