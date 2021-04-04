#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"

using namespace std;

    database::database() {}
    database::database(const database& orig)
    :recipe_box(orig.recipe_box), recipe_box_time_sorted(orig.recipe_box_time_sorted) {}
    database::database(string file){

    }

    database::~database() {}

    int database::get_recipe_name_full(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_name() == s){
                results++;
                search_results.push_back({recipe_box.at(i).get_name(),i,results});
            }
        }
    }

    int database::get_recipe_name_part(string s) const{

    }

    int database::get_recipe_diet_full(string s) const{

    }

    int database::get_recipe_diet_part(string s) const{

    }

    int database::get_recipe_meal_full(string s) const{

    }

    int database::get_recipe_meal_part(string s) const{

    }

    int database::get_recipe_ingred_full(string s) const{

    }

    int database::get_recipe_ingred_part(string s) const{

    }

    int database::get_recipe_time_full(int t) const{

    }

    int database::get_recipe_time_range(int t_begin, int t_end) const{

    }

    void database::add_recipe(){

    }

    void database::delete_recipe(){

    }

    void database::edit_recipe(){

    }

    void database::print_recipe_name(){

    }

    void database::print_recipe_whole(){
        
    }