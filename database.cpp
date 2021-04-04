#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include <fstream>

using namespace std;

    database::database() {}
    database::database(const database& orig)
    :recipe_box(orig.recipe_box), recipe_box_time_sorted(orig.recipe_box_time_sorted) {}
    database::database(string file_name)
    : file(file_name) {
        int field = 0;
        ifstream data(file);
        while (true){
            recipe temp;
            if(field == 0){
                string input_nm = "";
                data >> input_nm;
                if (data.fail()){
                    break;
                }
                temp.set_name(input_nm);
                field++;
            } else {
                int input_t;
                data >> input_t;
                if (data.fail()){
                    break;
                }
                temp.set_time(input_t);
                field = 0;
            }
            recipe_box.push_back(temp);
        }
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
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            string name = recipe_box.at(i).get_name();
            if (name.find(s) != std::string::npos){
                results++;
                search_results.push_back({recipe_box.at(i).get_name(),i,results});
            }
        }
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