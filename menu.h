#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"

using namespace std;
struct page{
    vector<string> options;
    int slct_start; // selection start
};

class menu{
private:

    const page home = {{"(1) Add a Recipe", "(2) Find a Recipe", "(3) List All Recipes", "(4) Quit"}, 0};
    const page find_recipe = {{"(1) By Name", "(2) By Time", "(3) By Ingredient", "(4) By Meal Type", "(5) By Diet"}, 4};
    const page find_by_name = {{"(1) By Exact Name", "(2) By Keyword"},9};
    const page find_by_time = {{"(1) By Exact Time", "(2) By Time Range"},11};
    const page find_by_ingred = {{"(1) By Exact Ingredient", "(2) By Keyword"},13};
    const page find_by_meal = {{"(1) Breakfast", "(2) Lunch", "(3) Dinner", "(4) Snack", "(5) Drink", "(6) Dessert"},15};
    const page find_by_diet = {{"(1) Meat", "(2) Vegetarian", "(3) Vegan", "(4) Gluten-free", " (5) Low-sugar", "(6) Pescatarian", " (7) Dairy free", " (8) N/A"},21};
    const page list_recipes = {{"(1) By Name Alphabetically", "(2) By Name Reverse Alphabetically", "(3) By Time Increasing", "(4) By Time Decreasing"}, 29};
    const page quit = {{"(1) Quit and Save", "(0) Main Menu"}, 33};

    vector<search_result> results;
    
    page p;
    page last_p;
    int user_choice;

public:
    menu();
    ~menu();
    
    void get_user_choice();
    void process_choice();
};

#endif