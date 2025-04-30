#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Functions.c"

// Function for Nobles. Delete Towns with...
void deleteCriminalTowns(Town** head) {
    Town** trav;
    Town* curr;
    Town* next = NULL;
    int flag = 0;

    trav = head;
    while(*trav != NULL){
        curr = *trav;
        next = curr->next;
        flag = 0;
        for(int i = 0; i < 3; i++){
            if(strcmp(curr->VIP[i].job, "Thief") == 0 || strcmp(curr->VIP[i].job, "Bandit") == 0 ){
                *trav = next;
                flag = 1;
                free(curr);
                break;
            }
        }
        if(flag == 0)trav = &((*trav)->next);
    }
    
    // Town* curr = *head;
    // Town* prev = NULL;
    // Town* next = NULL;
    // int flag = 0;
    // while(curr != NULL){
    //     flag = 0;
    //     next = curr->next;

    //     for(int i = 0; i < 3; i++){
    //         if(strcmp(curr->VIP[i].job, "Thief") == 0 || strcmp(curr->VIP[i].job, "Bandit") == 0 ){
    //             if(prev == NULL){
    //                 *head = next;
    //             }else{
    //                 prev->next = next;
    //             }
    //             flag = 1;
    //             free(curr);
    //             break;
    //         }
    //     }
    //     if(flag == 0)prev = curr;
    //     curr = next;
    // }
}

// Function for Knights. Delete Towns that do not have... but have...
void HuntCriminals(Town** head) {
    Town** trav;
    Town* curr;
    Town* next =NULL;
    int guardflag =0;
    int criminalflag =0;
    int deprev = 0;
    trav = head;

    while(*trav != NULL){
        guardflag = 0;
        criminalflag = 0;
        deprev = 0;
        curr = *trav;
        next = curr->next;

        for(int i = 0; i < 3; i++){
            if(strcmp(curr->VIP[i].job, "Guard") == 0){
                guardflag = 1;
            }

            if(strcmp(curr->VIP[i].job, "Thief") == 0 || strcmp(curr->VIP[i].job, "Bandit") == 0){
                criminalflag = 1;
            }
        }

        if(criminalflag == 0 || guardflag == 1){
            *trav = next;
            free(curr);
            deprev = 1;
        }

        if(deprev == 0)trav = &((*trav)->next);
    }
    
    // Town* curr = *head;
    // Town* prev = NULL;
    // Town* next = NULL;
    // int guardflag = 0;
    // int criminalflag = 0;
    // int denode = 0;

    // while(curr != NULL){
    //     guardflag = 0;
    //     criminalflag = 0;
    //     denode = 0;
    //     next = curr->next;

    //     for(int i = 0; i < 3; i++){
    //         if(strcmp(curr->VIP[i].job, "Guard") == 0){
    //             guardflag = 1;
    //         }else if(strcmp(curr->VIP[i].job, "Thief") == 0 || strcmp(curr->VIP[i].job, "Bandit") == 0){
    //             criminalflag = 1;
    //         }

    //     }

    //     if(criminalflag == 0 || guardflag == 1){
    //         if(prev == NULL){
    //             *head = next;
    //         }else{
    //             prev->next = next;
    //         }
    //         free(curr);

    //         denode = 1;
    //     }
    //     if(denode == 0)prev = curr;
    //     curr = next;
    // }
}

// Function for Merchants.
void deleteHighGoldTowns(Town** head, int budget) {
    Town** trav;
    Town* next = NULL;
    Town* curr;
    trav = head;
    int flag = 0;

    while(*trav != NULL){
        flag = 0;
        curr = *trav;
        next = curr->next;

        if(curr->gold > budget){
            *trav = next;
            free(curr);
            flag = 1;
        }

        if(flag == 0) trav = &((*trav)->next);
    }
    
    // Town* curr = *head;
    // Town* prev = NULL;
    // Town* next = NULL;
    // int flag = 0;

    // while(curr != NULL){
    //     flag = 0;
    //     next = curr->next;
    //     if(curr->gold > budget){
    //         if(prev == NULL){
    //             *head = next;
    //         }else{
    //             prev->next = next;
    //         }
    //         free(curr);
    //         flag = 1;
    //     }

    //     if(flag == 0)prev = curr;
    //     curr = next;
    // }
    
}

// Function to sort the list based on distance
void sortTownsByDistance(Town** head) {
    Town** trav;
    Town* curr = NULL;
    Town* next = NULL;

    int swap = 1;
    while(swap == 1){
        trav = head;
        swap = 0;

        while((*trav)->next != NULL){
            curr = *trav;
            next = curr->next;

            if(strcmp(curr->distance, next->distance) == 1){
                curr->next = next->next;
                next->next = curr;
                *trav = next;
                swap = 1;
            }

            trav = &((*trav)->next);
        }
    }
    
    // Town* curr = *head;
    // Town* next = NULL;
    // Town* prev = NULL;
    // int swap = 1;
    // while(swap){
    //     curr = *head;
    //     prev = NULL;
    //     swap = 0;

    //     while(curr->next != NULL){
    //         next = curr->next;

    //         if(strcmp(curr->distance, next->distance) == 1){
    //             if(prev == NULL){
    //                 curr->next = next->next;
    //                 next->next = curr;
    //                 *head = next;
    //             }else{
    //                 curr->next = next->next;
    //                 next->next = curr;
    //                 prev->next = next;
    //             }
    //             prev = next;
    //             swap = 1;

    //         }else{
    //             prev = curr;
    //             curr = next;
    //         }
    //     }

    // }
    

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
