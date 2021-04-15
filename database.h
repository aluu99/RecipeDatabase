#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "recipe.h"
#include <fstream>
#include <algorithm>

using namespace std;

struct recipe_time{
    int time;
    int id;
};

class database {
private:
    vector<recipe> recipe_box;
    vector<recipe*> recipe_box_name;
    vector<recipe*> recipe_box_time;
    string file;
    vector<string> seperate_list(const string& list);
    void save_file();
    
    void add_by_num(const recipe r);
    //void add_by_time(const recipe r);
    
    int binary_search_time(vector<recipe_time> r, int low, int high, int key);

public:
    vector<recipe> testing;
    database();
    database(vector<recipe> recipes);
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


    void add_by_name(recipe r);
    void add_by_time(recipe r);
    void add_recipe(recipe r);
    void delete_recipe(int i);
    void edit_recipe(int i);
    void print_recipe_name(int i);
    void print_recipe_whole(int i);
    //void read_file(string f);
};


#endif