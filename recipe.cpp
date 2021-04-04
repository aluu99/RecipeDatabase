#include "recipe.h"
#include "cmpt_error.h"
#include <iostream>
#include <vector>

using namespace std;

    // default constructor
    recipe::recipe(){
    }

    // constructor
    recipe::recipe(string n, int t, string m, vector<string> i, vector<string> d)
    : name(n), time(t), meal(m), ingreds(i), diet(d) { }


    // copy constructor
    recipe::recipe(const recipe& other)
    : recipe(other.name,other.time,other.meal,other.ingreds,other.diet) { }

    // destructor
    recipe::~recipe(){
        
    }
    
    // methods
    string recipe::get_name() const{
        return name;
    }

    string recipe::get_url() const{
        return url;
    }

    int recipe::get_time() const{
        return time;
    }

    string recipe::get_meal() const{
        return meal;
    }

    vector<string> recipe::get_ingreds() const{
        return ingreds;
    }

    string recipe::get_diet(int i) const{
        return diet.at(i);
    }

    string recipe::get_ingred(int i) const{
        return ingreds.at(i);
    }

    void recipe::set_name(string s){
        name = s;
    }

    void recipe::set_url(string s) {
        url = s;
    }

    vector<string> recipe::get_meal_options() const{
        return meal_options;
    }

    vector<string> recipe::get_diet_options() const{
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
