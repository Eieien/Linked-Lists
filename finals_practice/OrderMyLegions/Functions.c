#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Functions.h"

// Function to display the linked list
void displayLegions(Legion* head) {
    Legion* temp = head;
    while (temp != NULL) {
        printf("Legion Number: %d, Legion Type: %s\n", temp->legionNumber, temp->legionType);
        printf("  Legionnaire: %d, Centurion: %d, Light Troops: %d, Archers: %d\n\n",
               temp->soldiers.legionnaire, temp->soldiers.centurion,
               temp->soldiers.lightTroops, temp->soldiers.archers);
        temp = temp->next;
    }
}

// Function to populate the linked list with initial data
void populateLegions(Legion** head) {
    Soldiers soldiers1 = {1000, 50, 200, 300};
    Soldiers soldiers2 = {1200, 60, 300, 150};
    Soldiers soldiers3 = {800, 40, 150, 80};
    Soldiers soldiers4 = {700, 30, 100, 900};
    Soldiers soldiers5 = {900, 35, 120, 1100};
    Soldiers soldiers6 = {500, 20, 80, 50};
    Soldiers soldiers7 = {1100, 55, 250, 200};
    Soldiers soldiers8 = {600, 25, 100, 1200};

    insertLegion(head, 1, "Infantry", soldiers1);
    insertLegion(head, 2, "Cavalry", soldiers2);
    insertLegion(head, 3, "Archers", soldiers3);
    insertLegion(head, 4, "Infantry", soldiers4);
    insertLegion(head, 5, "Archers", soldiers5);
    insertLegion(head, 6, "Infantry", soldiers6);
    insertLegion(head, 7, "Cavalry", soldiers7);
    insertLegion(head, 8, "Archers", soldiers8);
}
