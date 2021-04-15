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
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter","chocolate chips"},
                {"vegetarian", "low-sugar"});
                
recipe test3(   " mojito",
                "https://www.allrecipes.com/recipe/277079/slurp/",
                2,
                "drink",
                {"lime", "soda", "mint", "sugar", "ice", "salt"},
                {"vegetarian", "gluten-free", "vegan", "low-sugar"}); 

recipe test4(   "nachos ",
                "https://www.allrecipes.com/recipe/chip/",
                0,
                "snack",
                {"chips", "cheese"},
                {"vegetarian"}); 

recipe test5(   "shepherd's pie",
                "https://www.allrecipes.com/recipe/277079/sweet-potato-and-venison-shepherds-pie/",
                170,
                "dinner",
                {"potato", "butter", "milk", "salt", "black pepper", "dried sage", "nutmeg", "cheese"},
                {"pescatarian"});
                
recipe test6(   "vanilla crepes",
                "https://www.allrecipes.com/recipe/95817/vanilla-crepes/",
                30,
                "breakfast",
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter"},
                {"n/a"}); 

recipe test7(   "apple pie",
                "https://www.allrecipes.com/recipe/95817/pie/",
                120,
                "dessert",
                {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter", "apples"},
                {"gluten-free"});

// recipes sorted by name in alpha order
vector<recipe> recipes = {test0, test1, test2, test3, test4, test5, test6, test7};

// // recipes sorted by time in ascending order
// vector<recipe> by_time = {test0, test4, test3, test2, test6, test1, test5};

database test_database(recipes);

void binary_search_name_test(){
    
}

/**************************TEST FUNCTIONS******************************/

// calls test functions for menu class
void menu_tests(){
   cout << "Testing menu class tests ... \n";
   menu test;
   cout << "All menu class tests passed! \n";
}

// calls test functions for database class
void database_tests(){
    cout << "Testing database class tests ... \n";
    
    database_dflt_constructor_test();
    database_copy_constructor_test();
    database_vector_constructor_test();
    seperate_list_test();
    //database_file_constructor_test();

    save_file_test();
    //binary_search_name_test();

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
    add_ingred_test();
    change_ingred_test();
    delete_ingred_test();
    add_diet_test();
    delete_diet_test();
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

void database_file_constructor_test(){
    cout << "Testing file database constructor: ";

    database test("test.txt");

    cout << "PASSED \n";
}


void database_vector_constructor_test(){
    cout << "Testing vector database constructor: ";

    database test(recipes);

    cout << "PASSED \n";
}

void database_copy_constructor_test(){
    cout << "Testing copy database constructor: ";

    database test(test_database);

    cout << "PASSED \n";
}

void save_file_test(){
    cout << "Testing save_file_test(): ";

    database test("test.txt");
    vector<string> list;
    // assert(test.testing.at(0).get_name() == "nothing");
    // assert(test.testing.at(0).get_url() == "www");
    // assert(test.testing.at(0).get_time() == 0);
    // assert(test.testing.at(0).get_meal() == "snack");
    // list = {"nope"};
    // assert(test.testing.at(0).get_ingreds() == list);
    // list = {"n/a"};
    // assert(test.testing.at(0).get_diets() == list);

    assert(test.testing.at(0).get_name() == "chicken soup");assert(test.testing.at(0).get_url() == "www.eatsoup.ca");
    assert(test.testing.at(0).get_time() == 45);
    assert(test.testing.at(0).get_meal() == "lunch");
    list = {"chicken", "broth", "celery", "carrots"};
    assert(test.testing.at(0).get_ingreds() == list);
    list = {"meat", "dairy free"};
    assert(test.testing.at(0).get_diets() == list);

    assert(test.testing.at(1).get_name() == "chocolate chip cookies");
    assert(test.testing.at(1).get_url() == "https://www.allrecipes.com/recipe/277079/cookies/");
    assert(test.testing.at(1).get_time() == 20);
    assert(test.testing.at(1).get_meal() == "dessert");
    list = {"milk", "egg yolks", "vanilla extract", "flour", "sugar", "salt", "butter","chocolate chips"};
    assert(test.testing.at(1).get_ingreds() == list);
    list = {"vegetarian", "low-sugar"};
    assert(test.testing.at(1).get_diets() == list);

    cout << "PASSED\n";
}

vector<string> eperate_list(const string& list){
        char next_item = ',';
        string item = "";
        vector<string> items;
        for (int i = 0; i < list.size(); i++){
            if (list.at(i) == next_item){
                i++;
                items.push_back(item);
                item = "";
                continue;
            }
            item += list.at(i);
            if (i == list.size() - 1){
                items.push_back(item);
            }
        }
        return items;
    }

void seperate_list_test(){
    string test = "apple, banana, cucumber";
    vector<string> expected = {"apple", "banana", "cucumber"};

    assert(eperate_list(test) == expected);
}

void add_by_name_test(){
    
}

void add_by_time_test(){

}

/****************************RECIPE TEST FUNCTIONS****************************/

// CONSTRUCTOR TESTS
void recipe_dflt_constructor_test(){
    cout << "Testing default recipe constructor: ";

    recipe test(); 

    cout <<  "PASSED\n";
}

void recipe_reg_constructor_test(){
    cout << "Testing regular recipe constructor: ";

    recipe test("name", "url", 0, "meal", {"ingred 1", "ingred 2"}, {"diet 1", "diet 2"});

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

// OTHER METHOD TESTS

void add_ingred_test(){
    cout << "Testing add_ingred_test(): ";
    
    recipe test(test0);
    test.add_ingred("apple");
    assert(test.get_ingred(test.get_num_ingreds()-1) == "apple");
    test.add_ingred(" b a n a n a ");
    assert(test.get_ingred(test.get_num_ingreds()-1) == " b a n a n a ");
    test.add_ingred(" ");
    assert(test.get_ingred(test.get_num_ingreds()-1) == " ");
    test.add_ingred("123-456!");
    assert(test.get_ingred(test.get_num_ingreds()-1) == "123-456!");

    cout << "PASSED. \n";
}

void change_ingred_test(){
    cout << "Testing change_ingred_test(): ";

    recipe test(test2);
    test.change_ingred(0,"apple");
    assert(test.get_ingred(0) == "apple");
    test.change_ingred(1," b a n a n a ");
    assert(test.get_ingred(1) == " b a n a n a ");
    test.change_ingred(2," b a na n a ");
    assert(test.get_ingred(2) == " b a na n a ");
    test.change_ingred(3,"avocado rind");
    assert(test.get_ingred(3) == "avocado rind");
    test.change_ingred(4,"lemon");
    assert(test.get_ingred(4) == "lemon");
    test.change_ingred(5," chicken");
    assert(test.get_ingred(5) == " chicken");
    test.change_ingred(6," seeded watermelon ");
    assert(test.get_ingred(6) == " seeded watermelon ");
    test.change_ingred(7,"5 beets");
    assert(test.get_ingred(7) == "5 beets");

    cout << "PASSED. \n";
}

void delete_ingred_test(){
    cout << "Testing delete_ingred_test(): ";
    
    recipe test(test2);
    test.delete_ingred(test.get_num_ingreds());
    assert((test.get_num_ingreds() + 1) == test2.get_num_ingreds());
    test.delete_ingred(0);
    assert((test.get_num_ingreds() + 2) == test2.get_num_ingreds());
    assert(test.get_ingred(0) == test2.get_ingred(1));
    assert(test.get_ingred(1) == test2.get_ingred(2));
    assert(test.get_ingred(2) == test2.get_ingred(3));
    assert(test.get_ingred(3) == test2.get_ingred(4));
    assert(test.get_ingred(4) == test2.get_ingred(5));
    assert(test.get_ingred(5) == test2.get_ingred(6));

    cout << "PASSED. \n";
}

void add_diet_test(){
    cout << "Testing add_diet_test(): ";

    recipe test(test1);
    test.add_diet("meat");
    assert(test.get_diet(test.get_num_diets()-1) == "meat");
    test.add_diet("vegetarian");
    assert(test.get_diet(test.get_num_diets()-1) == "vegetarian");
    test.add_diet("vegetarian");
    assert(test.get_diet(test.get_num_diets()-1) == "vegetarian");
    test.add_diet("vegan");
    assert(test.get_diet(test.get_num_diets()-1) == "vegan");
    test.add_diet("gluten-free");
    assert(test.get_diet(test.get_num_diets()-1) == "gluten-free");
    test.add_diet("low-sugar");
    assert(test.get_diet(test.get_num_diets()-1) == "low-sugar");
    test.add_diet("pescatarian");
    assert(test.get_diet(test.get_num_diets()-1) == "pescatarian");
    test.add_diet("dairy free");
    assert(test.get_diet(test.get_num_diets()-1) == "dairy free");
    test.add_diet("n/a");
    assert(test.get_diet(test.get_num_diets()-1) == "n/a");
    assert(test.get_num_diets() == 1);

    cout << "PASSED. \n";
}

void delete_diet_test(){
    cout << "Testing delete_diet_test(): ";

    recipe test(test3);
    test.delete_diet(test.get_num_diets());
    assert(test.get_num_diets() + 1 == test3.get_num_diets());
    test.delete_diet(0);
    assert(test.get_num_diets() + 2 == test3.get_num_diets());
    assert(test.get_diet(0) == test3.get_diet(1));
    assert(test.get_diet(1) == test3.get_diet(2));

    cout << "PASSED. \n";
}