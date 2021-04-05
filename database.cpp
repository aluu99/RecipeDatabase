#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include <ncurses.h>
#include <fstream>

using namespace std;
        
    int database::binary_search_name(vector<recipe> r, int low, int high, string key){
        int mid;

        if(low == high)
            return low;

        mid = low + ((high - low) / 2);

        if (key > r[mid].get_name())
            return binary_search_name(r, mid + 1, high, key);
        else if (key < r[mid].get_name())
            return binary_search_name(r, low, mid, key);
        else 
            return mid;
    }

    int database::binary_search_time(vector<recipe> r, int low, int high, int key){
        int mid;

        if(low == high)
            return low;

        mid = low + ((high - low) / 2);

        if (key > r[mid].get_time())
            return binary_search_time(r, mid + 1, high, key);
        else if (key < r[mid].get_time())
            return binary_search_time(r, low, mid, key);
        else
            return mid;
    }
        
    void database::add_by_name(const recipe r){
        int correct_i;

        correct_i = binary_search_name(recipe_box, 0, recipe_box.size(), r.get_name());
        recipe_box.insert(recipe_box.begin() + correct_i, r);
    }

    
    void database::add_by_time(const recipe r){
        int correct_i;

        correct_i = binary_search_time(recipe_box_time, 0, recipe_box_time.size(), r.get_time());
        recipe_box_time.insert(recipe_box_time.begin() + correct_i, r);
    }
    
    database::database() {}
    database::database(const database& orig)
    :recipe_box(orig.recipe_box), recipe_box_time(orig.recipe_box_time) {}
    database::database(string file_name)
    : file(file_name) {
        ifstream data(file);
        while (true){
            recipe temp;
            string input = "";
            getline(data,input);
            if (data.fail()){
                break;
            }
            temp.set_name(input);
            getline(data,input);
            if (data.fail()){
                break;
            }
            int input_int = stoi(input);
            temp.set_time(input_int);
            add_recipe(temp);
        }
    }

    database::~database() {}

    recipe database::get(int i) const{
        return recipe_box.at(i);
    }

    recipe database::get_time(int i) const{
        return recipe_box_time.at(i);
    }

    vector<search_result> database::search_recipe_name_full(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_name() == s){
                results++;
                search_results.push_back({recipe_box.at(i).get_name(),i,results});
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_name_part(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            string name = recipe_box.at(i).get_name();
            if (name.find(s) != std::string::npos){
                results++;
                search_results.push_back({recipe_box.at(i).get_name(),i,results});
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_diet_full(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> diets = recipe_box.at(i).get_diets();
            for (int j = 0; j < diets.size(); i++){
                if (diets.at(j) == s){
                    results++;
                    search_results.push_back({recipe_box.at(i).get_name(),i,results});
                    break;
                }
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_diet_part(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> diets = recipe_box.at(i).get_diets();
            for (int j = 0; j < diets.size(); i++){
                string diet = diets.at(j);
                if (diet.find(s) != std::string::npos){
                    results++;
                    search_results.push_back({recipe_box.at(i).get_name(),i,results});
                    break;
                }
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_meal_full(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> meals = recipe_box.at(i).get_meals();
            for (int j = 0; j < meals.size(); i++){
                if (meals.at(j) == s){
                    results++;
                    search_results.push_back({recipe_box.at(i).get_name(),i,results});
                    break;
                }
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_meal_part(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> meals = recipe_box.at(i).get_meals();
            for (int j = 0; j < meals.size(); i++){
                string meal = meals.at(j);
                if (meal.find(s) != std::string::npos){
                    results++;
                    search_results.push_back({recipe_box.at(i).get_name(),i,results});
                    break;
                }
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_ingred_full(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> ingreds = recipe_box.at(i).get_ingreds();
            for (int j = 0; j < ingreds.size(); i++){
                if (ingreds.at(j) == s){
                    results++;
                    search_results.push_back({recipe_box.at(i).get_name(),i,results});
                    break;
                }
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_ingred_part(string s) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> ingreds = recipe_box.at(i).get_ingreds();
            for (int j = 0; j < ingreds.size(); i++){
                string ingred = ingreds.at(j);
                if (ingred.find(s) != std::string::npos){
                    results++;
                    search_results.push_back({recipe_box.at(i).get_name(),i,results});
                    break;
                }
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_time_full(int t) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_time() == t){
                results++;
                search_results.push_back({recipe_box.at(i).get_name(),i,results});
            }
        }
        return search_results;
    }

    vector<search_result> database::search_recipe_time_range(int t_begin, int t_end) const{
        vector<search_result> search_results;
        int results = 0;
        for (int i = 0; i < recipe_box.size(); i++){
            if ((recipe_box.at(i).get_time() >= t_begin) && (recipe_box.at(i).get_time() <= t_end)){
                results++;
                search_results.push_back({recipe_box.at(i).get_name(),i,results});
            }
        }
        return search_results;
    }

    void database::add_recipe(recipe r){
        add_by_name(r);
        add_by_time(r);
    }

    void database::delete_recipe(int i){
        recipe_box.erase(recipe_box.begin() + i);
    }

    void database::edit_recipe(int i){
        cout << i;
    }

    void database::print_recipe_name(int i){
        initscr();
        clear();
        move(10,10);
        cout << recipe_box.at(i).get_name();
        refresh();
        endwin();
    }

    void database::print_recipe_whole(int i){
        cout << i;
    }

    // void database::read_file(string f){
    //     ifstream file;
    //     file.open(f);

    //     if(file.is_open()){
            

    //     } else 
    //         cmpt::error("Saved file could not open");
    // }