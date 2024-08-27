#include "RecipeManager.h"
#include <iostream>

void getUserInput(RecipeManager& manager) {
    string choice;
    while (true) {
        cout << "Choose an option (create, read, update, delete, search, exit): ";
        cin >> choice;

        if (choice == "create") {
            Recipe recipe;
            cout << "Enter recipe name: ";
            cin.ignore();
            getline(cin, recipe.name);

            cout << "Enter ingredients (separated by commas): ";
            string ingredientsInput;
            getline(cin, ingredientsInput);
            stringstream ss(ingredientsInput);
            string ingredient;
            while (getline(ss, ingredient, ',')) {
                recipe.ingredients.push_back(ingredient);
            }

            cout << "Enter instructions: ";
            getline(cin, recipe.instructions);

            cout << "Enter tags (separated by commas): ";
            string tagsInput;
            getline(cin, tagsInput);
            stringstream st(tagsInput);
            string tag;
            while (getline(st, tag, ',')) {
                recipe.tags.push_back(tag);
            }

            int id = manager.createRecipe(recipe);
            cout << "Recipe created with ID: " << id << endl;

        } else if (choice == "read") {
            int id;
            cout << "Enter recipe ID: ";
            cin >> id;
            try {
                Recipe recipe = manager.readRecipe(id);
                cout << "Recipe Name: " << recipe.name << endl;
                cout << "Ingredients: ";
                for (const auto& ing : recipe.ingredients) {
                    cout << ing << " ";
                }
                cout << endl;
                cout << "Instructions: " << recipe.instructions << endl;
                cout << "Tags: ";
                for (const auto& tag : recipe.tags) {
                    cout << tag << " ";
                }
                cout << endl;
            } catch (const exception& e) {
                cout << e.what() << endl;
            }

        } else if (choice == "update") {
            int id;
            cout << "Enter recipe ID to update: ";
            cin >> id;

            Recipe recipe;
            cout << "Enter new recipe name: ";
            cin.ignore();
            getline(cin, recipe.name);

            cout << "Enter new ingredients (separated by commas): ";
            string ingredientsInput;
            getline(cin, ingredientsInput);
            stringstream ss(ingredientsInput);
            string ingredient;
            while (getline(ss, ingredient, ',')) {
                recipe.ingredients.push_back(ingredient);
            }

            cout << "Enter new instructions: ";
            getline(cin, recipe.instructions);

            cout << "Enter new tags (separated by commas): ";
            string tagsInput;
            getline(cin, tagsInput);
            stringstream st(tagsInput);
            string tag;
            while (getline(st, tag, ',')) {
                recipe.tags.push_back(tag);
            }

            manager.updateRecipe(id, recipe);
            cout << "Recipe updated." << endl;

        } else if (choice == "delete") {
            int id;
            cout << "Enter recipe ID to delete: ";
            cin >> id;
            try {
                manager.deleteRecipe(id);
                cout << "Recipe deleted." << endl;
            } catch (const exception& e) {
                cout << e.what() << endl;
            }

        } else if (choice == "search") {
            string query;
            cout << "Enter search query: ";
            cin.ignore();
            getline(cin, query);

            vector<Recipe> results = manager.searchRecipes(query);
            for (const auto& recipe : results) {
                cout << "Recipe Name: " << recipe.name << endl;
            }

        } else if (choice == "exit") {
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

int main() {
    RecipeManager manager;
    getUserInput(manager);
    return 0;
}
