#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "recipe.h"
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;

class database {
private:
    // Store recipe info, including database file
    vector<recipe> recipe_box;
    vector<recipe*> rb_by_name;
    vector<recipe*> rb_by_time;
    string file = "database.txt";
    
    void read_file();
    void add_by_name(recipe& r);
    void add_by_time(recipe& r);
    

public:
    // Constructors and Destructor
    database();
    database(const database& orig);
    database(vector<recipe> recipes);
    database(string file_name);
    ~database();

    // Getter Methods
    recipe get(int i) const;
    string get_p(int i) const;
    int size() const;
    vector<recipe> get_recipe_box() const;
    vector<recipe*> get_rb_by_name() const;
    vector<recipe*> get_rb_by_time() const;
    recipe* get_rb_by_name_elem(int i) const;
    recipe* get_rb_by_time_elem(int i) const;

    // Search Methods
    void prep_results(vector<const recipe*>& results, vector<string>& print);
    void search_recipe_name_full(const string s,
        vector<const recipe*>& results, vector<string>& print);
    void search_recipe_name_part(const string s,
        vector<const recipe*>& results, vector<string>& print);
    void search_diet(const string s,
        vector<const recipe*>& results, vector<string>& print);
    void search_meal(const string s,
        vector<const recipe*>& results, vector<string>& print);
    void search_recipe_ingred_full(const string s,
        vector<const recipe*>& results, vector<string>& print);
    void search_recipe_ingred_part(const string s,
        vector<const recipe*>& results, vector<string>& print);
    void search_recipe_time_full(const int t,
        vector<const recipe*>& results, vector<string>& print);
    void search_recipe_time_range(const int t1, const int t2,
        vector<const recipe*>& results, vector<string>& print);

    // List Methods
    void list_names_alpha(vector<const recipe*>& results, vector<string>& print);
    void list_names_alpha_reverse(vector<const recipe*>& results, vector<string>& print);
    void list_times_up(vector<const recipe*>& results, vector<string>& print);
    void list_times_down(vector<const recipe*>& results, vector<string>& print);

    // Add & Delete Recipe Methods
    void add_recipe(recipe r);
    void delete_recipe(int i); 
        
    // Other Methods
    bool not_duplicate(recipe r);
    bool existing_url(string url); 
    void save_to_file();
    void print_recipe(vector<const recipe*>& r, int i);
};

// Helper Functions
vector<string> seperate_list(const string& list);
string vector_to_string(const vector<string> list);

template<typename T>
int linear_search(const vector<T>& v, const T key);
int binary_search_name(vector<recipe*> rb, int low, int high, string key);
int binary_search_time(vector<recipe*> rb, int low, int high, int key);

#endif