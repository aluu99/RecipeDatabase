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
                "snack",
                {},
                {"n/a"},
                0);
                
recipe test1(   "chicken soup",
                "www.eatsoup.ca",
                45,
                "lunch",
                {"chicken", "broth", "celery", "carrots"},
                {"meat", "dairy free"},
                1);
                
recipe test2(   "chocolate chip cookies",
                "https://www.allrecipes.com/recipe/277079/cookies/",
                20,
                "dessert",
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter","chocolate chips"},
                {"vegetarian", "low-sugar"},
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
                {"potato", "butter", "milk", "salt", "black pepper", "dried sage", "nutmeg", "cheese"},
                {"pescatarian"},
                5);
                
recipe test6(   "vanilla crepes",
                "https://www.allrecipes.com/recipe/95817/vanilla-crepes/",
                30,
                "breakfast",
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter"},
                {"n/a"},
                6); 

// recipes sorted by name in alpha order
vector<recipe> by_name = {test0, test1, test2, test3, test4, test5, test6};

// recipes sorted by time in ascending order
vector<recipe> by_time = {test0, test4, test3, test2, test6, test1, test5};

//database test_database(by_name, by_time);

void binary_search_name_test(){
    
}

/**************************TEST FUNCTIONS******************************/

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
    get_name_test();
    get_url_test();
    get_time_test();
    get_meal_test();
    get_ingreds_test();
    get_ingred_test();
    get_num_ingreds_test();
    get_diets_test();
    get_diet_test();
    get_num_diets_test();
    get_id_test();

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
    cout << "Testing copy recipe constructor: ";

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
    cout << "Testing get_name(): ";

    assert(test0.get_name() == " ");
    assert(test1.get_name() == "chicken soup");
    assert(test2.get_name() == "chocolate chip cookies");
    assert(test3.get_name() == " mojito");
    assert(test4.get_name() == "nachos ");
    assert(test5.get_name() == "shepherd's pie");
    assert(test6.get_name() == "vanilla crepes");

    cout << "PASSED. \n";
}

void get_url_test(){
    cout << "Testing get_url(): ";

    assert(test0.get_url() == " ");
    assert(test1.get_url() == "www.eatsoup.ca");
    assert(test2.get_url() == "https://www.allrecipes.com/recipe/277079/cookies/");
    assert(test3.get_url() == "https://www.allrecipes.com/recipe/277079/slurp/");
    assert(test4.get_url() == "https://www.allrecipes.com/recipe/chip/");
    assert(test5.get_url() == "https://www.allrecipes.com/recipe/277079/sweet-potato-and-venison-shepherds-pie/");
    assert(test6.get_url() == "https://www.allrecipes.com/recipe/95817/vanilla-crepes/");

    cout << "PASSED. \n";
}

void get_time_test(){
    cout << "Testing get_time(): ";

    assert(test0.get_time() == 0);
    assert(test1.get_time() == 45);
    assert(test2.get_time() == 20);
    assert(test3.get_time() == 2);
    assert(test4.get_time() == 0);
    assert(test5.get_time() == 170);
    assert(test6.get_time() == 30);

    cout << "PASSED. \n";
}

void get_meal_test(){
    cout << "Testing get_meal(): ";

    assert(test0.get_meal() == "snack");
    assert(test1.get_meal() == "lunch");
    assert(test2.get_meal() == "dessert");
    assert(test3.get_meal() == "drink");
    assert(test4.get_meal() == "snack");
    assert(test5.get_meal() == "dinner");
    assert(test6.get_meal() == "breakfast");

    cout << "PASSED. \n";
}
void get_ingreds_test(){
    cout << "Testing get_ingreds(): ";

    vector<string> expected_output = {};
    assert(test0.get_ingreds() == expected_output);
    expected_output = {"chicken", "broth", "celery", "carrots"};
    assert(test1.get_ingreds() == expected_output);
    expected_output = {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter","chocolate chips"};
    assert(test2.get_ingreds() == expected_output);
    expected_output = {"lime", "soda", "mint", "sugar", "ice", "salt"};
    assert(test3.get_ingreds() == expected_output);
    expected_output = {"chips", "cheese"};
    assert(test4.get_ingreds() == expected_output);
    expected_output = {"potato", "butter", "milk", "salt", "black pepper", "dried sage", "nutmeg", "cheese"};
    assert(test5.get_ingreds() == expected_output);
    expected_output = {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter"};
    assert(test6.get_ingreds() == expected_output);
    
    cout << "PASSED. \n";
}

// this helper loops through expected 
void get_ingred_helper(recipe t, vector<string> expected){
    for(int i = 0; i < expected.size(); i++){
        assert(t.get_ingred(i) == expected.at(i));
    }
}

void get_ingred_test(){
    cout << "Testing get_ingred(): ";

    vector<string> expected_output = {};
    
    get_ingred_helper(test0, expected_output);
    expected_output = {"chicken", "broth", "celery", "carrots"};
    get_ingred_helper(test1, expected_output);
    expected_output = {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter","chocolate chips"};
    get_ingred_helper(test2, expected_output);
    expected_output = {"lime", "soda", "mint", "sugar", "ice", "salt"};
    get_ingred_helper(test3, expected_output);
    expected_output = {"chips", "cheese"};
    get_ingred_helper(test4, expected_output);
    expected_output = {"potato", "butter", "milk", "salt", "black pepper", "dried sage", "nutmeg", "cheese"};
    get_ingred_helper(test5, expected_output);
    expected_output = {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter"};
    get_ingred_helper(test6, expected_output);

    cout << "PASSED. \n";
}

void get_num_ingreds_test(){
    cout << "Testing get_num_ingreds(): ";

    assert(test0.get_num_ingreds() == 0);
    assert(test1.get_num_ingreds() == 4);
    assert(test2.get_num_ingreds() == 8);
    assert(test3.get_num_ingreds() == 6);
    assert(test4.get_num_ingreds() == 2);
    assert(test5.get_num_ingreds() == 8);
    assert(test6.get_num_ingreds() == 7);

    cout << "PASSED. \n";
}

void get_diets_test(){
    cout << "Testing get_diets(): ";

    vector<string> expected_output = {"n/a"};
    assert(test0.get_diets() == expected_output);
    expected_output = {"meat", "dairy free"};
    assert(test1.get_diets() == expected_output); 
    expected_output = {"vegetarian", "low-sugar"};
    assert(test2.get_diets() == expected_output);
    expected_output = {"vegetarian", "gluten-free", "vegan", "low-sugar"};
    assert(test3.get_diets() == expected_output);
    expected_output = {"vegetarian"};
    assert(test4.get_diets() == expected_output);
    expected_output = {"pescatarian"};
    assert(test5.get_diets() == expected_output);
    expected_output = {"n/a"};
    assert(test6.get_diets() == expected_output);

    cout << "PASSED. \n";
}

void get_diet_test(){
    cout << "Testing get_diet_test(): ";

    assert(test0.get_diet(0) == "n/a");
    assert(test1.get_diet(0) == "meat");
    assert(test1.get_diet(1) == "dairy free");
    assert(test2.get_diet(0) == "vegetarian");
    assert(test2.get_diet(1) == "low-sugar");
    assert(test3.get_diet(0) == "vegetarian");
    assert(test3.get_diet(1) == "gluten-free");
    assert(test3.get_diet(2) == "vegan");
    assert(test3.get_diet(3) == "low-sugar");
    assert(test4.get_diet(0) == "vegetarian");
    assert(test5.get_diet(0) == "pescatarian");
    assert(test6.get_diet(0) == "n/a");

    cout << "PASSED. \n";
}

void get_num_diets_test(){
    cout << "Testing get_num_diets_test(): ";

    assert(test0.get_num_diets() == 1);
    assert(test1.get_num_diets() == 2);
    assert(test2.get_num_diets() == 2);
    assert(test3.get_num_diets() == 4);
    assert(test4.get_num_diets() == 1);
    assert(test5.get_num_diets() == 1);
    assert(test6.get_num_diets() == 1);

    cout << "PASSED. \n";
}

void get_id_test(){
    cout << "Testing get_id_test(): ";

    assert(test0.get_id() == 0);
    assert(test1.get_id() == 1);
    assert(test2.get_id() == 2);
    assert(test3.get_id() == 3);
    assert(test4.get_id() == 4);
    assert(test5.get_id() == 5);
    assert(test6.get_id() == 6);
    
    cout << "PASSED. \n";
}

