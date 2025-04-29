#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int extractTownNumber(const char* townName) {
    // Assuming town names are in the format "Town<number>", e.g., "Town10"
    int number = 0;
    sscanf(townName, "Town%d", &number);
    return number;
}

// Helper function to count the number of towns in the list
int countTowns(Town* head) {
    int count = 0;
    Town* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printTownNames(Town* head) {
    // Get the count of towns
    int count = countTowns(head);

    if (count == 0) {
        printf("No towns to display.\n");
        return;
    }

    // Create an array of Town pointers
    Town** townArray = (Town**)malloc(count * sizeof(Town*));
    Town* current = head;
    int i = 0;

    // Fill the array with town pointers
    while (current != NULL) {
        townArray[i++] = current;
        current = current->next;
    }

    // Sort the array by extracting the town number for proper comparison
    for (int j = 0; j < count - 1; j++) {
        for (int k = 0; k < count - j - 1; k++) {
            int townNum1 = extractTownNumber(townArray[k]->name);
            int townNum2 = extractTownNumber(townArray[k + 1]->name);
            if (townNum1 > townNum2) {
                // Swap the towns
                Town* temp = townArray[k];
                townArray[k] = townArray[k + 1];
                townArray[k + 1] = temp;
            }
        }
    }

    // Print the sorted town names
    printf("Your Destinations: ");
    for (i = 0; i < count; i++) {
        printf("%s", townArray[i]->name);
        if (i < count - 1) {
            printf("-> ");
        }
    }
    printf("-> END");

    // Free the allocated memory for the array
    free(townArray);
}

void displayTowns(Town* head) {
    Town* current = head;

    // Traverse the linked list
    while (current != NULL) {
        // Display the current town's details
        printf("Town: %s, Gold: %d, Distance: %s\n", current->name, current->gold, current->distance);

        // Display the jobs of the 3 VIPs in the town
        for (int i = 0; i < 3; i++) {
            printf("  VIP %d Job: %s\n", i + 1, current->VIP[i].job);
        }

        // Move to the next town in the list
        current = current->next;
    }
}

// Function to insert a new town at the end of the list
void insertAtEnd(Town** head, Town* newTown) {
    if (*head == NULL) {
        // If the list is empty, make newTown the head
        *head = newTown;
    } else {
        // Traverse to the end of the list
        Town* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Insert the new town at the end
        temp->next = newTown;
    }
}

void populate(Town** head) {
    // Array of town data
    char* townNames[] = {"Town1", "Town2", "Town3", "Town4", "Town5", 
                         "Town6", "Town7", "Town8", "Town9", "Town10"};
    int gold[] = {100, 200, 300, 150, 250, 350, 180, 220, 270, 320};
    char* distances[] = {"30km", "20km", "10km", "15km", "25km", "35km", "18km", "22km", "27km", "32km"};
    
    // VIP job data for each town
    char* VIPJobs[10][3] = {
        {"Thief", "Merchant", "Guard"},
        {"Farmer", "Trader", "Bandit"},
        {"Fishmonger", "Captain", "Guard"},
        {"Blacksmith", "Adventurer", "Wizard"},
        {"Bandit", "Farmer", "Guard"},
        {"Bandit", "Miner", "Thief"},
        {"Guard", "Trader", "Guard"},
        {"Thief", "Miner", "Farmer"},
        {"Blacksmith", "Miner", "Bandit"},
        {"Trader", "Miner", "Guard"}
    };

    Town* temp = NULL;
    
    for (int i = 0; i < 10; i++) {
        // Allocate memory for new town
        Town* newTown = (Town*)malloc(sizeof(Town));
        
        // Populate town data
        strcpy(newTown->name, townNames[i]);
        newTown->gold = gold[i];
        strcpy(newTown->distance, distances[i]);
        
        // Populate VIP jobs
        for (int j = 0; j < 3; j++) {
            strcpy(newTown->VIP[j].job, VIPJobs[i][j]);
        }

        // Insert town at the beginning of the list
        newTown->next = temp;
        temp = newTown;
    }

    // Update head pointer to point to the first town
    *head = temp;
}

