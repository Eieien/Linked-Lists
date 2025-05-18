#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Functions.c"


Legion* createLegion(int legionNumber, char* legionType, Soldiers soldiers) {
    // malloc here and populate the node with the passed data.
    Legion* newLegion = malloc(sizeof(Legion));
    newLegion->legionNumber = legionNumber;
    strcpy(newLegion->legionType, legionType);
    newLegion->soldiers = soldiers;
    newLegion->next = NULL;

    return newLegion;
}

void insertLegion(Legion** head, int legionNumber, char* legionType, Soldiers soldiers) {
    Legion* newLegion = createLegion(legionNumber, legionType, soldiers);

    Legion** trav;
    // Insert at the beginning if it's "Cavalry"
    
    if(strcmp(newLegion->legionType, "Cavalry") == 0){
        newLegion->next = *head;
        *head = newLegion;
    }else if(strcmp(newLegion->legionType, "Cavalry") != 0 && (newLegion->soldiers.archers > newLegion->soldiers.centurion && newLegion->soldiers.archers > newLegion->soldiers.legionnaire && newLegion->soldiers.archers > newLegion->soldiers.lightTroops)){
        // Check if it has more archers than other units and if so Insert at the end
        for(trav = head; (*trav) != NULL; trav = &(*trav)->next);
        *trav = newLegion;

    }else{
        
        for(trav = head; *trav != NULL; trav = &(*trav)->next){
            if(((*trav)->soldiers.archers > (*trav)->soldiers.centurion && (*trav)->soldiers.archers > (*trav)->soldiers.legionnaire && (*trav)->soldiers.archers > (*trav)->soldiers.lightTroops) || strcmp((*trav)->legionType, "Archers") == 0)break;
        }

        newLegion->next = (*trav);
        *trav = newLegion;
    }

    // Insert before the first "Archers" legion if it has high count of legionnaires

}




int main() {
    Legion* head = NULL;

    // Populate the Legion using the given function
    populateLegions(&head);

    printf("The Legions:\n");
    // Print the Legion using the given function
    displayLegions(head);

    return 0;
}
