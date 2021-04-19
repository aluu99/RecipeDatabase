#include <iostream>
#include <vector>
#include <cassert>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "test.h"
#include <cmath>

using namespace std;

/************************* DATABASE INFO ****************************/
recipe test0(   " ",
                " ",
                1,
                "snack",
                {},
                {"n/a"});

recipe test1(   "chicken soup",
                "www.eatsoup.ca",
                45,
                "lunch",
                {"chicken", "broth", "celery", "carrots"},
                {"meat", "dairy free"});
                
recipe test2(   "chocolate chip cookies",
                "https://www.allrecipes.com/recipe/277079/cookies/",
                20,
                "dessert",
                {"milk", "egg yolks", "vanilla extract", "flour", 
                    "sugar", "salt", "butter","chocolate chips"},
                {"vegetarian", "low-sugar"});
                
recipe test3(   " mojito",
                "https://www.allrecipes.com/recipe/277079/slurp/",
                2,
                "drink",
                {"lime", "soda", "mint", "sugar", "ice", "salt"},
                {"vegetarian", "gluten-free", "vegan", "low-sugar"}); 

recipe test4(   "nachos ",
                "https://www.allrecipes.com/recipe/chip/",
                10,
                "snack",
                {"chips", "cheese"},
                {"vegetarian"}); 

recipe test5(   "shepherd's pie",
                "https://www.allrecipes.com/recipe/277079/shepherds-pie/",
                170,
                "dinner",
                {"potato", "butter", "milk", "salt", "black pepper", 
                 "dried sage", "nutmeg", "cheese"},
                {"pescatarian"});
                
recipe test6(   "vanilla crepes",
                "https://www.allrecipes.com/recipe/95817/vanilla-crepes/",
                30,
                "breakfast",
                {"milk", "egg yolks", "vanilla extract", "flour", 
                "sugar", "salt", "butter"},
                {"n/a"}); 

recipe test7(   "apple pie",
                "https://www.allrecipes.com/recipe/95817/pie/",
                120,
                "dessert",
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", 
                 "salt", "butter", "apples"},
                {"gluten-free"});

// recipes sorted by name in alpha order
vector<recipe> recipes = {test0, test1, test2, test3, test4, test5, test6, test7};

database test_database(recipes);

/**************************TEST FUNCTIONS******************************/

// calls test functions for database class
void database_tests(){
    cout << "Testing database class tests ... \n";
    
    database_dflt_constructor_test();
    database_copy_constructor_test();
    database_vector_constructor_test();
    database_file_constructor_test();

    read_file_test();
    save_to_file_test();
    seperate_list_test();
    binary_search_name_test();
    binary_search_time_test();
    add_recipe_test();
    delete_recipe_test();
    add_recipe_test();

    cout << "All database class tests passed! \n";
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

    set_name_test();
    set_url_test();
    set_time_test();
    set_meal_test();
    set_ingreds_test();
    set_diets_test();
    test1.print();

    cout << "All recipe class tests passed! \n";
}

/****************************MENU TEST FUNCTIONS******************************/

/****************************DATABASE TEST FUNCTIONS**************************/

// CONSTRUCTOR TESTS

void database_dflt_constructor_test(){
    cout << "Testing default recipe constructor: ";

    database test();

    cout << "PASSED\n";
}

void database_copy_constructor_test(){
    cout << "Testing copy database constructor: ";

    database test(test_database);
    for (int i = 0; i < recipes.size(); i++){
        assert(test.get(i).get_name() == recipes[i].get_name());
        assert(test.get(i).get_url() == recipes[i].get_url());
        assert(test.get(i).get_time() == recipes[i].get_time());
        assert(test.get(i).get_meal() == recipes[i].get_meal());
        assert(test.get(i).get_ingreds() == recipes[i].get_ingreds());
        assert(test.get(i).get_diets() == recipes[i].get_diets());
    }

    cout << "PASSED \n";
}

void database_vector_constructor_test(){
    cout << "Testing vector database constructor: ";

    database test(recipes);
    for (int i = 0; i < recipes.size(); i++){
        assert(test.get(i).get_name() == recipes[i].get_name());
        assert(test.get(i).get_url() == recipes[i].get_url());
        assert(test.get(i).get_time() == recipes[i].get_time());
        assert(test.get(i).get_meal() == recipes[i].get_meal());
        assert(test.get(i).get_ingreds() == recipes[i].get_ingreds());
        assert(test.get(i).get_diets() == recipes[i].get_diets());
    }


    cout << "PASSED \n";
}

void database_file_constructor_test(){
    cout << "Testing file database constructor: ";

    database test("test.txt");
    database test0("test2.txt");
    for (int i = 0; i < test0.size(); i++){
        assert(test0.get(i).get_name() == recipes[i].get_name());
        assert(test0.get(i).get_url() == recipes[i].get_url());
        assert(test0.get(i).get_time() == recipes[i].get_time());
        assert(test0.get(i).get_meal() == recipes[i].get_meal());
        assert(test0.get(i).get_ingreds() == recipes[i].get_ingreds());
        assert(test0.get(i).get_diets() == recipes[i].get_diets());
    }

    cout << "PASSED \n";
}

// METHOD TESTS

void read_file_test(){
    cout << "Testing read_file_test(): ";

    database test("test.txt");
    vector<string> list;
    assert(test.get(0).get_name() == "nothing");
    assert(test.get(0).get_url() == "www");
    assert(test.get(0).get_time() == 10);
    assert(test.get(0).get_meal() == "snack");
    list = {"nope"};
    assert(test.get(0).get_ingreds() == list);
    list = {"n/a"};
    assert(test.get(0).get_diets() == list);

    assert(test.get(1).get_name() == "chicken soup");
    assert(test.get(1).get_url() == "www.eatsoup.ca");
    assert(test.get(1).get_time() == 45);
    assert(test.get(1).get_meal() == "lunch");
    list = {"chicken", "broth", "celery", "carrots"};
    assert(test.get(1).get_ingreds() == list);
    list = {"meat", "dairy free"};
    assert(test.get(1).get_diets() == list);

    assert(test.get(2).get_name() == "chocolate chip cookies");
    assert(test.get(2).get_url() == "https://www.allrecipes.com/recipe/277079/cookies/");
    assert(test.get(2).get_time() == 20);
    assert(test.get(2).get_meal() == "dessert");
    list = {"milk", "egg yolks", "vanilla extract", "flour", 
            "sugar", "salt", "butter","chocolate chips"};
    assert(test.get(2).get_ingreds() == list);
    list = {"vegetarian", "low-sugar"};
    assert(test.get(2).get_diets() == list);

    cout << "PASSED\n";
}

void save_to_file_test(){
    cout << "Testing save_to_file_test(): ";

    database test(recipes);
    test.save_to_file();

    cout << "PASSED\n";
}

void seperate_list_test(){
    cout << "Testing seperate_list_test(): ";

    string test = "apple, banana, cucumber";
    vector<string> expected = {"apple", "banana", "cucumber"};

    assert(seperate_list(test) == expected);

    cout << "PASSED\n";
}

void binary_search_name_test(){
    cout << "Testing binary_search_name_test(): ";

    vector<recipe> test = recipes;
    vector<recipe*> pntr_array;

    for(int i = 0; i < test.size(); i++){
        pntr_array.push_back(&test[i]);
    }

    int notInDatabase = binary_search_name(pntr_array, 0, pntr_array.size(), "chicken");
    int inDatabase = binary_search_name(pntr_array, 0, pntr_array.size(), "chicken soup");

    assert(notInDatabase == 1);
    assert(inDatabase == 1);

    cout << "PASSED\n";
}

void binary_search_time_test(){
    cout << "Testing binary_search_time_test(): ";

    recipe one_min(   " ",
                " ",
                1,
                "snack",
                {},
                {"n/a"});

    recipe forty_five_min(   "chicken soup",
                "www.eatsoup.ca",
                45,
                "lunch",
                {"chicken", "broth", "celery", "carrots"},
                {"meat", "dairy free"});
                
    recipe twenty_min(   "chocolate chip cookies",
                "https://www.allrecipes.com/recipe/277079/cookies/",
                20,
                "dessert",
                {"milk", "egg yolks", "vanilla extract", "flour", 
                 "sugar", "salt", "butter","chocolate chips"},
                {"vegetarian", "low-sugar"});

    vector<recipe> test = {one_min, twenty_min, forty_five_min};
    vector<recipe*> test_pntr_array;

    for(int i = 0; i < test.size(); i++){
        test_pntr_array.push_back(&test[i]);
    }

    int notInDatabase = binary_search_time(test_pntr_array, 0, test_pntr_array.size(), 2);
    int inDatabase = binary_search_time(test_pntr_array, 0, test_pntr_array.size(), 20);

    assert(inDatabase == 1);
    assert(notInDatabase == 1);

    cout << "PASSED\n";
}

void add_recipe_test(){
    cout << "Testing add_by_time_test(): ";

    recipe one_min(   " ",
                " ",
                1,
                "snack",
                {},
                {"n/a"});

    recipe forty_five_min(   "chicken soup",
                "www.eatsoup.ca",
                45,
                "lunch",
                {"chicken", "broth", "celery", "carrots"},
                {"meat", "dairy free"});
                
    recipe twenty_min(   "chocolate chip",
                "https://www.allrecipes.com/recipe/277079/cookies/",
                20,
                "dessert",
                {"milk", "egg yolks", "vanilla extract", "flour", 
                 "sugar", "salt", "butter","chocolate chips"},
                {"vegetarian", "low-sugar"});

    vector<recipe> test_box = {one_min, twenty_min, forty_five_min};
    database test(test_box);

    recipe thirty_min(   "chocolate chip cookies",
                "https://www.allrecipes.com/recipe/277079/cookies/",
                30,
                "dessert",
                {"milk", "egg yolks", "vanilla extract", "flour", 
                 "sugar", "salt", "butter","chocolate chips"},
                {"vegetarian", "low-sugar"});

    test.add_recipe(thirty_min);

    assert(test.get_rb_by_time()[0]->get_time() == one_min.get_time());
    assert(test.get_rb_by_time()[1]->get_time() == twenty_min.get_time());
    assert(test.get_rb_by_time()[2]->get_time() == thirty_min.get_time());
    assert(test.get_rb_by_time()[3]->get_time() == forty_five_min.get_time());

    assert(test.get_rb_by_name()[0]->get_name() == one_min.get_name());
    assert(test.get_rb_by_name()[1]->get_name() == forty_five_min.get_name());
    assert(test.get_rb_by_name()[2]->get_name() == twenty_min.get_name());
    assert(test.get_rb_by_name()[3]->get_name() == thirty_min.get_name());

    cout << "PASSED\n";
}

void delete_recipe_test(){
    cout << "Testing delete_recipe_test(): ";

    database test(recipes);
    vector<recipe*> rb_name = test.get_rb_by_name();
    vector<recipe*> rb_time = test.get_rb_by_time();
    test.delete_recipe(0);
    assert(test.size() + 1 == recipes.size());
    assert(operator==(test.get(0), recipes.at(1)));
    assert(operator==(test.get(1), recipes.at(2)));
    assert(operator==(test.get(2), recipes.at(3)));
    assert(operator==(test.get(3), recipes.at(4)));
    assert(operator==(test.get(4), recipes.at(5)));
    assert(operator==(test.get(5), recipes.at(6)));
    assert(operator==(test.get(6), recipes.at(7)));

    vector<recipe*> rb_name_new = test.get_rb_by_name();
    vector<recipe*> rb_time_new = test.get_rb_by_time();
    assert(rb_name.size() == rb_name_new.size() + 1);
    assert(rb_time.size() == rb_time_new.size() + 1);
    
    for (int i = 0; i <rb_name_new.size(); i ++){
        assert(rb_name_new.at(i) == rb_name.at(i+1));
        assert(rb_time_new.at(i) == rb_time.at(i+1));
    }

    cout << "PASSED\n";
}

/****************************RECIPE TEST FUNCTIONS****************************/

// CONSTRUCTOR TESTS
void recipe_dflt_constructor_test(){
    cout << "Testing default recipe constructor: ";

    recipe recipe_test();

    cout <<  "PASSED\n";
}

void recipe_reg_constructor_test(){
    cout << "Testing regular recipe constructor: ";

    recipe test("name", "url", 0, "meal", 
                {"ingred 1", "ingred 2"}, {"diet 1", "diet 2"});

    assert(test.get_name()    == "name");
    assert(test.get_url()     == "url");
    assert(test.get_time()    == 0);
    assert(test.get_meal()    == "meal");
    assert(test.get_ingred(0) == "ingred 1");
    assert(test.get_ingred(1) == "ingred 2");
    assert(test.get_diet(0)   == "diet 1");
    assert(test.get_diet(1)   == "diet 2");

    cout << "PASSED \n";
}

void recipe_copy_constructor_test(){
    cout << "Testing copy recipe constructor: ";

    for (int i = 0; i < recipes.size(); i++){
        recipe test(recipes.at(i));
        assert(test.get_name() == recipes.at(i).get_name());
        assert(test.get_url()  == recipes.at(i).get_url());
        assert(test.get_time() == recipes.at(i).get_time());
        assert(test.get_meal() == recipes.at(i).get_meal());
        for (int j = 0; j < recipes.at(i).get_num_ingreds(); j++){
            assert(test.get_ingred(j) == recipes.at(i).get_ingred(j));
        }
        for (int j = 0; j < recipes.at(i).get_num_diets(); j++){
            assert(test.get_diet(j) == recipes.at(i).get_diet(j));
        }
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
    assert(test5.get_url() == "https://www.allrecipes.com/recipe/277079/shepherds-pie/");
    assert(test6.get_url() == "https://www.allrecipes.com/recipe/95817/vanilla-crepes/");

    cout << "PASSED. \n";
}

void get_time_test(){
    cout << "Testing get_time(): ";

    assert(test0.get_time() == 1);
    assert(test1.get_time() == 45);
    assert(test2.get_time() == 20);
    assert(test3.get_time() == 2);
    assert(test4.get_time() == 10);
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
    expected_output = {"milk", "egg yolks", "vanilla extract", "flour", 
                        "sugar", "salt", "butter","chocolate chips"};
    assert(test2.get_ingreds() == expected_output);
    expected_output = {"lime", "soda", "mint", "sugar", "ice", "salt"};
    assert(test3.get_ingreds() == expected_output);
    expected_output = {"chips", "cheese"};
    assert(test4.get_ingreds() == expected_output);
    expected_output = {"potato", "butter", "milk", "salt", "black pepper", 
                        "dried sage", "nutmeg", "cheese"};
    assert(test5.get_ingreds() == expected_output);
    expected_output = {"milk", "egg yolks", "vanilla extract", "flour", 
                        "sugar", "salt", "butter"};
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
    expected_output = {"milk", "egg yolks", "vanilla extract", "flour", 
                        "sugar", "salt", "butter","chocolate chips"};
    get_ingred_helper(test2, expected_output);
    expected_output = {"lime", "soda", "mint", "sugar", "ice", "salt"};
    get_ingred_helper(test3, expected_output);
    expected_output = {"chips", "cheese"};
    get_ingred_helper(test4, expected_output);
    expected_output = {"potato", "butter", "milk", "salt", "black pepper", 
                        "dried sage", "nutmeg", "cheese"};
    get_ingred_helper(test5, expected_output);
    expected_output = {"milk", "egg yolks", "vanilla extract", "flour", 
                        "sugar", "salt", "butter"};
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

// SETTER METHOD TESTS

void set_name_test(){
    cout << "Testing set_name_test(): ";
    
    recipe testA(test0);

    string name = "pie";
    testA.set_name(name);
    assert(testA.get_name() == name);
    
    name = " pie ";
    testA.set_name(name);
    assert(testA.get_name() == name);
    
    name = " p i e !";
    testA.set_name(name);
    assert(testA.get_name() == name);
    
    cout << "PASSED. \n";
}

void set_url_test(){
    cout << "Testing set_url_test(): ";
    
    recipe testA(test0);

    string url = "https://wwww.recipe.com";
    testA.set_url(url);
    assert(testA.get_url() == url);
    
    url = "wwww.recipe.com";
    testA.set_url(url);
    assert(testA.get_url() == url);
    
    cout << "PASSED. \n";
}

void set_time_test(){
    cout << "Testing set_time_test(): ";
    
    recipe testA(test0);

    int time = 25;
    testA.set_time(time);
    assert(testA.get_time() == time);
    
    cout << "PASSED. \n";
}

void set_meal_test(){
    cout << "Testing set_meal_test(): ";
    
    recipe testA(test0);

    string meal = "breakfast";
    testA.set_meal(meal);
    assert(testA.get_meal() == meal);

    meal = "lunch";
    testA.set_meal(meal);
    assert(testA.get_meal() == meal);

    meal = "dinner";
    testA.set_meal(meal);
    assert(testA.get_meal() == meal);
    
    cout << "PASSED. \n";
}

void set_ingreds_test(){
    cout << "Testing set_ingreds_test(): ";
    
    recipe testA(test0);

    vector<string> ingreds = {"banana", "turnip", "milk"};
    testA.set_ingreds(ingreds);
    assert(testA.get_ingreds() == ingreds);
    
    ingreds = {"banana", "", "milk"};
    testA.set_ingreds(ingreds);
    assert(testA.get_ingreds() == ingreds);
    
    ingreds = {};
    testA.set_ingreds(ingreds);
    assert(testA.get_ingreds() == ingreds);

    cout << "PASSED. \n";
}

void set_diets_test(){
    cout << "Testing set_diets_test(): ";
    
    recipe testA(test0);

    vector<string> diets = {"vegan", "vegetarian", "dairy-free"};
    testA.set_diets(diets);
    assert(testA.get_diets() == diets);

    diets = {"vegan", "", "dairy-free"};
    testA.set_diets(diets);
    assert(testA.get_diets() == diets);

    diets = {};
    testA.set_diets(diets);
    assert(testA.get_diets() == diets);

    cout << "PASSED. \n";
}