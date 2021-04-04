#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "menu.h"
#include <cmath>

using namespace std;

int main() {
    cout << "Made it to main!\n";
    recipe test;
    test.get_name();
    database test0("my_recipes.txt");
    for (int i = 0; i < 8; i++){
        cout << test0.get(i).get_name() << " " << test0.get(i).get_time() << endl;
    }
    cout << "Back to main!\n";
}
