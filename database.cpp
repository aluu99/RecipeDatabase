#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"

using namespace std;

    database::database() {
        cout << "Would you like to add a recipe? Y/N: ";
        
    }
    database::database(const database& orig)
    :recipe_box(orig.recipe_box) {}

    database::~database() {}
    
    int database::get_recipe_idx(int idx) const{

    }

    int database::get_recipe_name_full(string s) const{

    }

    int database::get_recipe_name_part(string s) const{

    }

    int database::get_recipe_diet_full(string s) const{

    }

    int database::get_recipe_diet_part(string s) const;
    int database::get_recipe_meal_full(string s) const;
    int database::get_recipe_meal_part(string s) const;
    int database::get_recipe_ingred_full(string s) const;
    int database::get_recipe_ingred_part(string s) const;
    int database::get_recipe_time_full(int t) const;
    int database::get_recipe_time_range(int t_begin, int t_end) const;

    void database::add_recipe();
    void database::delete_recipe();
    void database::edit_recipe();
    void database::print_recipe_name();
    void database::print_recipe_whole();