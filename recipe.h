#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"


using namespace std;

class recipe {
private:
    // Recipe fields
    string name;
    string url;
    int time;
    string meal;
    vector<string> ingreds;
    vector<string> diet;

public:
    // Constructors and Destructor
    recipe();
    recipe(string n, string url, int t, string m, vector<string> i, vector<string> d);
    recipe(const recipe& other);
    ~recipe();

    // Overload recipe operator=
    recipe& operator=(const recipe& r);
    
    // Getter Methods
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
    
    // Setter Methods
    void set_name(string s);
    void set_url(string url);
    void set_time(int t);
    void set_meal(string s);
    void set_ingreds(vector<string> recipes);
    void set_diets(vector<string> d);

    // Print recipe info
    void print() const;
};

// Overload recipe operator==
bool operator==(recipe a, recipe b);

#endif