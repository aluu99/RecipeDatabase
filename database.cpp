#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include <ncurses.h>
#include <fstream>
#include <regex>

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
        if (data.fail()){
            cout << "File failed to open.\n";
            return;
        }
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

        for(int i = 0; i < recipe_box.size(); i++){
            add_by_name(recipe_box[i]);
            add_by_time(recipe_box[i]);
        }
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

    database::database() {
        save_file();
    }

    database::database(const database& orig)
    :recipe_box(orig.recipe_box), rb_by_name(orig.rb_by_name), 
    rb_by_time(orig.rb_by_time), file(orig.file) 
    {}

    database::database(vector<recipe> recipes)
    :recipe_box(recipes) 
    {
        for(int i = 0; i < recipe_box.size(); i++){
            add_by_name(recipe_box[i]);
        }
        for(int i = 0; i < recipe_box.size(); i++){
            add_by_time(recipe_box[i]);
        }
    }
    
    database::database(string file_name)
    : file(file_name) {
        save_file();
    }

    database::~database() {}

    recipe database::get(int i) const{
        return recipe_box.at(i);
    }

    // string database::get_p(int i) const{
    //     string add = reinterpret_cast<const char*>(&(recipe_box.at(i)));
    //     return add;
    // }

    // int database::get_idx(recipe* r){
    //     for (int i = 0; i < recipe_box.size(); i++){
    //         if(&(recipe_box.at(i)) == r){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    
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

    void database::print_recipe(vector<recipe*>& r,int i){
        r[i]->print();
    }
    
   void database::search_recipe_name_full(vector<recipe*>& results, vector<string>& print){
        string s = "";
        results.clear();
        print.clear();
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter exact name to search: ";
        getline(cin, s);

        for (int i = 0; i < recipe_box.size(); i++){
            if (recipe_box.at(i).get_name() == s){
                results.push_back(&(recipe_box.at(i)));
                string info = recipe_box.at(i).get_name() + "   " + to_string(recipe_box.at(i).get_time()) + " minutes";
                print.push_back(info);
            }
        }
    }

    void database::search_recipe_name_part(vector<recipe*>& results, vector<string>& print){
        string s = "";
        results.clear();
        print.clear();
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Enter keyword to search: ";
        getline(cin, s);

        for (int i = 0; i < recipe_box.size(); i++){
            string name = recipe_box.at(i).get_name();
            if (name.find(s) != std::string::npos){
                results.push_back(&(recipe_box.at(i)));
                string info = recipe_box.at(i).get_name() + "   " + to_string(recipe_box.at(i).get_time()) + " minutes";
                print.push_back(info);
            }
        }
    }

    void database::search_diet(const string s, vector<recipe*>& results, vector<string>& print){
        results.clear();
        //print.clear();
        cin.clear();
        cin.ignore(256,'\n');
        
        //for (int i = 0; i < recipe_box.size(); i++){
            //for (int j = 0; j < recipe_box.at(i).get_num_diets(); i++){
                cout << s << print.at(0);
                // if (recipe_box.at(i).get_diet(j) == s){
                //     // results.push_back(&(recipe_box.at(i)));
                //     // string info = recipe_box.at(i).get_name() + "   " + to_string(recipe_box.at(i).get_time()) + " minutes";
                //     // print.push_back(info);
                //     break;
                // }
            //}
        //}
    }
/*
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

    void database::add_by_name(recipe& r){
        int binary_search_index = binary_search_name(rb_by_name, 0, rb_by_name.size(), r.get_name());
        
        recipe* to_r = &r;
        rb_by_name.insert(rb_by_name.begin() + binary_search_index, to_r);//   
     
          //cout << correct_index;
  }
    void database::add_by_time(recipe& r){
        int binary_search_index = binary_search_time(rb_by_time, 0, rb_by_time.size(), r.get_time());

        // cout << r.get_name();
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
        add_by_name(recipe_box[recipe_box.size()-1]);
        
        add_by_time(recipe_box[recipe_box.size()-1]);
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

    recipe* database::get_rb_by_name_elem(int i) const{
        return rb_by_name.at(i);
    }
    
    recipe* database::get_rb_by_time_elem(int i) const{
        return rb_by_time.at(i);
    }
    
    




