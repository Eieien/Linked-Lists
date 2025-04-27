#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Note: With typedef, 'Node' must be declared right after typedef struct to properly reference itself
typedef struct Node 
{
    int data;
    struct Node *next; 
    // Note: Use 'struct Node' instead since 'Node' isn’t recognized yet 
    //       because typedef struct hasn’t finished defining 'Node'
} Node;

Node *createNode()
{
    Node *node = (Node*)malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter number to store: ");
    scanf("%d", &node->data);
    // Initialize next of current node as NULL since there is no next node
    node->next = NULL;

    return node;
}

void linkNode(Node **head, Node *node){
    // If no linked list exists, 1st node is head
    if(*head == NULL) *head = node;
    // If there is linked list
    else{
        // 1st: point to head
        Node *ptr = *head;

        // 2nd: point to each consecutive node until there is no next node
        while(ptr->next != NULL) ptr = ptr->next;
        
        // 3rd: since loop ended when pointing to the last node which has NULL link,
        //      it now links newly created node to the end of the list
        ptr->next = node;
    }
}

void deleteNode(Node **head) { 
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    int num;
    printf("Enter value to delete: ");
    scanf("%d", &num);

    Node *ptr = *head;  // Pointer to head / 1st node
    Node *prev = NULL;  // Previous node before pointer node (initialized as NULL since no node before head)

    // If head node itself is to be deleted
    if (ptr != NULL && ptr->data == num) {
        *head = ptr->next; // Next node will be new head
        free(ptr);
        printf("Deleted %d\n", num);
        return;
    }

    // Search for the node
    while (ptr != NULL && ptr->data != num) {
        prev = ptr; // Prev is pointer node
        ptr = ptr->next; // Pointer goes to next node
    }

    // If value is not found
    if (ptr == NULL) {
        printf("Value not found in list\n");
    }
    else {  // Unlink and delete node
        prev->next = ptr->next; // Prev node links to the next node of the deleted node
        free(ptr);
        printf("Deleted %d\n", num);
    }
}

void displayList(Node *head) 
{
    // Current initialized as head / 1st node
    Node *current = head;

    printf("\nLinked List:\n");
    // Loop for current to point from head to end of linked list
    while (current != NULL) {
        printf("[%d] ", current->data);
        // Goes to next node
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL; // Head of linked list (must be initialized as NULL since linked list is empty)
    Node *node;  // Nodes of linked list
    Node *ptr;   // Pointer for each node
    char ch;
    int num;

    while(1) {
        printf("Linked List System\n");
        printf("1. Add Item\n");
        printf("2. Delete Item\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &ch);
        while (getchar() != '\n'); // Clear buffer

        switch(ch){
            case '1': // Add
                node = createNode();
                if (node != NULL) linkNode(&head, node);
                break;

            case '2': // Delete
                deleteNode(&head);
                break;

            case '3': // Display
                displayList(head);
                break;

            default: // Exit
                // Free memory
                while (head != NULL) {
                    ptr = head;
                    head = head->next;
                    free(ptr);
                }

                return 0;
        }

        printf("\n");
    }
}