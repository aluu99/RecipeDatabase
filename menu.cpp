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
        //cout << box.get(0).get_name() << "\n";
        while(true){
           get_user_choice();
           process_choice();
        }
    }

    // menu::menu(database* box)
    // :page(home), last_page(home), box(box){
    //     cout << box->get(0).get_name() << "\n";
    //     while(true){
    //        get_user_choice();
    //        process_choice();
    //     }
    // }

    menu::~menu() {}

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

    // int menu::get_valid_num_inp(int low, int high, bool & valid_input){
    //     int chosen;
        
    //     while(!valid_input){
    //         cout << "Enter your choice: ";
    //         cin >> chosen;

    //         if(cin.fail() || !is_int(chosen)){
    //             // Reference for handling incorrect data types:
    //             // https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer 
    //             // if input is not a number or is not an integer
    //             cout << "Incorrect input. Please try again. \n";
    //             cin.clear();
    //             cin.ignore(256, '\n');
    //             continue;
    //         }
            
    //         if(chosen >= low && chosen <= high){
    //                 valid_input = true;
    //         }

    //         if(!valid_input)
    //             // if input is an integer but not a correct input
    //             cout << "Incorrect input. Please try again. \n";
    //     }
    //     return chosen;
    // }

    void menu::get_user_choice(){
        double chosen;
        bool valid_input = false;
        display_choices(page);

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
            }
            
            if (page != home){
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
                    //int j = 0;
                    // string add = reinterpret_cast<const char*>(recipe_results[recipe_choice]);
                    // for (; j < box.size(); j++){
                    //     if (box.get_p(j) == add){
                    //         break;
                    //     }
                    // }
                    box.delete_recipe(recipe_choice);
                    page = empty;
                    break;
            }
        }
    }

    bool is_url(string url){
        vector<string> url_endings = {".edu", ".org", ".com", ".net", ".biz", ".info", ".gov"};
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

    // void menu::add_user_recipe(){
    //     recipe temp();

    //     string name;
    //     string url;
    //     int time; 
    //     string meal;
    //     vector<string> ingreds;
    //     vector<string> diet;
        
    //     cout << "Enter recipe name: ";
    //     cin >> name;
        
    //     bool validUrl = false;
        
    //     while(!validUrl){
    //         cout << "Copy and paste recipe url: ";
    //         cin >> url;
            
    //         validUrl = is_url(url);
            
    //         if(!validUrl){
    //             cout << "URL is invalid. Please try copy and paste URL exactly. \n";
    //         }
    //     }

    //     bool validTime = false;

    //         while(!validTime){
    //             cout << "Please enter time recipe (in minutes): ";
    //             cin >> time;
                
    //             if(cin.fail() || time < 0){
    //                 cout << "Time input is invalid. Please try again. \n";

    //                 cin.clear();
    //                 cin.ignore(256, '\n');
    //             }
    //         }

    //     bool validMeal = false;
    //         display_choices(meal_options);
            
    //         while(!validMeal){
                
    //         }
    // }
