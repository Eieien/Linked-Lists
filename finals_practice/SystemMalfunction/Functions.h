#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct{
	char fName[20];
	char lName[20];
}personName;

typedef struct{
	int units;
	int yearLevel;
}studentRecord;

typedef struct{
	personName name;
	studentRecord record;

}studentData;

typedef struct node{
	studentData data;
	struct node* next;
}Node,*NodePtr;

/*insertLast takes in a Node** or NodePtr* as well as a studentData passed into it and inserts the studentData at the end of the linked list */
void insertLast(Node**,studentData);

/*populate() calls insertLast multiple times to initially populate the linked list. Once this function is called expect that the linked list is properly populated with the necessary information*/
NodePtr populate();

/*display() takes in a Node* or NodePtr and an int for yearLvl, this properly displays all of the students of a specific year level, the formatting is already done with display and display just needs to be properly called*/
void display(Node*, int);

#endif
