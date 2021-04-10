#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"

using namespace std;

void recipe_dflt_constructor_test();
void recipe_reg_constructor_test();
void recipe_copy_constructor_test();
void database_tests();
void recipe_tests();
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
void get_id_test();

#endif