#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

void insertLast(Node** headRef, studentData record){
	Node *newNode=malloc(sizeof(Node));
	newNode->data=record;
	newNode->next=NULL;

	while(*headRef!=NULL){
		headRef=&(*headRef)->next;
	}

	*headRef=newNode;
}

NodePtr populate(){
	NodePtr head=NULL;
	studentData records[24]=
	{
		{{"Darwin","Connelly"},{48,0}},
		{{"Emmanuelle","Bergnaum"},{96,0}},
		{{"Angus","Auer"},{152,0}},
		{{"Bennett","Schimmel"},{62,0}},
		{{"Catharine","Keeling"},{28,0}},
		{{"Berneice","Bruen"},{220,0}},
		{{"Letha","Smitham"},{143,0}},
		{{"Vladimir","Gorczany"},{72,0}},
		{{"Vicente","Volkman"},{240,0}},
		{{"Maymie","Wuckert"},{29,0}},
		{{"Anya","Jacobson"},{140,0}},
		{{"Yesenia","Ondricka"},{168,0}},
		{{"Rowena","Muller"},{152,0}},
		{{"Lilla","Abbott"},{95,0}},
		{{"Rod","Barton"},{142,0}},
		{{"Johnny","Villa"},{173,0}},
		{{"Jody","MacGyver"},{24,0}},

	};
	int i=0;
	for(i=0;i<17;i++){
		insertLast(&head,records[i]);
	}

	return head;
}

void display(Node* head, int yrLvl){
	Node *trav=head;
	printf("\n\n=====STUDENT LIST======\n\n");
	printf("%-25s  %-20s  %-15s\n","STUDENT NAME","YEAR LEVEL","UNITS");
	printf("------------%-15s----------%-12s-----\n\n"," "," "," ");
		while(trav!=NULL){
		if(trav->data.record.yearLevel==yrLvl){
			printf("%-10s %-21s %-17d %3d\n",trav->data.name.fName,trav->data.name.lName,trav->data.record.yearLevel,trav->data.record.units);
		}
		trav=trav->next;
	}
}
