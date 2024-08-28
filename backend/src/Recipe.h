#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

using namespace std;

class Recipe {
public:
    int id;
    string name;
    vector<string> ingredients;
    string instructions;
    vector<string> tags;

    string getIngredientsAsString() const;
    void setIngredientsFromString(const string& ingredientsStr);
    string getTagsAsString() const;
    void setTagsFromString(const string& tagsStr);
};

#endif