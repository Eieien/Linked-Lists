#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.c"


// Function to check if a recipe can be made with the available ingredients
int canMakeRecipe(Recipe recipe, IngredientNode* ingredients) {
    /* 6.) Write code to check if Recipe can be made using the available ingredients*/
}

int findRecipe(Recipe* recipeList,char* recipeName){
    /* 3.) Write the code to find the selected recipe */
    for(int i = 0; i < MAX_RECIPES; i++){
        if(strcmp(recipeList[i].name, recipeName) == 0){
            return i;
        }
    }

    return -1;
}

int main() {
    IngredientNode* ingredients = NULL;
    ingredients=populate();

    Recipe* recipes = populateRecipe();
    printf("\nRecipes:\n");
    printRecipes(recipes,MAX_RECIPES);
    /* 1.) Print Recipes */


    // Ask user for recipe choice
    char recipeName[50];
    printf("\nEnter the name of the recipe you want to check: ");
    scanf("%[^\n]s",recipeName);

    int foundRecipe = findRecipe(recipes,recipeName);
    /* 2.) Call to check if recipe exits */
    int flag = 0;

    if(foundRecipe < 0)printf("RECIPE DOES NOT EXIST!");
    else{
        printf("Recipe: %s\n", recipeName);
        IngredientNode* curr = NULL;
        for(int i = 0; i < recipes[foundRecipe].numIngredients; i++){
            curr = ingredients;
            printf("\tIngredient: %s, Quanitity: %d\n", recipes[foundRecipe].ingredients[i].name, recipes[foundRecipe].ingredients[i].quantity);
            while(strcmp(curr->ingredient.name, recipes[foundRecipe].ingredients[i].name) != 0){
                curr = curr->next;
            };

            if(curr->ingredient.quantity < recipes[foundRecipe].ingredients[i].quantity) flag = 1;
        }
    }


    /* 4.) Display the Recipe and Display its Individual ingredients */



    /* 5.) Call Function to check if Recipe can be made based on
    available ingredients*/

    if(flag == 1){
        printf("You do not have enough ingredients to make this recipe.");
    }else{
        printf("You have all the necessary ingredients to make this recipe.");
    }


    return 0;
}
