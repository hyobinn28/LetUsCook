#include "RecipeManager.h"
#include "Database.h"
#include "jwt.h"
#include <iostream>

using namespace std;

int RecipeManager::createRecipe(const string& token, const Recipe& recipe) {
    int userId = jwt::getUserIdFromToken(token);
    Database db;
    string query = "INSERT INTO recipes (userId, name, ingredients, instructions, tags) VALUES (" +
                   to_string(userId) + ", '" + recipe.name + "', '" + recipe.getIngredientsAsString() + 
                   "', '" + recipe.instructions + "', '" + recipe.getTagsAsString() + "');";
    db.execute(query);
    return db.getLastInsertId();
}

Recipe RecipeManager::readRecipe(int recipeId) {
    Database db;
    string query = "SELECT * FROM recipes WHERE id = " + to_string(recipeId) + ";";
    auto result = db.query(query);

    if(result.size() == 1) {
        Recipe recipe;
        recipe.id = recipeId;
        recipe.name = result[0]["name"];
        recipe.setIngredientsFromString(result[0]["ingredients"]);
        recipe.instructions = result[0]["instructions"];
        recipe.setTagsFromString(result[0]["tags"]);
        return recipe;
    }

    throw runtime_error("Recipe not found.");
}

void RecipeManager::updateRecipe(const string& token, int recipeId, const Recipe& updatedRecipe) {
    int userId = jwt::getUserIdFromToken(token);
    Database db;
    
    string ownershipQuery = "SELECT userId FROM recipes WHERE id = " + to_string(recipeId) + ";";
    auto result = db.query(ownershipQuery);

    if(result.size() == 1 && stoi(result[0]["userId"]) == userId) {
        string updateQuery = "UPDATE recipes SET name = '" + updatedRecipe.name + 
                             "', ingredients = '" + updatedRecipe.getIngredientsAsString() +
                             "', instructions = '" + updatedRecipe.instructions + 
                             "', tags = '" + updatedRecipe.getTagsAsString() + 
                             "' WHERE id = " + to_string(recipeId) + ";";
        db.execute(updateQuery);
    }
    else {
        throw runtime_error("Unauthorized to update this recipe.");
    }
}

void RecipeManager::deleteRecipe(const string& token, int recipeId) {
    int userId = jwt::getUserIdFromToken(token);
    Database db;

    string ownershipQuery = "SELECT userId FROM recipes WHERE id = " + to_string(recipeId) + ";";
    auto result = db.query(ownershipQuery);

    if(result.size() == 1 && stoi(result[0]["userId"]) == userId) {
        string deleteQuery = "DELETE FROM recipes WHERE id = " + to_string(recipeId) + ";";
        db.execute(deleteQuery);
    }
    else {
        throw runtime_error("Unauthorized to delete this recipe.");
    }
}

vector<Recipe> RecipeManager::searchRecipes(const string& query) {
    Database db;
    string searchQuery = "SELECT * FROM recipes WHERE name LIKE '%" + query + "%';";
    auto results = db.query(searchQuery);

    vector<Recipe> recipes;
    for(const auto& row : results) {
        Recipe recipe;
        recipe.id = stoi(row.at("id"));
        recipe.name = row.at("name");
        recipe.setIngredientsFromString(row.at("ingredients"));
        recipe.instructions = row.at("instructions");
        recipe.setTagsFromString(row.at("tags"));
        recipes.push_back(recipe);
    }
    return recipes;
}

vector<Recipe> RecipeManager::getUserRecipes(const string& token) {
    int userId = jwt::getUserIdFromToken(token);
    Database db;
    string query = "SELECT * FROM recipes WHERE userId = " + to_string(userId) + ";";
    auto results = db.query(query);

    vector<Recipe> recipes;
    for(const auto& row : results) {
        Recipe recipe;
        recipe.id= stoi(row.at("id"));
        recipe.name = row.at("name");
        recipe.setIngredientsFromString(row.at("ingredients"));
        recipe.instructions = row.at("instructions");
        recipe.setTagsFromString(row.at("tags"));
        recipes.push_back(recipe);
    }
    return recipes;
}