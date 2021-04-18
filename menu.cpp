#include <iostream>
#include <vector>
#include <cmath>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "menu.h"
#include <limits.h>

using namespace std;

    menu::menu()
    :page(home), last_page(home){
        //cout << box.get(0).get_name() << "\n";
        while(true){
           get_user_choice();
           process_choice();
        }
    }

    menu::~menu() { }

    bool menu::is_int(double d){
        if(floor(d) == ceil(d)){
            return true;
        } else {
            return false;
        }
    }

    void menu::display_choices(vector<string> choices){
        for(int i = 0; i < choices.size(); i++){
            cout << "(" << i + 1 << ") ";
            cout << choices[i] << "\n";
        }
    }

    int menu::get_valid_num_inp(int low, int high, const bool auto_prompt){
        bool valid_input = false;
        int chosen;
        
        while(!valid_input){
            if(auto_prompt)
                cout << "Enter your choice: ";
            cin >> chosen;

            if(cin.fail() || !is_int(chosen)){
                // Reference for handling incorrect data types:
                // https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer 
                // if input is not a number or is not an integer
                cout << "Incorrect input. Please try again. \n";
                cin.clear();
                cin.ignore(256, '\n');
                continue;
            }
            
            if(chosen >= low && chosen <= high){
                valid_input = true;
            }

            if(!valid_input)
                // if input is an integer but not a correct input
                cout << "Incorrect input. Please try again. \n";
        }
        return chosen;
    }

    void menu::get_user_choice(){
        double chosen;

        display_choices(page);

        if (page != home && page != quit){
            cout << "(-1) Main Menu\n";
        }

        if(page != home){
            cout << "(0) Back \n";
        }

        if (page != home){
            // if input is an int and we are not in the start menu
            chosen = get_valid_num_inp(-1, page.size(), true);
        }    
        else {
            // if input is an int and we are in the start menu
            chosen = get_valid_num_inp(0, page.size(), true);
        }
        
        user_choice = chosen;
    }

    void menu::process_choice(){
        // Reference for using switch statments for menu:
        // https://stackoverflow.com/questions/41676953/optimization-of-menu-and-submenu-in-c
        
        vector<string> temp = last_page;
        last_page = page;
        switch(user_choice){
            case -1:
                page = home;
                break;         
            case 0:
                page = temp;
                break;
        }
        
        if(page == home){
            switch(user_choice){
                case 1:
                    add_user_recipe();
                    break;
                case 2:
                    page = find_recipe;
                    break;
                case 3:
                    page = find_recipe;
                    break;
                case 4:
                    page = list_recipes;
                    break;
                case 5:
                    page = quit;
                    break;
            }
        }else if(page == find_recipe){
            switch(user_choice){
                case 1:
                    page = find_by_name;
                    break;
                case 2:
                    page = find_by_time;
                    break;
                case 3:
                    page = find_by_ingred;
                    break;
                case 4:
                    page = find_by_meal;
                    break;
                case 5:
                    page = find_by_diet;
                    break;
            }
        }else if(page == find_by_name){
            switch(user_choice){
                case 1:
                    // string n = get_string_input(); 
                    //      - this function makes sure its a string input
                    // 
                    //
                    // search_results = update_results()
                    //      - updates results with all search_results with 
                    //          matching ids
                    // set page to search result
                    // get_user_choice
                    // recipe_choice = get_user_choice
                    // page = recipe_options
                    // get_user_choice
                    box.search_recipe_name_full(recipe_results, print_results);
                    page = print_results;
                    break;
                case 2:
                    box.search_recipe_name_part(recipe_results, print_results);
                    page = print_results;
                    break;
            }
        }else if(page == find_by_time){
            switch(user_choice){
                case 1:
                    // int num = get_int_input();
                    // results_id = search_exact_time(num);
                    // search_results.clear();
                    // set_search_results();
                    // page = search_results;
                    // get_user_choice();
                    // user can select a recipe or menu or go back
                    //      - page = recipe_options; , save selected recipe id
                    //      - page = home;
                    //      - page go back
                    box.search_recipe_time_full(recipe_results, print_results);
                    page = print_results;
                    break;
                case 2:
                    // int low_num = get_lower_range();
                    //    int num = get_int_input();
                    //int high_num = get_higher_range();
                    //    int num = get_int_input();
                    //results_id = search_time_range();
                    // search_results.clear();
                    //set_search_results();
                    // page = search_results;
                    // get_user_choice();
                    box.search_recipe_time_range(recipe_results, print_results);
                    page = print_results;
                    break;
            }
        }else if(page == find_by_ingred){
            switch(user_choice){
                case 1:
                    // full ingredient
                    // must search throuvh vector
                    box.search_recipe_ingred_full(recipe_results, print_results);
                    page = print_results;
                    break;
                case 2:
                    // part ingredient
                    // must search through vector
                    box.search_recipe_ingred_part(recipe_results, print_results);
                    page = print_results;
                    break;
            }
        }else if(page == find_by_meal){
            switch(user_choice){
                case 1:
                    box.search_meal("breakfast",recipe_results, print_results);
                    page = print_results;
                    break;
                case 2:
                    box.search_meal("lunch",recipe_results, print_results);
                    page = print_results;
                    break;
                case 3:
                    box.search_meal("dinner",recipe_results, print_results);
                    page = print_results;
                    break;
                case 4:
                    box.search_meal("snack",recipe_results, print_results);
                    page = print_results;
                    break;
                case 5:
                    box.search_meal("drink",recipe_results, print_results);
                    page = print_results;
                    break;
                case 6:
                    box.search_meal("dessert",recipe_results, print_results);
                    page = print_results;
                    break;
            }
        }else if(page == find_by_diet){
            switch(user_choice){
                case 1:
                    box.search_diet("meat",recipe_results, print_results);
                    page = print_results;
                    break;
                case 2:
                    box.search_diet("vegetarian",recipe_results, print_results);
                    page = print_results;
                    break;
                case 3:
                    box.search_diet("vegan",recipe_results, print_results);
                    page = print_results;
                    break;
                case 4:
                    box.search_diet("gluten-free",recipe_results, print_results);
                    page = print_results;
                    break;
                case 5:
                    box.search_diet("low-sugar",recipe_results, print_results);
                    page = print_results;
                    break;
                case 6:
                    box.search_diet("pescatarian",recipe_results, print_results);
                    page = print_results;
                    break;
                case 7:
                    box.search_diet("dairy free",recipe_results, print_results);
                    page = print_results;
                    break;
                case 8:
                    box.search_diet("n/a",recipe_results, print_results);
                    page = print_results;
                    break;
            }
        }else if(page == list_recipes){
            switch(user_choice){
                case 1:
                    //lists name alpha
                    box.list_names_alpha(recipe_results, print_results);
                    page = print_results;
                    break;
                case 2:
                    //lists names reverse alpha
                    box.list_names_alpha_reverse(recipe_results, print_results);
                    page = print_results;
                    break;
                case 3:
                    //lists time ascending
                    box.list_times_up(recipe_results, print_results);
                    page = print_results;
                    break;
                case 4:
                    //lists time descending
                    box.list_times_down(recipe_results, print_results);
                    page = print_results;
                    break;
            }
        }else if(page == quit){
            switch(user_choice){
                case 1: 
                    box.save_to_file();
                    break;
            }
        }else if(page == print_results){
            recipe_choice = user_choice - 1;
            page = recipe_options;
        } else {
            // page == recipe_options
            switch(user_choice){
                case 1:
                    box.print_recipe(recipe_results, recipe_choice);
                    page = empty;
                    break;
                case 2:
                    int j = 0;
                    string add = reinterpret_cast<const char*>(recipe_results[recipe_choice]);
                    for (; j < box.size(); j++){
                        if (box.get_p(j) == add){
                            break;
                        }
                    }
                    box.delete_recipe(j);
                    page = home;
                    break;
            }
        }
    }

    bool is_url(string url){
        vector<string> url_endings = {".edu", ".org", ".com", ".net", ".biz", ".info", ".gov", ".ca"};
        vector<string> url_begins = {"http://", "https://"};

        bool valid_end = false;
        bool valid_begin = false;

        for(int i = 0; i < url_endings.size(); i++){
            if(url.find(url_endings[i], 0) != -1)
                valid_end = true;
        }

        for(int i = 0; i < url_begins.size(); i++){
            if(url.find(url_begins[i], 0) != -1)
                valid_begin = true;
        }

        return valid_end && valid_begin;
    }

    void to_lowercase(string &s){
        for(int i = 0; i < s.length(); i++){
            char temp = tolower(s[i]);
            s[i] = temp;
        }
    }

    void menu::add_user_recipe(){
        string name;
        string url;
        int time; 
        string meal;
        vector<string> ingreds;
        vector<string> diet;
        
        cin.clear();
        cin.ignore(256,'\n');

        cout << "Enter recipe name: ";
        // reduce to lowercase
        getline(cin, name);
        to_lowercase(name);

        bool validUrl = false;
        
        while(!validUrl){
            cout << "Copy and paste recipe url: ";
            getline(cin,url);
            
            validUrl = is_url(url);
            
            if(!validUrl){
                cout << "URL is invalid. Please try copy and paste URL exactly. \n";
            }
        }
        
        cout << "Enter the time it takes to make (in minutes): ";
        int max_int = INT_MAX;
        time = get_valid_num_inp(0, max_int, false);

        cout << "Choose which meal option it is: \n";
        display_choices(meal_options);
        int meal_index = get_valid_num_inp(1, meal_options.size() - 1, true);
        meal = meal_options.at(meal_index);
        
        cout << "Enter in the ingredients one at a time. Enter 0 to stop: \n";
        
        string ingreds_input;
        do{
            getline(cin, ingreds_input);
            if(ingreds_input != "0"){
                to_lowercase(ingreds_input);
                ingreds.push_back(ingreds_input);
            }
        }while(ingreds_input != "0");
        

        cout << "Choose which diet options apply one at a time. Enter 0 to stop: \n";
        display_choices(diet_options);
        
        int diet_input;
        
        do{
            diet_input = get_valid_num_inp(0, diet_options.size(), true) -1;
            if(diet_input != -1){
                diet.push_back(diet_options[diet_input]);
            }
        }while(diet_input != -1);

        cout << name << ", " << url << ", " << time << ", " << meal << "\n";

        //recipe temp(name, url, time, meal, ingreds, diet);
        temp.set_name(name);
        temp.set_url(url);
        temp.set_time(time);
        temp.set_meal(meal);
        temp.set_ingreds(ingreds);
        temp.set_diets(diet);

        cout << temp.get_name();

        box.add_recipe(temp);
    }
