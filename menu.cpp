#include <iostream>
#include <vector>
#include <cmath>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "menu.h"

using namespace std;

    menu::menu()
    :page(home), last_page(home){
        while(true){
           get_user_choice();
           process_choice();
        }
    }

    menu::~menu() {}

    bool menu::is_int(double d){
        if(floor(d) == ceil(d)){
            return true;
        } else {
            return false;
        }
    }

    void menu::get_user_choice(){
        double chosen;
        bool valid_input = false;
        for(int i = 0; i < page.size(); i++){
            cout << "(" << i + 1 << ") ";
            cout << page[i] << "\n";
        }
        if (page != home || page != quit){
            cout << "(0) Main Menu\n";
        }
        cout << "(-1) Back\n";

        while(!valid_input){
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
            } else if (page != home){
                // if input is an int and we are not in the start menu
                if(((chosen >= 1) && (chosen <= page.size())) || chosen == 0 || chosen == -1){
                    valid_input = true;
                }    
            } else {
                // if input is an int and we are in the start menu
                if(((chosen >= 1) && (chosen <= page.size())) || chosen == -1){
                    valid_input = true;
                }
            }

            if(!valid_input)
                // if input is an integer but not a correct input
                cout << "Incorrect input. Please try again. \n";
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
                page = temp;
                break;         
            case 0:
                page = home;
                break;
        }
        
        if(page == home){
            switch(user_choice){
                case 1:
                    // add_recipe(); TO-DO!!!!
                    break;
                case 2:
                    page = find_recipe;
                    break;
                case 3:
                    page = list_recipes;
                    break;
                case 4:
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
                    break;
                case 2:
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
                    break;
            }
        }else if(page == find_by_ingred){
            switch(user_choice){
                case 1:
                    // full ingredient
                    // must search throuvh vector
                    break;
                case 2:
                    // part ingredient
                    // must search through vector
                    break;
            }
        }else if(page == find_by_meal){
            switch(user_choice){
                case 1:
                    //lists brakfasts
                    break;
                case 2:
                    //lists lunches
                    break;
                case 3:
                    //lists dinners
                    break;
                case 4:
                    //lists snacks
                    break;
                case 5:
                    //lists drink
                    break;
                case 6:
                    //lists dessert
                    break;
            }
        }else if(page == find_by_diet){
            switch(user_choice){
                case 1:
                    //lists meat
                    break;
                case 2:
                    //lists vegetarian
                    break;
                case 3:
                    //lists vegan
                    break;
                case 4:
                    //lists gluten-free
                    break;
                case 5:
                    //lists low-sugar
                    break;
                case 6:
                    //lists pescatarian
                    break;
            }
        }else if(page == list_recipes){
            switch(user_choice){
                case 1:
                    //lists name alpha
                    break;
                case 2:
                    //lists names reverse alpha
                    break;
                case 3:
                    //lists time ascending
                    break;
                case 4:
                    //lists time descending
                    break;
            }
        }else if(page == quit){
            switch(user_choice){
                case 1: 
                    // quit_save(); TO-DO!!!!
                    break;
            }
        }else{
            switch(user_choice){
                case 1:
                    // print recipe 
                    break;
                case 2:
                    //edit recipe
                    break;
                case 3:
                    //delete recipe
                    break;
            }
        }
    }