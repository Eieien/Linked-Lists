#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.c"

void computeYearLevel(Node**); // Create the proper Function definition, as well as the proper Function code. This function should properly update all items in the linked list to their proper yearLevel.

int main(){
    int yrLvl;
    Node *head;

	head=populate();

    //[ANSWER 2] Write the proper Function call to computeYearLevel()
	computeYearLevel(&head);
	printf("Input Year Level: ");
	scanf("%d",&yrLvl);

	display(head, yrLvl);


	return 0;
}

// [ANSWER 1] Write the Function Definition for computeYearLevel();

void computeYearLevel(Node** head){
	Node** trav = head;

	while(*trav != NULL){

		if((*trav)->data.record.units < 47){
			(*trav)->data.record.yearLevel = 1;
		}else if((*trav)->data.record.units >= 48 && (*trav)->data.record.units < 96){
			(*trav)->data.record.yearLevel = 2;
		}else if((*trav)->data.record.units >= 96 && (*trav)->data.record.units < 144){
			(*trav)->data.record.yearLevel = 3;
		}else if((*trav)->data.record.units >= 144 && (*trav)->data.record.units < 192){
			(*trav)->data.record.yearLevel = 4;
		}else{
			(*trav)->data.record.yearLevel = 5;
		}

		trav = &(*trav)->next;
	}
}
