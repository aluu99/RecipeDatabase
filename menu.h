#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"

using namespace std;

class menu{
private:

    const vector<string> home = {"(1) Add a Recipe", "(2) Find a Recipe", "(3) List All Recipes", "(4) Quit"};
    const vector<string> find_recipe = {"(1) By Name", "(2) By Time", "(3) By Ingredient", "(4) By Meal Type", "(5) By Diet"};
    const vector<string> find_by_name = {"(1) By Exact Name", "(2) By Keyword"};
    const vector<string> find_by_time = {"(1) By Exact Time", "(2) By Time Range"};
    const vector<string> find_by_ingred = {"(1) By Exact Ingredient", "(2) By Keyword"};
    const vector<string> find_by_meal = {"(1) Breakfast", "(2) Lunch", "(3) Dinner", "(4) Snack", "(5) Drink", "(6) Dessert"};
    const vector<string> find_by_diet = {"(1) Meat", "(2) Vegetarian", "(3) Vegan", "(4) Gluten-free", " (5) Low-sugar", "(6) Pescatarian", " (7) Dairy free", " (8) N/A"};
    const vector<string> list_recipes = {"(1) By Name Alphabetically", "(2) By Name Reverse Alphabetically", "(3) By Time Increasing", "(4) By Time Decreasing"};
    const vector<string> quit = {"(1) Quit and Save"};
    const vector<string> recipe_options = {"(1) Print", "(2) Edit", "(3) Delete"};

    vector<string> search_results;
    vector<int> results_id;
    
    vector<string> page;
    vector<string> last_page;
    int user_choice;

public:
    menu();
    ~menu();
    
    bool is_int(double d);
    void get_user_choice();
    void process_choice();
};

#endif