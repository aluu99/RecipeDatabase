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
    string diet;

public:
    recipe();
    recipe(const recipe& other);

    ~recipe();

    string get_name() const;
    int get_time() const;
    string get_meal() const;
    string get_ingreds() const;
    string get_diet() const;
    string get_ingred(int i) const;
    string get_ingred_item(int i) const;
    string get_ingred_amount(int i) const;

    void set_name() const;
    void set_time() const;
    void set_meal() const;
    void set_ingreds() const;
    void set_diet() const;
    void set_ingred(int i) const;
    void set_ingred_item(int i) const;
    void set_ingred_amount(int i) const;

    void print() const;
};


#endif