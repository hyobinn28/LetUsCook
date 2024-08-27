#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include "Recipe.h"
#include <map>
#include <string>
#include <sstream>
#include <vector>

class RecipeManager {
private:
    map<int, Recipe> recipeDatabase;
    int currentRecipeID;
    const string filename;

public:
    RecipeManager(const string& filename = "recipes.txt");
    ~RecipeManager();

    int createRecipe(const Recipe& recipe);
    Recipe readRecipe(int recipeID) const;
    void updateRecipe(int recipeID, const Recipe& updatedRecipe);
    void deleteRecipe(int recipeID);
    vector<Recipe> searchRecipes(const string& query) const;

private:
    void loadRecipes();
    void saveRecipes() const;
};

#endif // RECIPE_MANAGER_H
