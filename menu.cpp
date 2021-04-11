#include <iostream>
#include <vector>
#include "cmpt_error.h"
#include "database.h"
#include "recipe.h"
#include "menu.h"

using namespace std;

    menu::menu() {
        //while(true){
           p.options = home.options;
           p.slct_start = home.slct_start;
           last_p.options = home.options;
           last_p.slct_start = home.slct_start;
           get_user_choice();
            //process_choice();
        //}
    }

    menu::~menu() {}

    void menu::get_user_choice(){
        int chosen;
        bool valid_input = false;
        for(int i = 0; i < p.options.size(); i++){
            cout << p.options[i] << "\n";
        }
        if (p.slct_start != 0){
            cout << "(0) Main Menu\n";
            cout << "(-1) Back\n";
        }

        while(!valid_input){
            cout << "Enter your choice: ";
            cin >> chosen;
            if(p.slct_start != 0){
                if(((chosen >= 1) && (chosen <= p.options.size())) || chosen == 0 || chosen == -1){
                    valid_input = true;
                }    
            } else {
                if((chosen >= 1) && (chosen <= p.options.size())){
                    valid_input = true;
                }
            }

            if(!valid_input)
                cout << "Incorrect input. Please try again. \n";
        }
        
        if(chosen == 0 || chosen == -1){
            user_choice = chosen;
        } else{
            user_choice = chosen + p.slct_start;
        }

        cout << user_choice;
    }

    void menu::process_choice(){

    }