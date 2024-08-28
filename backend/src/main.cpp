#include "RecipeManager.h"
#include "UserManager.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "Choose an option:\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
}

void userMenu(RecipeManager &recipeManager, const string &token) {
    while(true) {
        cout << "\nChoose an option (create, read, update, delete, search, view, logout): ";
        string choice;
        cin >> choice;

        if(choice == "create") {
            Recipe recipe;
            cout << "Enter recipe name: ";
            cin.ignore();
            getline(cin, recipe.name);

            cout << "Enter ingredients (separated by commas): ";
            string ingredientsInput;
            getline(cin, ingredientsInput);
            recipe.setIngredientsFromString(ingredientsInput);

            cout << "Enter instructions: ";
            getline(cin, recipe.instructions);

            cout << "Enter tags (separated by commas): ";
            string tagsInput;
            getline(cin, tagsInput);
            recipe.setTagsFromString(tagsInput);

            int id = recipeManager.createRecipe(token, recipe);
            cout << "Recipe created with ID: " << id << endl;

        }
        else if(choice == "read") {
            int id;
            cout << "Enter recipe ID: ";
            cin >> id;
            try {
                Recipe recipe = recipeManager.readRecipe(id);
                cout << "Recipe Name: " << recipe.name << endl;
                cout << "Ingredients: " << recipe.getIngredientsAsString() << endl;
                cout << "Instructions: " << recipe.instructions << endl;
                cout << "Tags: " << recipe.getTagsAsString() << endl;
            }
            catch (const exception& e) {
                cout << e.what() << endl;
            }

        }
        else if(choice == "update") {
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
            recipe.setIngredientsFromString(ingredientsInput);

            cout << "Enter new instructions: ";
            getline(cin, recipe.instructions);

            cout << "Enter new tags (separated by commas): ";
            string tagsInput;
            getline(cin, tagsInput);
            recipe.setTagsFromString(tagsInput);

            recipeManager.updateRecipe(token, id, recipe);
            cout << "Recipe updated." << endl;

        }
        else if (choice == "delete") {
            int id;
            cout << "Enter recipe ID to delete: ";
            cin >> id;
            try {
                recipeManager.deleteRecipe(token, id);
                cout << "Recipe deleted." << endl;
            }
            catch(const exception& e) {
                cout << e.what() << endl;
            }

        }
        else if(choice == "search") {
            string query;
            cout << "Enter search query: ";
            cin.ignore();
            getline(cin, query);

            vector<Recipe> results = recipeManager.searchRecipes(query);

            for(const auto &recipe : results) {
                cout << "Recipe Name: " << recipe.name << endl;
            }

        }
        else if (choice == "view") {
            vector<Recipe> userRecipes = recipeManager.getUserRecipes(token);

            for(const auto& recipe : userRecipes) {
                cout << "Recipe ID: " << recipe.id << " - " << recipe.name << endl;
            }

        }
        else if(choice == "logout") {
            cout << "Logged out successfully." << endl;
            break;
        }
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

int main() {
    UserManager userManager;
    RecipeManager recipeManager;

    while(true) {
        displayMenu();
        string choice;
        cin >> choice;

        if(choice == "1") {
            string username, email, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter password: ";
            cin >> password;

            if(userManager.registerUser(username, email, password)) {
                cout << "Registration successful!" << endl;
            }
            else {
                cout << "Registration failed." << endl;
            }

        }
        else if (choice == "2") {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            try {
                string token = userManager.loginUser(username, password);
                cout << "Login successful!" << endl;
                userMenu(recipeManager, token);
            }
            catch (const exception &e) {
                cout << "Login failed: " << e.what() << endl;
            }

        }
        else if(choice == "3") {
            cout << "Exiting..." << endl;
            break;

        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}