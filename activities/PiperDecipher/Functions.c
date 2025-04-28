#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

void Decipher(char *message, int key) {
	
	if (key == -4) {
		if (strcmp(message, "KviexivViwsvexmsr") == 0) {
		strcpy(message, "GreaterRestoration");
		} else if (strcmp(message, "Hmwmrxikvexi") == 0) {
			strcpy(message, "Disintegrate");
		} else if (strcmp(message, "ViepmxcFvieo") == 0) {
			strcpy(message, "RealityBreak");
		} else if (strcmp(message, "LiepmrkAsvh") == 0) {
			strcpy(message, "HealingWord");
		} else if (strcmp(message, "TsaivAsvhOmpp") == 0) {
			strcpy(message, "PowerWordKill");
		} else if (strcmp(message, "Mrzyprivefmpmxc") == 0) {
			strcpy(message, "Invulnerability");
		} else if (strcmp(message, "HevoQixisv") == 0) {
			strcpy(message, "DarkMeteor");
		} else if (strcmp(message, "VezirsywZsmh") == 0) {
			strcpy(message, "RavenousVoid");
		} else if (strcmp(message, "KviexivTspcqsvtl") == 0) {
			strcpy(message, "GreaterPolymorph");
		}
	} else {
		printf("WRONG KEY!\n");
	}	
}

Mage* createMage(char* fName, char* lName, char MI, int level, char* uniqueSpell) {
    Mage* newMage = (Mage*)malloc(sizeof(Mage));
    if (newMage == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }

    strcpy(newMage->name.fName, fName);
    strcpy(newMage->name.lName, lName);
    newMage->name.MI = MI;
    newMage->level = level;
    strcpy(newMage->uniqueSpell, uniqueSpell);
    newMage->next = NULL;  
    return newMage;
}

void addMage(MageCollege* college, Mage* newMage) {
    if (college->students == NULL) {
        college->students = newMage;  // If the list is empty, add the first Mage
    } else {
        Mage* temp = college->students;
        while (temp->next != NULL) {
            temp = temp->next;  // Traverse to the end of the list
        }
        temp->next = newMage;  // Add the new Mage at the end of the list
    }
}

void enrollMages(MageCollege* college) {
    addMage(college, createMage("Argon", "Liver", 'B', 1, "KviexivViwsvexmsr"));
    addMage(college, createMage("Pyr", "Mancer", 'O', 1, "Hmwmrxikvexi"));
    addMage(college, createMage("Nec", "Omancer", 'R', 1, "ViepmxcFvieo"));
    addMage(college, createMage("Gobu", "Goblin ", 'B', 1, "LiepmrkAsvh"));
    addMage(college, createMage("Alduin", "Dragon", 'D', 1, "TsaivAsvhOmpp"));
    addMage(college, createMage("Deem", "Gorgon", 'O', 1, "Mrzyprivefmpmxc"));
    addMage(college, createMage("Tia", "Amat", 'M', 1, "HevoQixisv"));
    addMage(college, createMage("Roboutte", "Guilliman ", 'G', 1, "VezirsywZsmh"));
    addMage(college, createMage("Piper D Cipher", "Dragon", 'D', 1, "KviexivTspcqsvtl"));
}

