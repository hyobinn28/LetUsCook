#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

using namespace std;

struct Recipe {
    string name;
    vector<string> ingredients;
    string instructions;
    vector<string> tags;

    string serialize() const; // Convert Recipe to a string
    static Recipe deserialize(const string& data); // Convert string back to Recipe
};

#endif // RECIPE_H
