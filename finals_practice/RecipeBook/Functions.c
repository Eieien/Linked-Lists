#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

IngredientNode* createNode(const char* name, int quantity) {
    IngredientNode* newNode = (IngredientNode*)malloc(sizeof(IngredientNode));
    strcpy(newNode->ingredient.name, name);
    newNode->ingredient.quantity = quantity;
    newNode->next = NULL;
    return newNode;
}


void addIngredient(IngredientNode** head, const char* name, int quantity) {
    IngredientNode* newNode = createNode(name, quantity);
    newNode->next = *head;
    *head = newNode;
}


// Function to print recipes
void printRecipes(Recipe* recipes, int numRecipes) {
    for (int i = 0; i < numRecipes; i++) {
        printf("Recipe: %s\n", recipes[i].name);
    }
}

IngredientNode* populate(){
    IngredientNode* ingredients = NULL;

    addIngredient(&ingredients, "Flour", 2);
    addIngredient(&ingredients, "Sugar", 1);
    addIngredient(&ingredients, "Eggs", 12);
    addIngredient(&ingredients, "Milk", 0);
    addIngredient(&ingredients, "Butter", 3);
    addIngredient(&ingredients, "Salt", 0);
    addIngredient(&ingredients, "Baking Powder", 1);
    addIngredient(&ingredients, "Vanilla Extract", 0);
    addIngredient(&ingredients, "Chocolate Chips", 2);

    return ingredients;
}

Recipe* populateRecipe(){
     Recipe recipeArray[MAX_RECIPES] = {
        {
            "Pancakes",
            {
                {"Flour", 1},
                {"Milk", 1},
                {"Eggs", 2},
                {"Baking Powder", 1},
                {"Salt", 1}
            },
            5
        },
        {
            "Chocolate Chip Cookies",
            {
                {"Flour", 2},
                {"Sugar", 1},
                {"Butter", 1},
                {"Eggs", 1},
                {"Chocolate Chips", 2}
            },
            5
        },
        {
            "Scrambled Eggs",
            {
                {"Eggs", 3},
                {"Milk", 1},
                {"Butter", 1},
                {"Salt", 1}
            },
            4
        },
        {
            "Vanilla Cake",
            {
                {"Flour", 2},
                {"Sugar", 2},
                {"Butter", 1},
                {"Eggs", 3},
                {"Vanilla Extract", 1}
            },
            5
        },
        {
            "Butter Cookies",
            {
                {"Flour", 2},
                {"Sugar", 1},
                {"Butter", 2},
                {"Eggs", 1}
            },
            4
        }
    };
    Recipe* recipes=malloc(sizeof(Recipe)*MAX_RECIPES);

    for(int i=0;i<MAX_RECIPES;i++){
        recipes[i]=recipeArray[i];
    }

    return recipes;

}
