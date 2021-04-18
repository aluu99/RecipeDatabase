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

    const vector<string> home = {"Add a Recipe", "Delete a Recipe", "Find a Recipe", "List All Recipes", "Quit"};
    const vector<string> find_recipe = {"By Name", "By Time", "By Ingredient", "By Meal Type", "By Diet"};
    const vector<string> find_by_name = {"By Exact Name", "By Keyword"};
    const vector<string> find_by_time = {"By Exact Time", "By Time Range"};
    const vector<string> find_by_ingred = {"By Exact Ingredient", "By Keyword"};
    const vector<string> find_by_meal = {"Breakfast", "Lunch", "Dinner", "Snack", "Drink", "Dessert"};
    const vector<string> find_by_diet = {"Meat", "Vegetarian", "Vegan", "Gluten-free", "Low-sugar", "Pescatarian", "Dairy free", "N/A"};
    const vector<string> list_recipes = {"By Name Alphabetically", "By Name Reverse Alphabetically", "By Time Increasing", "By Time Decreasing"};
    const vector<string> quit = {"Quit and Save"};
    const vector<string> recipe_options = {"Print", "Delete"};
    const vector<string> empty = {};

    const vector<string> meal_options = {"breakfast", "lunch", "dinner", "snack", "drink", "dessert"};
    const vector<string> diet_options = {"meat", "vegetarian", "vegan", "gluten-free", "low-sugar", "pescatarian", "dairy free", "n/a"};

    vector<string> page;
    vector<string> last_page;
    database box;
    int user_choice;
    int recipe_choice;

    void display_choices(vector<string> choices);
    int get_valid_num_inp(int low, int high);
public:
    menu();
    menu(database* box);
    ~menu();
    
    vector<recipe*> recipe_results;
    vector<string> print_results;

    bool is_int(double d);
    void get_user_choice();
    void process_choice();
    void add_user_recipe();
};


#endif
    