#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "recipe.h"
#include <fstream>

using namespace std;

struct recipe_time{
    int time;
    int id;
};

class database {
private:
    vector<recipe> recipe_box;
    vector<recipe_time> recipe_box_time;
    string file;
    int id_total;
    void add_by_name(const recipe r);
    void add_by_num(const recipe r);
    void add_by_time(const recipe r);
    int binary_search_name(vector<recipe> const r, int low, int high, string key);
    int binary_search_time(vector<recipe_time> r, int low, int high, int key);

public:
    database();
    database(vector<recipe> by_name, vector<recipe> by_time);
    database(const database& orig);
    database(string file);

    ~database();

    recipe get(int i) const;
    recipe get_from_time(int i) const;
    vector<int> search_recipe_name_full(string s) const;
    vector<int> search_recipe_name_part(string s) const;
    vector<int> search_recipe_diet_full(string s) const;
    vector<int> search_recipe_diet_part(string s) const;
    vector<int> search_recipe_meal_full(string s) const;
    vector<int> search_recipe_meal_part(string s) const;
    vector<int> search_recipe_ingred_full(string s) const;
    vector<int> search_recipe_ingred_part(string s) const;
    vector<int> search_recipe_time_full(int t) const;
    vector<int> search_recipe_time_range(int t_begin, int t_end) const;

    void add_recipe(recipe r);
    void delete_recipe(int i);
    void edit_recipe(int i);
    void print_recipe_name(int i);
    void print_recipe_whole(int i);
    //void read_file(string f);
};


#endif