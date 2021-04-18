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

public:
    recipe();
    recipe(string n, string url, int t, string m, vector<string> i, vector<string> d);
    recipe(const recipe& other);
    recipe& operator=(const recipe& r);

    ~recipe();

    
    string get_name() const;
    string get_url() const;
    int get_time() const;
    string get_meal() const;
    vector<string> get_ingreds() const;
    string get_ingred(int i) const;
    int get_num_ingreds() const;
    vector<string> get_diets() const;
    string get_diet(int i) const;
    int get_num_diets() const;
    
    void set_name(string s);
    void set_url(string url);
    void set_time(int t);
    void set_meal(string s);
    void set_ingreds(vector<string> recipes);
    void set_diets(vector<string> d);
    
    void add_ingred(string i);
    void change_ingred(int i, string s);
    void delete_ingred(int index);
    
    void add_diet(string d);
    void delete_diet(int index);

    void print() const;
};


#endif
        
