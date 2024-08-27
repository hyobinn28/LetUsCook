#include "RecipeManager.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

RecipeManager::RecipeManager(const string& filename) : currentRecipeID(0), filename(filename) {
    loadRecipes();
}

RecipeManager::~RecipeManager() {
    saveRecipes();
}

int RecipeManager::createRecipe(const Recipe& recipe) {
    recipeDatabase[++currentRecipeID] = recipe;
    saveRecipes();
    return currentRecipeID;
}

Recipe RecipeManager::readRecipe(int recipeID) const {
    auto it = recipeDatabase.find(recipeID);
    if (it != recipeDatabase.end()) {
        return it->second;
    } else {
        throw runtime_error("Recipe not found");
    }
}

void RecipeManager::updateRecipe(int recipeID, const Recipe& updatedRecipe) {
    auto it = recipeDatabase.find(recipeID);
    if (it != recipeDatabase.end()) {
        recipeDatabase[recipeID] = updatedRecipe;
        saveRecipes();
    } else {
        throw runtime_error("Recipe not found");
    }
}

void RecipeManager::deleteRecipe(int recipeID) {
    if (recipeDatabase.erase(recipeID)) {
        saveRecipes();
    } else {
        throw runtime_error("Recipe not found");
    }
}

vector<Recipe> RecipeManager::searchRecipes(const string& query) const {
    vector<Recipe> results;
    for (const auto& [id, recipe] : recipeDatabase) {
        if (recipe.name.find(query) != string::npos ||
            find(recipe.tags.begin(), recipe.tags.end(), query) != recipe.tags.end()) {
            results.push_back(recipe);
        }
    }
    return results;
}

void RecipeManager::loadRecipes() {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        int id = stoi(line);
        string recipeData;
        getline(file, recipeData);
        Recipe recipe = Recipe::deserialize(recipeData);
        recipeDatabase[id] = recipe;
    }
}

void RecipeManager::saveRecipes() const {
    ofstream file(filename);
    for (const auto& [id, recipe] : recipeDatabase) {
        file << id << "\n" << recipe.serialize() << "\n";
    }
}
