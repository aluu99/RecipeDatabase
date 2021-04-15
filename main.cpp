#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "menu.h"
#include "test.h"
#include <cmath>

using namespace std;

int main() {
    /*
    cout << "Made it to main!\n";
    recipe test;
    test.get_name();
    database test0("my_recipes.txt");
    for (int i = 0; i < 5; i++){
        cout << test0.get(i).get_name() << " " << test0.get(i).get_time() << endl;
    }
    // for (int i = 0; i < 5; i++){
    //     cout << test0.get_time(i).get_name() << " " << test0.get_time(i).get_time() << endl;
    // }
    test0.print_recipe_name(2);
    cout << "Back to main!\n";*/

    //recipe_tests();
    //menu_tests();
    database_tests();
}