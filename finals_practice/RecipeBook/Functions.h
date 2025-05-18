#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define MAX_INGREDIENTS 10
#define MAX_RECIPES 5

typedef struct Ingredient {
    char name[50];
    int quantity;
} Ingredient;


typedef struct IngredientNode {
    Ingredient ingredient;
    struct IngredientNode* next;
} IngredientNode;


typedef struct Recipe {
    char name[50];
    Ingredient ingredients[MAX_INGREDIENTS]; // LIST OF INGREDIENTS NEEDED BY A RECIPE
    int numIngredients; // THE COUNT OF RECIPES
} Recipe;

IngredientNode* createNode(const char* name, int quantity);
void addIngredient(IngredientNode** head, const char* name, int quantity);
void printRecipes(Recipe* recipes, int numRecipes);
IngredientNode* populate();
Recipe* populateRecipe();


#endif
