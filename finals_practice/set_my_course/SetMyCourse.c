#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Functions.c"

// Function for Nobles. Delete Towns with...
void deleteCriminalTowns(Town** head) {
    Town** trav = head;
    Town* curr = NULL;
    Town* next = NULL;
    int flag = 0;
    while((*trav) != NULL){
        curr = *trav;
        next = curr->next;
        flag = 0;
        for(int i = 0; i < 3; i++){
            if(strcmp(curr->VIP[i].job, "Bandit") == 0 || strcmp(curr->VIP[i].job, "Thief") == 0){
                *trav = next;
                free(curr);
                flag++;
                break;
            }
        }
        if(flag == 0)trav = &((*trav)->next);
        
    }

}

// Function for Knights. Delete Towns that do not have... but have...
void HuntCriminals(Town** head) {
    Town** trav = head;
    Town* curr = NULL;
    Town* next = NULL;
    int criminal = 0, guard = 0;
    while((*trav) != NULL){
        curr = *trav;
        next = curr->next;
        criminal = 0;
        guard = 0;
        
        for(int i = 0; i < 3; i++){
            if(strcmp(curr->VIP[i].job, "Bandit") == 0 || strcmp(curr->VIP[i].job, "Thief") == 0 ){
                criminal = 1;
            }
            if(strcmp(curr->VIP[i].job, "Guard") == 0)guard = 1;
        }

        if(criminal == 0 || guard == 1){
            *trav = next;
            free(curr);
        }else{
            trav = &(*trav)->next;
        }
    }
}

// Function for Merchants.
void deleteHighGoldTowns(Town** head, int budget) {
    Town** trav = head;
    Town* curr = NULL;
    Town* next = NULL;
    while((*trav) != NULL){
        curr = *trav;
        next = curr->next;

        if(budget < curr->gold){
            free(curr);
            *trav = next;
        }else{
            trav = &((*trav)->next);
        }
        
    }
}

// Function to sort the list based on distance
void sortTownsByDistance(Town** head) {
   Town** trav = head;
   Town* curr = NULL;
   Town* next = NULL;

   int swapped = 1;

   while(swapped){
        trav = head;
        swapped = 0;

        while((*trav)->next != NULL){
            curr = *trav;
            next = curr->next;

            if(strcmp(curr->distance, next->distance) > 0){
                curr->next = next->next;
                next->next = curr;
                *trav = next;
                swapped = 1;
            }

            trav = &((*trav)->next);
        }
   }
}

int main() {
    Town* head = NULL;
    char input[20];

    populate(&head);

    printf("Prepare itinerary for? (Noble, Knight, Merchant): ");
    scanf("%s", input);

    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if (strcmp(input, "noble") == 0) {
        printf("\nYour Travel Plans, m'lord...\n\n");
        deleteCriminalTowns(&head);
        printTownNames(head);
    } else if (strcmp(input, "knight") == 0) {
        printf("\nCriminals found here good sir...\n\n");
        HuntCriminals(&head);
        printTownNames(head);
    } else if (strcmp(input, "merchant") == 0) {
        printf("\nOoooh Investments...\n\n");
        int budget;
        printf("Your gold:");
        scanf("%d", &budget);
        deleteHighGoldTowns(&head, budget);
        printTownNames(head);
    } else {
        printf("Invalid role entered.\n");
        head = NULL;
    }

    sortTownsByDistance(&head);
    printf("\nFinal Itinerary:\n");
    displayTowns(head);

    return 0;
}
