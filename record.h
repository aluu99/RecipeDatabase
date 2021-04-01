#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"

using namespace std;

struct ingred {
    string item;
    string amount;
};

class record {
private:
    string name;
    int time;
    string meal;
    vector<ingred> ingreds;
    string diet;

public:
    record();
    record(const record& other);

    ~record();

    int get_name() const;
    int get_time() const;
    int get_meal() const;
    int get_ingreds() const;
    int get_diet() const;
    int get_ingred(int i) const;
    int get_ingred_item(int i) const;
    int get_ingred_amount(int i) const;

    int set_name() const;
    int set_time() const;
    int set_meal() const;
    int set_ingreds() const;
    int set_diet() const;
    int set_ingred(int i) const;
    int set_ingred_item(int i) const;
    int set_ingred_amount(int i) const;

    void print() const;
};


#endif