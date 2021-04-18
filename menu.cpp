#include <iostream>
#include <vector>
#include <cmath>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "menu.h"
#include <limits.h>

using namespace std;
    /***************************CON/DE-STRUCTORS***************************/

    // Default constructor
    menu::menu()
    :page(home), last_page(home){
        while(true){
           get_user_choice();
           process_choice();
        }
    }

    // Destructor
    menu::~menu() { }

    /********************************METHODS******************************/

    // Prints out numbered list of choices
    void menu::display_choices(vector<string> choices){
        for(int i = 0; i < choices.size(); i++){
            cout << "(" << i + 1 << ") ";
            cout << choices[i] << "\n";
        }
        cout << "\n";
    }

    // Provides user with choices, gets valid user input, and stores choice
    // in user_choice variable
    void menu::get_user_choice(){
        double chosen;

        display_title();
        display_choices(page);

        if (page != home && page != quit){
            cout << "(-1) Main Menu\n";
        }
                                                

        cout << "(0) Back \n";

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

    // Prints new page for the user based on user_choice variable
    void menu::process_choice(){
        // Reference for using switch statments for menu:
        // https://stackoverflow.com/questions/41676953/optimization-of-menu-and-submenu-in-c
        
        divide_pages();

        // Saves last_page to temp and updates it to the new page
        vector<string> temp = last_page;
        last_page = page;

        switch(user_choice){
            // Back to Home
            case -1: 
                page = home;
                break;         
            // Back to Last Page
            case 0:
                page = temp;
                break;
        }
        
        if(page == find_recipe){  
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
            print_title("Find By Name");

            switch(user_choice){
                case 1:
                {
                    string s = get_string_inp("Enter exact name to search: ");
                    box.search_recipe_name_full(s, recipe_results, print_results);
                    page = print_results;
                    break;
                }
                case 2:
                {
                    string s = get_string_inp("Enter name keyword to search: ");
                    box.search_recipe_name_part(s, recipe_results, print_results);
                    page = print_results;
                    break;
                }
            }
        }else if(page == find_by_time){
            switch(user_choice){
                case 1:
                {
                    cout << "Enter the exact time in minutes: ";
                    int t = get_valid_num_inp(0, INT_MAX, false);
                    box.search_recipe_time_full(t, recipe_results, print_results);
                    page = print_results;
                    break;
                }
                case 2:
                {
                    cout << "Enter lower time range to search: ";
                    int t1 = get_valid_num_inp(1, INT_MAX,false);
                    cout << "Enter upper time range to search: ";
                    int t2 = get_valid_num_inp(t1, INT_MAX,false);
                    box.search_recipe_time_range(t1,t2,recipe_results, print_results);
                    page = print_results;
                    break;
                }
            }
        }else if(page == find_by_ingred){
            switch(user_choice){
                case 1:
                    {// full ingredient
                    // must search throuvh vector
                    string s = get_string_inp("Enter exact ingredient to search: ");
                    box.search_recipe_ingred_full(s, recipe_results, print_results);
                    page = print_results;
                    break;
                    }
                case 2:
                    {// part ingredient
                    // must search through vector
                    string s = get_string_inp("Enter ingredient keyword to search: ");
                    box.search_recipe_ingred_part(s, recipe_results, print_results);
                    page = print_results;
                    break;
                    }
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
                    page == empty;
                    exit(EXIT_SUCCESS);
                    break;
            }
        }else if(page == print_results){
            recipe_choice = user_choice - 1;
            page = recipe_options;
        } else if(page == recipe_options){
            switch(user_choice){
                case 1:
                    box.print_recipe(recipe_results, recipe_choice);
                    page = empty;
                    break;
                case 2:
                    page = confirm_deletion;
                    break;
            }
        } else if (page == confirm_deletion){
            switch(user_choice){
                case 1:
                   {int j = 0;
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
                case 2:
                    page = recipe_options;
                    break;
            }
        } 
        else{
            // page == home
            switch(user_choice){
                // Add a Recipe
                case 1:
                    add_user_recipe();
                    break;
                // Delete a Recipe
                case 2:
                    page = find_recipe;
                    break;
                // Find_recipe
                case 3:
                    page = find_recipe;
                    break;
                // List_recipe
                case 4:
                    page = list_recipes;
                    break;
                // Quit 
                case 5:
                    page = quit;
                    break;
            }
        }
    }

    // Adds a recipe to database using user input. Checks for valid input.O
    void menu::add_user_recipe(){
        cin.clear();
        cin.ignore(256,'\n');

        // GET USER RECIPE NAME
        string name;

        cout << "Enter recipe name: ";

        getline(cin, name);
        to_lowercase(name);

        // GET USER RECIPE URL
        string url;
        bool validUrl = false;
        
        while(!validUrl){
            cout << "Copy and paste recipe url: ";

            getline(cin,url);
            validUrl = is_url(url);

            if(!validUrl){
                cout << "URL is invalid. Please try copy and paste URL exactly. \n";
            }
        }

        // GET USER RECIPE TIME
        int time; 

        cout << "Enter the time it takes to make (in minutes): ";

        int max_int = INT_MAX;
        time = get_valid_num_inp(0, max_int, false);

        // GET USER MEAL TIME
        string meal;

        cout << "Choose which meal option it is: \n";

        display_choices(meal_options);
        int meal_index = get_valid_num_inp(1, meal_options.size() - 1, true);
        meal = meal_options.at(meal_index);
        cout << '\n';

        // GET USER INGREDIENTS
        vector<string> ingreds;
        string ingreds_input;

        cout << "Enter in the ingredients one at a time. Enter 0 to stop: \n";
        do{
            getline(cin, ingreds_input);
            if(ingreds_input != "0"){
                to_lowercase(ingreds_input);
                ingreds.push_back(ingreds_input);
            }
        }while(ingreds_input != "0");
        cout << '\n';

        // GET USER DIET
        vector<string> diet;
        cout << "Choose which diet options apply one at a time. Enter 0 to stop: \n";
        display_choices(diet_options);
        
        int diet_input;

        do{
            diet_input = get_valid_num_inp(0, diet_options.size(), true) -1;
            if(diet_input != -1){
                diet.push_back(diet_options[diet_input]);
            }
        }while(diet_input != -1);

        // CREATE RECIPE
        recipe temp(name,url,time,meal,ingreds,diet);

        // CHECK FOR DUPLICATES
        if(box.not_duplicate(temp)){
            box.add_recipe(temp);
            divide_pages();
        }else{
            cout << "This recipe already exists. Please try again.\n";
        }
    }

    // Prompts user to enter number. Checks if number is an int and is low
    // or high. 
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
                cin.ignore(256,'\n');
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

    // Prompts user to enter input and returns valid string
    string menu::get_string_inp(string prompt){
        string s;
        cout << prompt;
        
        cin.clear();
        cin.ignore(256, '\n');

        getline(cin, s);
        to_lowercase(s);

        return s;
    }

    void menu::to_lowercase(string &s){
        for(int i = 0; i < s.length(); i++){
            char temp = tolower(s[i]);
            s[i] = temp;
        }
    }

    bool menu::is_int(double d){
        if(floor(d) == ceil(d)){
            return true;
        } else {
            return false;
        }
    }

    bool menu::is_url(string url){
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

    // Adds end line spaces
    void menu:: divide_pages(){
        int num_of_spaces = 15;

        for(int i = 0; i < num_of_spaces; i++)
            cout << '\n'; 
    }

    // Displays the title of the recipe
    void menu:: display_title(){
        if(page == home){
            print_title("Home Page");
            
        }else if(page == find_recipe){
            print_title("Find Recipe");
            
        }else if(page == find_by_name){
            print_title("Find By Name");
            
        }else if(page == find_by_time){
            print_title("Find By Time");        
        
        }else if(page == find_by_ingred){
            print_title("Find By Ingredients");

        }else if(page == find_by_meal){
            print_title("Find By Meal Type");

        }else if(page == find_by_diet){
            print_title("Find By Diet Type");
            
        }else if(page == list_recipes){
            print_title("List Recipes");

        }else if(page == quit){
            print_title("Quit");
        }
    }

    // Prints the recipe title 
    void menu:: print_title(string page_title){
        cout << page_title << "\n";
        cout << "------------------------------------------\n";
    }


