#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include <ncurses.h>
#include <fstream>

using namespace std;

/*
    int database::binary_search_name(vector<recipe> const r, int low, int high, string key){
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
    */
    vector<string> seperate_list(const string& list){
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

    void database::save_file(){
        ifstream data(file);
        int field = 0;
        recipe temp;

        while (true){
            string input = "";
            getline(data,input);
            if (data.fail()){
                break;
            }
            if (field == 0){
                //Name
                temp.set_name(input);
            }else if (field == 1){
                //URL
                temp.set_url(input);
            } else if (field == 2){
                //Time
                int input_int = stoi(input);
                temp.set_time(input_int);
            }else if (field == 3){
                //Meal
                temp.set_meal(input);
            }else if (field == 4){
                //Ingredients
                vector<string> list = seperate_list(input);
                temp.set_ingreds(list);
            } else {
                // Diet
                vector<string> list = seperate_list(input);
                temp.set_diets(list);
                add_recipe(temp);
                field = 0;
                continue;
            }
            field++;            
        }
        data.close();
    }

    string database::vector_to_string(const vector<string> list){
        string info = "";
        for (int i = 0; i < list.size(); i++){
            info += list.at(i);
            if (i != (list.size() - 1)){
                info += ", ";
            }
        }
        return info;
    }

    void database::save_to_file(){
        cout << "Saving file to: " << file << "\n";

        ofstream data(file);
        for (int i = 0; i < recipe_box.size(); i++){
            data << recipe_box.at(i).get_name() << "\n";
            data << recipe_box.at(i).get_url() << "\n";
            string str_time = to_string(recipe_box.at(i).get_time());
            data << str_time << "\n";
            data << recipe_box.at(i).get_meal() << "\n";
            string str_vector = vector_to_string(recipe_box.at(i).get_ingreds());
            data << str_vector << "\n";
            str_vector = vector_to_string(recipe_box.at(i).get_diets());
            data << str_vector << "\n";
        }

        cout << "File saved! Happy cooking!\n";
        data.close();
    }

    int database::binary_search_time(vector<recipe_time> r, int low, int high, int key){
        int mid;

        if(low == high)
            return low;

        mid = low + ((high - low) / 2);

        if (key > r[mid].time)
            return binary_search_time(r, mid + 1, high, key);
        else if (key < r[mid].time)
            return binary_search_time(r, low, mid, key);
        else
            return mid;
    }
/*
    void database::add_by_name(const recipe r){
        int correct_i;
        
        correct_i = binary_search_name(recipe_box, 0, recipe_box.size(), r.get_name());
        //recipe_box.insert(recipe_box.begin() + correct_i, r);
    }

    
    void database::add_by_time(const recipe r){
        int correct_i;
        recipe_time temp;
        //int time = ;
        int id = r.get_id();
        temp.time = r.get_time();
        temp.id = id;
        correct_i = binary_search_time(recipe_box_time, 0, recipe_box_time.size(), temp.time);
        recipe_box_time.insert(recipe_box_time.begin() + correct_i, temp); //TODO: ensure working correctly
    }
  */  
    database::database() {}

    database::database(const database& orig)
    :recipe_box(orig.recipe_box), rb_by_name(orig.rb_by_name), 
    rb_by_time(orig.rb_by_time), file(orig.file) 
    {}

    database::database(vector<recipe> recipes)
    :recipe_box(recipes) 
    {}
    
    database::database(string file_name)
    : file(file_name) {
        save_file();
    }

   

    database::~database() {}

    recipe database::get(int i) const{
        return recipe_box.at(i);
    }
/*
    recipe database::get_from_time(int i) const{
        int j;
        for (j = 0; j < recipe_box.size(); j++){
            if (recipe_box_time[i].id == recipe_box.at(j).get_id()){
                break;
            }
            if (j >= recipe_box.size()){
                cmpt::error("Error: This recipe does exist in your box.");
            }
        }
        
        return recipe_box.at(j);
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



    void database::delete_recipe(int i){
        //recipe_box.erase(recipe_box.begin() + i);
        for (int j = 0; j < recipe_box_time.size(); j++){
            if (recipe_box_time.at(j).id == recipe_box[i].get_id()){
                recipe_box_time.erase(recipe_box_time.begin() + j);
            }
        }
    }

    void database::edit_recipe(int i){
        // TODO!!!!
        
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

        void database::add_recipe(recipe r){
        // in menu id must be set to some random thing
        r.set_id(id_total);
        add_by_name(r);
        add_by_time(r);
        id_total++;
    }
   */



    // void binary_insert_name(recipe r){
    //     int index;
        
        
    // }

    // void database::add_by_name(recipe r){
    //     cout <<r;
    //     //binary_insert_name(rb_by_name, r);
    // }
/*
    void database::add_by_time(recipe r){
        
    }
*/
    
    // adjusts the index for binary search to return where it actually needs to be inserted
    int adjust_index(vector<recipe*> rb, int index, string key){
        int true_index = index;

        // if the name at the found index matches key, adjust for repeats
        if(rb[index]->get_name() == key){
            while(rb[++index]->get_name() == key){
                index++;
            }
        // if the name at the found index does not match key, move it back one space
        }else{
            true_index--;
        }

        return true_index;
    }

    // TWO CASES:
    // Either a name that doesn't exist is passed through.
    //      Index returned will be one greater than it needs to be
    // A name that does exist is passed through
    //      if name doesn't exist more than once it will be the correct index
    //      if name does exist more than once, it will be in the middle
    int binary_search_name(vector<recipe*> rb, int low, int high, string key){
        int mid;
        
        if(low == high)
            return low;

        mid = low + ((high - low) / 2);

        if (key < rb[mid]->get_name())
            return binary_search_name(rb, low, mid, key);

        else if (key > rb[mid]->get_name())
            return binary_search_name(rb, mid + 1, high, key);

        else 
            return mid;
    }

    void database::add_recipe(recipe r){
        recipe_box.push_back(r);
    }

    vector<recipe> database::get_recipe_box() const{
        return recipe_box;
    }

    vector<recipe*> database::get_rb_by_name() const{
        return rb_by_name;
    }
    
    vector<recipe*> database::get_rb_by_time() const{
        return rb_by_time;
    }