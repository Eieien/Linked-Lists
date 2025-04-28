#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

// Structure for the mage's full name
typedef struct {
    char fName[50];
    char lName[50];
    char MI;
} Fullname;

// Structure for Mage profile
typedef struct Mage {
    Fullname name;
    int level;
    char uniqueSpell[50];
    struct Mage* next;  // Pointer to the next Mage in the linked list
} Mage;

// Structure for Duel mana range
typedef struct {
    int minMana;
    int maxMana;
} Duel;

// Structure for MageCollege, using a linked list of Mages
typedef struct School {
    Mage* students;  // Head of the linked list of Mages
    Duel range;
} MageCollege;

void Decipher(char *message, int key);
void enrollMages(MageCollege* college);
Mage* createMage(char* fName, char* lName, char MI, int level, char* uniqueSpell);
void addMage(MageCollege* college, Mage* newMage);

#endif
