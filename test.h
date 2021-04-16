#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "menu.h"

using namespace std;


void database_tests();
void recipe_tests();
void menu_tests();

// Database Tests
void database_dflt_constructor_test();
void database_copy_constructor_test();
void database_vector_constructor_test();
void database_file_constructor_test();

void save_file_test();
void save_to_file_test();
void add_by_name_test();
void add_by_time_test();
void seperate_list_test();
void binary_search_name_test();

// Recipe Tests
void recipe_dflt_constructor_test();
void recipe_reg_constructor_test();
void recipe_copy_constructor_test();

void get_name_test();
void get_url_test();
void get_time_test();
void get_meal_test();
void get_ingreds_test();
void get_ingred_test();
void get_num_ingreds_test();
void get_diets_test();
void get_diet_test();
void get_num_diets_test();

void set_name_test();
void set_url_test();
void set_time_test();
void set_meal_test();
void set_ingreds_test();
void set_diets_test();

void add_ingred_test();
void change_ingred_test();
void delete_ingred_test();

void add_diet_test();
void delete_diet_test();

int adjust_index(vector<recipe*> rb, int index, string key);

#endif