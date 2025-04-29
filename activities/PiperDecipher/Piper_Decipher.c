#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Functions.c"

/*You Will Only Answer Everything in Here*/

int factorial(int n) {
    //Optional Function, you may integrate the math into the functions below if you prefer.
}

int getMana(char* message) {

    int key = -4;
    int Mana = 1;
    int count = 0;
    Decipher(message, key);
    for(int i = 0; message[i] != '\0'; i++){
        if(tolower(message[i]) == 'a' || tolower(message[i]) == 'e' || tolower(message[i]) == 'i' || tolower(message[i]) == 'o' || tolower(message[i]) == 'u'){
            count++;
        }
    }    
    if(count > 1){
        for (int i = 2; i <= count; i++) {
            Mana *= i;
        }
    }else{
        Mana = count;
    }

    return Mana;
}

Mage* eligibleMage(Mage* students, int* count, int minmana, int maxmana) {
    Mage* curr = students;
    Mage* prev = NULL;
    
    while(curr != NULL && (curr->level > maxmana || curr->level < minmana)){
        curr = curr->next;
    }    

    students = curr;
    if(students == NULL){
        return NULL;
    }

    *count += 1;
    while(curr != NULL && curr->next != NULL){
        if(curr->next->level < minmana){
            curr->next = NULL;
            break;
        }
        (*count)++;
        curr = curr->next;
    }

   

    return students;
}

void sort (Mage** students) {
    
    Mage* curr = *students;
    Mage* prev = NULL;
    Mage* next = NULL;
    int swap = 1;

    while(swap){
        curr = *students;
        swap = 0;
        prev = NULL;
        while(curr->next != NULL){
            
            next = curr->next;
            if(curr->level < next->level){
                
                if(prev == NULL){
                    curr->next = next->next;
                    next->next = curr;
                    *students = next;
                }else{
                    curr->next = next->next;
                    next->next = curr;
                    prev->next = next;
                }

                prev = next;
                swap = 1;
                

            }else{
                prev = curr;
                curr = next;
            }

        }
    }
}

void PipersList(int count, Mage* student) {


    printf("\n ===DUELING MAGES===\n");
    for (int i = 0; i < count; i++) {

        printf("Mage: %s %c %s \n- Mana Level: %d \n- Deciphered Spell: %s\n\n", student->name.fName, student->name.MI, student->name.lName, student->level, student->uniqueSpell);
        student = student->next;
    }
}

void display(Mage* head){
    Mage* ptr = head;
    while(ptr != NULL){
        int mana = getMana(ptr->uniqueSpell);
        printf("%d\t%s %s %c %d %s\n", mana, ptr->name.fName, ptr->name.lName, ptr->name.MI, ptr->level, ptr->uniqueSpell);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    // Psst hey, here's the key.. good luck -Your friend, Piper
    int key = -4;
    MageCollege college; // The empty college yet to be populated with mages
    int count = 0;
    //Hmmm... the part below is missing something.. how peculiar
    printf("Input Lowest Mana Acceptable:" );
    scanf("%d",&college.range.minMana);
    printf("\nInput Highest Mana Acceptable:" );
    scanf("%d",&college.range.maxMana);

    //Why does it feel so empty here.. a trick of the code?
    college.students = NULL; // HEAD

    enrollMages(&college);
    Mage* curr = college.students;

    while(curr != NULL){
        curr->level = getMana(curr->uniqueSpell);
        curr = curr->next;
    }
    sort(&college.students);
    // display(college.students);
    college.students = eligibleMage(college.students, &count, college.range.minMana, college.range.maxMana);
    // display(college.students);
    PipersList(count, college.students);

    return 0;
}
