#ifndef RECIPEMANAGER_H
#define RECIPEMANAGER_H

#include <string>
#include <vector>
#include "Recipe.h"

using namespace std;

class RecipeManager {
public:
    int createRecipe(const string& token, const Recipe& recipe);
    Recipe readRecipe(int recipeId);
    void updateRecipe(const string& token, int recipeId, const Recipe& updatedRecipe);
    void deleteRecipe(const string& token, int recipeId);
    vector<Recipe> searchRecipes(const string& query);
    vector<Recipe> getUserRecipes(const string& token);
};

#endif
