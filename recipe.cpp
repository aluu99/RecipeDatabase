#include "recipe.h"
#include "cmpt_error.h"
#include <iostream>
#include <vector>

using namespace std;

    recipe::recipe(){
        cout << "It worked!\n";
    }

    recipe::recipe(const recipe& other){

    }

    recipe::~recipe(){

    }

    string recipe::get_name() const{
        cout << "Get_name\n";
        return -1;
    }

    int recipe::get_time() const{

    }

    string recipe::get_meal() const{

    }

    string recipe::get_ingreds() const{

    }

    string recipe::get_diet() const{

    }

    string recipe::get_ingred(int i) const{

    }

    string recipe::get_ingred_item(int i) const{

    }

    string recipe::get_ingred_amount(int i) const{

    }

    void recipe::set_name() const{

    }

    void recipe::set_time() const{

    }

    void recipe::set_meal() const{

    }

    void recipe::set_ingreds() const{

    }

    void recipe::set_diet() const{

    }

    void recipe::set_ingred(int i) const{

    }

    void recipe::set_ingred_item(int i) const{

    }

    void recipe::set_ingred_amount(int i) const{

    }

    void recipe::print() const{

    }
