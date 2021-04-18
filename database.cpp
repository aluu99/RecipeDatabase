#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include <ncurses.h>
#include <fstream>
#include <regex>
#include <climits>
#include <cmath>

using namespace std;

    // Open file upon opening of a database and input the file recipes
    void database::save_file(){
        ifstream data(file);
        if (data.fail()){
            cout << "File failed to open.\n";
            return;
        }

        // Add the appropriate field to a temp recipe
        // When filled, push back and reset temp
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
                recipe_box.push_back(temp);
                field = 0;
                continue;
            }
            field++;            
        }
        data.close();

        // Add recipes to vectors in alphabetical order and time order
        for(int i = 0; i < recipe_box.size(); i++){
            add_by_name(recipe_box[i]);
            add_by_time(recipe_box[i]);
        }
    }



/***************************CON/DE-STRUCTORS***************************/

    // Default constructor
    database::database() {
        save_file();
    }

    // Copy constructor
    database::database(const database& orig)
    :recipe_box(orig.recipe_box), rb_by_name(orig.rb_by_name), 
    rb_by_time(orig.rb_by_time), file(orig.file) 
    {}

    // Constructor with recipe vector
    database::database(vector<recipe> recipes)
    :recipe_box(recipes) 
    {
        // Save recipe pointers alphabetically and by time
        for(int i = 0; i < recipe_box.size(); i++){
            add_by_name(recipe_box[i]);
        }
        for(int i = 0; i < recipe_box.size(); i++){
            add_by_time(recipe_box[i]);
        }
    }
    
    // Constructor with recipe file
    database::database(string file_name)
    : file(file_name) {
        save_file();
    }

    // Destructor
    database::~database() {}
    
    // When quitting, save all recipes to the database file
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

    recipe database::get(int i) const{
        return recipe_box.at(i);
    }

    string database::get_p(int i) const{
        string add = reinterpret_cast<const char*>(&(recipe_box.at(i)));
        return add;
    }
    
    template<typename T>
    int linear_search(const vector<T>& v, const T key){
        int i = 0;
        for (i = 0; i < v.size(); i++){
            if (v[i] == key){
                return i;
            }
        }
        return -1;
    }

    void database::delete_recipe(int i){
        
        recipe* r = &(recipe_box.at(i));
        int idx = linear_search(rb_by_name, r);
        recipe_box.erase(recipe_box.begin() + i);
        if (idx == -1){
            cout << "Recipe cannot be deleted because it has no address.\n";
            return;
        }
        rb_by_name.erase(rb_by_name.begin()+idx);
        idx = linear_search(rb_by_time, r);
        if (idx == -1){
            cout << "Recipe cannot be deleted because it has no address.\n";
            return;
        }
        rb_by_time.erase(rb_by_time.begin()+idx);
    }

    int database::size() const{
        return recipe_box.size();
    }

    void database::print_recipe(vector<const recipe*>& r,int i){
        r[i]->print();
    }

    void database::prep_results(vector<const recipe*>& results, vector<string>& print){
        results.clear();
        print.clear();
    }

   void database::search_recipe_name_full(const string s,
                vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);
        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_name() == s){
                results.push_back(&(recipe_box.at(i)));
                string info = recipe_box.at(i).get_name() + "   "
                    + to_string(recipe_box.at(i).get_time()) + " minutes";
                print.push_back(info);
            }
        }
    }

    void database::search_recipe_name_part(const string s,
            vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);
        for (int i = 0; i < recipe_box.size(); i++){
            string name = recipe_box.at(i).get_name();
            if (name.find(s) != std::string::npos){
                results.push_back(&(recipe_box.at(i)));
                string info = recipe_box.at(i).get_name() + "   "
                    + to_string(recipe_box.at(i).get_time()) + " minutes";
                print.push_back(info);
            }
        }
    }

    void database::search_diet(const string s,
            vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);
        cin.clear();
        cin.ignore(256,'\n');
        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> diets = recipe_box.at(i).get_diets();
            for (int j = 0; j < diets.size(); j++){
                if (diets.at(j) == s){
                    results.push_back(&(recipe_box.at(i)));
                    string info = recipe_box.at(i).get_name() + "   "
                        + to_string(recipe_box.at(i).get_time()) + " minutes";
                    print.push_back(info);
                    break;
                }
            }
        }
    }

    void database::search_meal(const string s,
            vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);
        cin.clear();
        cin.ignore(256,'\n');
        
        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_meal() == s){
                    results.push_back(&(recipe_box.at(i)));
                    string info = recipe_box.at(i).get_name() + "   "
                        + to_string(recipe_box.at(i).get_time()) + " minutes";
                    print.push_back(info);
                    break;
            }
        }
    }

    void database::search_recipe_ingred_full(const string s,
            vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);

        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> ingreds = recipe_box.at(i).get_ingreds();
            for (int j = 0; j < ingreds.size(); j++){
                if (ingreds.at(j) == s){
                    //results.push_back(&(recipe_box.at(i)));
                    string info = recipe_box.at(i).get_name() + "   "
                        + to_string(recipe_box.at(i).get_time()) + " minutes";
                    print.push_back(info);
                    break;
                }
            }
        }
    }

    void database::search_recipe_ingred_part(const string s,
            vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);

        for (int i = 0; i < recipe_box.size(); i++){
            vector<string> ingreds = recipe_box.at(i).get_ingreds();
            for (int j = 0; j < ingreds.size(); j++){
                string ingred = recipe_box.at(i).get_ingred(j);
                if (ingred.find(s) != std::string::npos){
                    //results.push_back(&(recipe_box.at(i)));
                    string info = recipe_box.at(i).get_name() + "   "
                        + to_string(recipe_box.at(i).get_time()) + " minutes";
                    print.push_back(info);
                }
            }
        }
    }

    void database::search_recipe_time_full(const int t,
            vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);

        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_time() == t){
                const recipe* r = &recipe_box.at(i);
                results.push_back(r);
                string info = recipe_box.at(i).get_name() + "   "
                    + to_string(recipe_box.at(i).get_time()) + " minutes";
                print.push_back(info);
            }
        }
    }

    void database::search_recipe_time_range(const int t1, const int t2,
            vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);

        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_time() >= t1 && recipe_box.at(i).get_time() <= t2){
                const recipe* r = &recipe_box.at(i);
               results.push_back(r);
                string info = recipe_box.at(i).get_name() + "   "
                    + to_string(recipe_box.at(i).get_time()) + " minutes";
                print.push_back(info);
            }
        }
    }

    void database::list_names_alpha(vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);
        for (int i = 0; i < rb_by_name.size(); i++){
            results.push_back(rb_by_name[i]);
            string name = rb_by_name[i]->get_name();
            int t = rb_by_name[i]->get_time();
            string time = to_string(t);
            string info =  name + "   " + time + " minutes";
            print.push_back(info);
        }
    }

    void database::list_names_alpha_reverse(vector<const recipe*>& results, vector<string>& print){
        list_names_alpha(results, print);
        reverse(results.begin(), results.end());
        reverse(print.begin(), print.end());
    }

    void database::list_times_up(vector<const recipe*>& results, vector<string>& print){
        prep_results(results,print);
        for (int i = 0; i < rb_by_time.size(); i++){
            results.push_back(rb_by_time[i]);
            string info = rb_by_time[i]->get_name() + "   "
                + to_string(rb_by_time[i]->get_time()) + " minutes";
            print.push_back(info);
        }
    }

    void database::list_times_down(vector<const recipe*>& results, vector<string>& print){
        list_times_up(results, print);
        reverse(results.begin(), results.end());
        reverse(print.begin(), print.end());
    }

    void database::add_by_name(recipe& r){
        int binary_search_index = binary_search_name(rb_by_name, 0, rb_by_name.size(), r.get_name());
        
        recipe* to_r = &r;
        rb_by_name.insert(rb_by_name.begin() + binary_search_index, to_r);
    }

    void database::add_by_time(recipe& r){
        int binary_search_index =
            binary_search_time(rb_by_time, 0, rb_by_time.size(), r.get_time());

        recipe* to_r = &r;        
        rb_by_time.insert(rb_by_time.begin() + binary_search_index, to_r);
    }
 
    int binary_search_time(vector<recipe*> rb, int low, int high, int key){
        int mid;
        
        if(low == high)
            return low;

        mid = low + ((high - low) / 2);

        if (key < rb[mid]->get_time())
            return binary_search_time(rb, low, mid, key);

        else if (key > rb[mid]->get_time())
            return binary_search_time(rb, mid + 1, high, key);

        else 
            return mid;
    } 

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
        rb_by_time.clear();
        for(int i = 0; i < recipe_box.size(); i++){
            add_by_time(recipe_box[i]);
        }

        rb_by_name.clear();
        for(int i = 0; i < recipe_box.size(); i++){
            add_by_name(recipe_box[i]);
        }
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

    void database::clear_rb_by_name(){
        rb_by_name.clear();
    }

    recipe* database::get_rb_by_name_elem(int i) const{
        return rb_by_name.at(i);
    }
    
    recipe* database::get_rb_by_time_elem(int i) const{
        return rb_by_time.at(i);
    }
    
    bool database::not_duplicate(recipe r){
        bool result = true;
        for(int i = 0; i < recipe_box.size(); i++){
            if(existing_url(r.get_url())){
                result = false;
            }
        }

        return result;
    }

    bool database::existing_url(string url){        
        bool existing = false;
        
        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_url() == url){
                existing = true;
            }
        }
        return existing;
    }
    
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
    
    string vector_to_string(const vector<string> list){
        string info = "";
        for (int i = 0; i < list.size(); i++){
            info += list.at(i);
            if (i != (list.size() - 1)){
                info += ", ";
            }
        }
        return info;
    }

