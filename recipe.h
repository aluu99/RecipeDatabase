#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"

using namespace std;

class recipe {
private:
    string name;
    string url;
    int time;
    string meal;
    vector<string> ingreds;
    vector<string> diet;
    int id;
    
    const vector<string> meal_options = {"breakfast", "lunch", "dinner", "snack", "drink", "dessert"};
    const vector<string> diet_options = {"meat, vegetarian, vegan, gluten-free, low-sugar, pescatarian, dairy free"};

public:
    recipe();
    recipe(string n, string url, int t, string m, vector<string> i, vector<string> d, int id);
    recipe(const recipe& other);

    ~recipe();

    int get_id() const;
    string get_name() const;
    string get_url() const;
    int get_time() const;
    vector<string> get_ingreds() const;
    string get_ingred(int i) const;
    vector<string> get_meals() const;
    vector<string> get_diets() const;

    void set_id(int i);
    void set_name(string s);
    void set_url(string url);
    void set_time(int t);
    void set_meal(string s);
    
    void set_ingreds(vector<string> recipes);
    void add_ingred(string i);
    void delete_ingred(int index);
    void change_ingred(int i, string s);
    
    void set_diet(vector<string> d);
    void add_diet(string d);
    void delete_diet(int index);



    void print() const;
};


#endif