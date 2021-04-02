#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "recipe.h"

using namespace std;

class database {
private:
    vector<recipe> recipe_box;

public:
    database();
    database(const database& orig);

    ~database();
    
    int get_recipe_idx(int idx) const;
    int get_recipe_name_full(string s) const;
    int get_recipe_name_part(string s) const;
    int get_recipe_diet_full(string s) const;
    int get_recipe_diet_part(string s) const;
    int get_recipe_meal_full(string s) const;
    int get_recipe_meal_part(string s) const;
    int get_recipe_ingred_full(string s) const;
    int get_recipe_ingred_part(string s) const;
    int get_recipe_time_full(int t) const;
    int get_recipe_time_range(int t_begin, int t_end) const;

    void add_recipe();
    void delete_recipe();
    void edit_recipe();
    void print_recipe_name();
    void print_recipe_whole();
};


#endif