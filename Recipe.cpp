#include "Recipe.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>  


string Recipe::serialize() const {
    ostringstream oss;
    oss << name << "\n";
    for (const auto& ingredient : ingredients) {
        oss << ingredient << ";";
    }
    oss << "\n" << instructions << "\n";
    for (const auto& tag : tags) {
        oss << tag << ";";
    }
    return oss.str();
}

Recipe Recipe::deserialize(const string& data) {
    istringstream iss(data);
    Recipe recipe;
    getline(iss, recipe.name);

    string line;
    getline(iss, line);
    istringstream ingredientsStream(line);
    string ingredient;
    while (getline(ingredientsStream, ingredient, ';')) {
        if (!ingredient.empty()) recipe.ingredients.push_back(ingredient);
    }

    getline(iss, recipe.instructions);

    getline(iss, line);
    istringstream tagsStream(line);
    string tag;
    while (getline(tagsStream, tag, ';')) {
        if (!tag.empty()) recipe.tags.push_back(tag);
    }

    return recipe;
}
