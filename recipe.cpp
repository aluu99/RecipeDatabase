#include "recipe.h"
#include "cmpt_error.h"
#include <iostream>
#include <vector>

using namespace std;

    // default constructor
    recipe::recipe(){
    }

    // constructor
    recipe::recipe(string n, string u, int t, string m, vector<string> i, vector<string> d, int idd)
    : name(n), url(u), time(t), meal(m), ingreds(i), diet(d), id(idd) { }

    // copy constructor
    recipe::recipe(const recipe& other)
    : recipe(other.name,other.url, other.time,other.meal,other.ingreds,other.diet, other.id) { }

    // destructor
    recipe::~recipe(){
        
    }
    
    // methods
    int recipe::get_id() const{
        return id;
    }

    string recipe::get_name() const{
        return name;
    }

    string recipe::get_url() const{
        return url;
    }

    int recipe::get_time() const{
        return time;
    }

    vector<string> recipe::get_ingreds() const{
        return ingreds;
    }


    string recipe::get_ingred(int i) const{
        return ingreds.at(i);
    }

    void recipe::set_id(int i){
        id = i;
    }

    void recipe::set_name(string s){
        name = s;
    }

    void recipe::set_url(string s) {
        url = s;
    }

    vector<string> recipe::get_meals() const{
        return meal_options;
    }

    vector<string> recipe::get_diets() const{
        return diet_options;
    }

    void recipe::set_time(int t){
        if(t <= 0){
            cmpt::error("Invalid time amount passed.");
        }

        time = t;
    }

    void recipe::set_meal(string s){
        if(!(s == "breakfast" || s == "lunch" || s == "dinner")){
            cmpt::error("Invalid meal type passed.");
        }

        meal = s;
    }

    void recipe::set_ingreds(vector<string> recipes){
        ingreds.clear();
        for (int i = 0; i < recipes.size(); i++){
            ingreds.push_back(recipes.at(i));
        }
    }

    void recipe::add_ingred(string s){
        ingreds.push_back(s);
    }

    void recipe::change_ingred(int i, string s){
        ingreds.at(i) = s;
    }


    void recipe::delete_ingred(int index){
        ingreds.erase(ingreds.begin() + index);
    }

    void recipe::set_diet(vector<string> d){
        diet = d;
    }

    void recipe::add_diet(string d){
        diet.push_back(d);
    }

    void recipe::delete_diet(int index){
        diet.erase(diet.begin() + index);
    }

    void recipe::print() const{
        
    }
