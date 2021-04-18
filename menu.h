#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include <limits.h>

using namespace std;

class menu{
private:
    // Page Choices

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
    const vector<string> confirm_deletion = {"Yes", "No"};

    vector<const recipe*> recipe_results;   // Recipes that meet desired search field
    vector<string> print_results;           // The recipe information printed to the screen

    // Valid meal and diet inputs
    const vector<string> meal_options = {"breakfast", "lunch", "dinner", "snack", "drink", "dessert"};
    const vector<string> diet_options = {"meat", "vegetarian", "vegan", "gluten-free", "low-sugar", "pescatarian", "dairy free", "n/a"};

    vector<string> page;        // Current page 
    vector<string> last_page;   // Previous page 
    database box;               // Name of the database
    int user_choice;            // The choice user inputted
    int recipe_choice;          // The choice of recipe user selected
    
    // Main Methods
    void display_choices(vector<string> choices); 
    void get_user_choice();
    void process_choice();
    void add_user_recipe();

    // Helper Methods
    int get_valid_num_inp(int low, int high, const bool auto_prompt);
    string get_string_inp(string prompt);
    void to_lowercase(string &s);
    bool is_int(double d);

    void divide_pages();
    void print_title(string page_title);
    void display_title();

public:
    menu();
    ~menu();
};

bool is_url(string url);

#endif
    