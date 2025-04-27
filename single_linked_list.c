#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct node
{
    int value;
    struct node *next;
};

// Traversing a Linked list
void printLinkedList(struct node *p)
{
    while (p != NULL)
    {
        printf("%d---->", p->value);
        p = p->next;
    }
}



// Create NewNode Function
struct node *createNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));

    if (!newNode)
    {
        printf("Mem fail");
        return NULL;
    }

    newNode->next = NULL;
    newNode->value = data;
    return newNode;
}

// Insert at beginning function
void insertNodeatBeginning(struct node **head, int data)
{
    struct node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert Node at the end function
void insertNodeatRear(struct node **head, int data)
{
    struct node *newNode = createNode(data);
    // if head is none
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {

        // Start from the head
        struct node *temp = *head;
        // Traverses the entire lists of Nodes until it reaches the last
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int lengthOfLinkedList(struct node** head){
    struct node* ptr = *head;
    int len = 0;

    while(ptr != NULL){
        ptr= ptr->next;
        len++;
    }

    return len;
}
// insert Node at a specific position function
void insertNodeatindex(struct node **head, int data, int position)
{
    struct node *newNode = createNode(data);

    struct node *temp = *head;

    int len = lengthOfLinkedList(head);

    if(position == 1){
        newNode->next = *head;
        *head = newNode;
    }else if(position > len){
        printf("POSITION NOT FOUND!");
        return;
    }else{

        for (int i = 2; i < position; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

}


void deleteBeginning(struct node** head){

    if(head == NULL){
        printf("LIST IS EMPTY");
        return;
    }
    struct node* temp = *head;

    *head = temp->next;

    free(temp);

}

void deleteRear(struct node** head){

    if(head == NULL){
        printf("LIST IS EMPTY");
        return;
    }


    struct node* ptr = *head;
    //find second to the last node
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }

    free(ptr->next);
    ptr->next = NULL;
}

bool search(struct node** head, int value){
    struct node* ptr = *head;
    while(ptr != NULL){
        if(ptr->value == value){
            return true;
        }else{
            ptr = ptr->next;
        }
    }

    return false;
}

void deleteatPosition(struct node** head, int position){
    struct node* ptr = *head;
    struct node* prev = NULL;
    if(position == 1){
        *head = ptr->next;
        free(ptr);
    }else{
        for(int i = 1; i < position; i++){
            if(ptr->next != NULL){
                prev = ptr;
                ptr = ptr->next;
            }
        }

        if(ptr != NULL){
            prev->next = ptr->next;
            free(ptr);
        }else{
            printf("VALUE NOT PRESENT");
        }

        
    }
}

int count(struct node* head){
    struct node* ptr = head;
    int count = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }

    return count;
}


int main()
{
    // head points to the first node
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *four = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // Assign Nodes
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect Nodes
    one->next = two;
    two->next = three;
    three->next = NULL;
    // Creating a new node
    four = createNode(4);

    three->next = four;

    head = one;
    // inserting a node at the beginning
    insertNodeatBeginning(&head, 5);

    // inserting a node at the end
    insertNodeatRear(&head, 6);
    insertNodeatindex(&head, 7, 2);
    deleteBeginning(&head);
    deleteRear(&head);
    deleteatPosition(&head, 3);
    printLinkedList(head);
    int len = count(head);
    printf("\n%d", len);

    // if(search(&head, 11)){
    //     printf("\nFOUND!");
    // }else{
    //     printf("\nNOT FOUND!");
    // }
    
    free(one);
    free(two);
    free(three);

    return 0;
}