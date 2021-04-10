#include <iostream>
#include <vector>
#include <cassert>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "menu.h"
#include "test.h"
#include <cmath>

using namespace std;

/************************* DATABASE INFO ****************************/
recipe test0(   " ",
                " ",
                0,
                " ",
                {},
                {},
                0);
                
recipe test1(   "chicken soup",
                "www.eatsoup.ca",
                45,
                "lunch",
                {"chicken", "broth", "celery", "carrots"},
                {"meat", "diary free"},
                1);
                
recipe test2(   "chocolate chip cookies",
                "https://www.allrecipes.com/recipe/277079/cookies/",
                20,
                "dessert",
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter","chocolate chips"},
                {"vegetarian"},
                2);
                
recipe test3(   " mojito",
                "https://www.allrecipes.com/recipe/277079/slurp/",
                2,
                "drink",
                {"lime", "soda", "mint", "sugar", "ice", "salt"},
                {"vegetarian", "gluten-free", "vegan", "low-sugar"},
                3); 

recipe test4(   "nachos ",
                "https://www.allrecipes.com/recipe/chip/",
                0,
                "snack",
                {"chips", "cheese"},
                {"vegetarian"},
                4); 

recipe test5(   "shepherd's pie",
                "https://www.allrecipes.com/recipe/277079/sweet-potato-and-venison-shepherds-pie/",
                170,
                "dinner",
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter",},
                {"pescatarian"},
                5);
                
recipe test6(   "vanilla crepes",
                "https://www.allrecipes.com/recipe/95817/vanilla-crepes/",
                30,
                "breakfast",
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter",},
                {"n/a"},
                6); 

// recipes sorted by name in alpha order
vector<recipe> by_name = {test0, test1, test2, test3, test4, test5, test6};

// recipes sorted by time in ascending order
vector<recipe> by_time = {test0, test4, test3, test2, test6, test1, test5};

//database test_database(by_name, by_time);

void binary_search_name_test(){
    
}

/**************************tTEST FUNCTIONS******************************/

// calls test functions for database class
void database_tests(){
    binary_search_name_test();
}

// calls test functions for recipe class
void recipe_tests(){
    cout << "Testing recipe class tests ... \n";
    
    recipe_dflt_constructor_test();
    recipe_reg_constructor_test();
    recipe_copy_constructor_test();

    cout << "All recipe class tests passed! \n";
}

/****************************RECIPE TEST FUNCTIONS************************************/

// CONSTRUCTOR TESTS
void recipe_dflt_constructor_test(){
    cout << "Testing default recipe constructor: ";

    recipe test(); 

    cout <<  "PASSED\n";
}

void recipe_reg_constructor_test(){
    cout << "Testing regular recipe constructor: ";

    recipe test("name", "url", 0, "meal", {"ingred 1", "ingred 2"}, {"diet 1", "diet 2"}, 1);

    assert(test.get_name()    == "name");
    assert(test.get_url()     == "url");
    assert(test.get_time()    == 0);
    assert(test.get_meal()    == "meal");
    assert(test.get_ingred(0) == "ingred 1");
    assert(test.get_ingred(1) == "ingred 2");
    assert(test.get_diet(0)   == "diet 1");
    assert(test.get_diet(1)   == "diet 2");
    assert(test.get_id()      == 1);

    cout << "PASSED \n";
}

void recipe_copy_constructor_test(){
    cout << "Testing co recipe constructor: ";

    for (int i = 0; i < by_name.size(); i++){
        recipe test(by_name.at(i));
        assert(test.get_name() == by_name.at(i).get_name());
        assert(test.get_url()  == by_name.at(i).get_url());
        assert(test.get_time() == by_name.at(i).get_time());
        assert(test.get_meal() == by_name.at(i).get_meal());
        for (int j = 0; j < by_name.at(i).get_num_ingreds(); j++){
            assert(test.get_ingred(j) == by_name.at(i).get_ingred(j));
        }
        for (int j = 0; j < by_name.at(i).get_num_diets(); j++){
            assert(test.get_diet(j) == by_name.at(i).get_diet(j));
        }
        assert(test.get_id() == by_name.at(i).get_id());
    }
    
    cout << "PASSED  \n";
}

// GETTER METHODS TESTS
void get_name_test(){
    
}

void get_url_test(){

}

void get_time_test(){

}

void get_meal_test(){

}
void get_ingreds_test(){

}

void get_ingred_test(){

}

void get_num_ingreds_test(){

}

void get_diets_test(){

}

void get_diet_test(){

}

void get_num_diets_test(){

}

void get_id_test(){

}

