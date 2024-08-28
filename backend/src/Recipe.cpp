#include "Recipe.h"
#include <sstream>

using namespace std;

string Recipe::getIngredientsAsString() const {
    stringstream ss;
    
    for(size_t i = 0; i < ingredients.size(); ++i) {
        ss << ingredients[i];

        if(i < ingredients.size() - 1) {
            ss << ",";
        }
    }
    return ss.str();
}

void Recipe::setIngredientsFromString(const string &ingredientsStr) {
    stringstream ss(ingredientsStr);
    string item;

    while(getline(ss, item, ',')) {
        ingredients.push_back(item);
    }
}

string Recipe::getTagsAsString() const {
    stringstream ss;

    for(size_t i = 0; i < tags.size(); ++i) {
        ss << tags[i];

        if(i < tags.size() - 1) {
            ss << ",";
        }
    }
    return ss.str();
}

void Recipe::setTagsFromString(const string &tagsStr) {
    stringstream ss(tagsStr);
    string item;

    while(getline(ss, item, ',')) {
        tags.push_back(item);
    }
}
