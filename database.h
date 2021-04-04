#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "recipe.h"
#include <fstream>

using namespace std;

struct search_result {
    string name;
    int idx;
    int search_num; 
};

class database {
private:
    vector<recipe> recipe_box;
    vector<recipe> recipe_box_time_sorted;
    string file;

public:
    database();
    database(const database& orig);
    database(string file);

    ~database();

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

    void add_recipe(string n, string url, int t, string m, vector<string> i, vector<string> d);
    void delete_recipe();
    void edit_recipe();
    void print_recipe_name();
    void print_recipe_whole();
    void read_file(string f);
};


#endif