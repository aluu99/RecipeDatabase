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



};


#endif