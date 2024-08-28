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

    crow::SimpleApp app; 

    RecipeManager recipeManager;
    UserManager userManager;

    // Define a simple "Hello, World!" route
    CROW_ROUTE(app, "/")
    ([]() {
        return "Hello, World!";
    });

    // Define a route to get a recipe by ID
    CROW_ROUTE(app, "/recipe/<int>")
    ([&recipeManager](int id) {
        try {
            Recipe recipe = recipeManager.readRecipe(id);
            std::stringstream result;
            result << "Recipe Name: " << recipe.name << "\n"
                   << "Ingredients: " << recipe.getIngredientsAsString() << "\n"
                   << "Instructions: " << recipe.instructions << "\n"
                   << "Tags: " << recipe.getTagsAsString();
            return crow::response(result.str());
        } catch (const std::exception& e) {
            return crow::response(404, "Recipe not found.");
        }
    });

    // Define a route to create a new recipe (for simplicity, we're not doing full validation)
    CROW_ROUTE(app, "/recipe").methods(crow::HTTPMethod::POST)
    ([&recipeManager](const crow::request& req) {
        auto x = crow::json::load(req.body);
        if (!x) {
            return crow::response(400, "Invalid JSON");
        }

        Recipe recipe;
        recipe.name = x["name"].s();
        recipe.setIngredientsFromString(x["ingredients"].s());
        recipe.instructions = x["instructions"].s();
        recipe.setTagsFromString(x["tags"].s());

        // For simplicity, we skip token handling in this basic example
        int id = recipeManager.createRecipe("dummy-token", recipe);
        return crow::response(201, "Recipe created with ID: " + std::to_string(id));
    });

    // Run the Crow application on port 8080
    app.port(8080).multithreaded().run();
}
    return 0;
}
