#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"

using namespace std;

struct ingred {
    string item;
    string amount;
};

class recipe {
private:
    string name;
    int time;
    string meal;
    vector<ingred> ingreds;
    vector<string> diet;

public:
    recipe();
    recipe(string n, int t, string m, vector<ingred> i, vector<string> d);
    recipe(const recipe& other);

    ~recipe();

    string get_name() const;
    int get_time() const;
    string get_meal() const;
    vector<ingred> get_ingreds() const;
    string get_diet(int i) const;
    ingred get_ingred(int i) const;
    string get_ingred_item(int i) const;
    string get_ingred_amount(int i) const;

    void set_name(string s);
    void set_time(int t);
    void set_meal(string s);
    
    void set_ingreds(vector<ingred> recipes);
    void add_ingred(ingred i);
    void delete_ingred(int index);
    
    void set_diet(vector<string> d);
    void add_diet(string d);
    void delete_diet(int index);

    void set_ingred(int i, string itm, string amt);
    void set_ingred_item(int i, string s);
    void set_ingred_amount(int i, string s);

    void print() const;
};


#endif