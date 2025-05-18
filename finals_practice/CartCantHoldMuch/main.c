#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions.c"

void insertItems(Node** head, Node* product){
    //Write the code to insert items into linked list.
    if(*head == NULL)*head = product;
    else{
        Node* curr = *head;
        while(curr->next != NULL) curr=  curr->next;
        curr->next = product;
    }

}

int main() {
    ProductList myProd;

    createAndPopulate(&myProd);

    int count = 0;

    Node* head = NULL;

    int totalQty = 0;



    printf("\nORIGINAL PRODUCT:\n");
    for(int i = 0; i < myProd.count; ++i) {
        displayProduct(myProd.prods[i]);
        printf("\n");
    }
    //Write the Code to Insert Items into the Linked List.
    printf("\n");

    for(int i = 0; i < myProd.count; ++i){
        printf("[%d.]Adding %s (%d): ", i + 1, myProd.prods[i].prodName, myProd.prods[i].prodQty);
        if(myProd.prods[i].prodQty + totalQty > 100){
            printf("Fail\n\n");
        }else{
            printf("Success\n\n");
            Node* product = malloc(sizeof(Node));
            product->data = myProd.prods[i];
            product->next = NULL;
            insertItems(&head, product);
            count++;
            totalQty += myProd.prods[i].prodQty;
            
        }
    }



    printf("\n NEW PRODUCT CART:\n");
    //Write the code to display the items in your cart.
    Node* curr = head;
    for(int i = 0; i < count; ++i){
        displayProduct(curr->data);
        printf("\n");
        curr = curr->next;
    }
    printf("Count: %d", totalQty);


    return 0;
}
