#include "recipe.h"
#include "cmpt_error.h"
#include <iostream>
#include <vector>

using namespace std;

/*
    string name;
    int time;
    string meal;
    vector<ingred> ingreds;
    string diet;
*/


    recipe::recipe(){
        //TODO: ask for all the info
        cout << "It worked!\n";
    }

    recipe::recipe(string n, int t, string m, vector<ingred> i, string d)
    : name(n), time(t), meal(m), ingreds(i), diet(d) { }

    recipe::recipe(const recipe& other)
    : recipe(other.name,other.time,other.meal,other.ingreds,other.diet) { }

    recipe::~recipe(){
        
    }
    
    string recipe::get_name() const{
        return name;
    }

    int recipe::get_time() const{
        return time;
    }

    string recipe::get_meal() const{
        return meal;
    }

    vector<ingred> recipe::get_ingreds() const{
        return ingreds;
    }

    string recipe::get_diet() const{
        return diet;
    }

    ingred recipe::get_ingred(int i) const{
        return ingreds.at(i);
    }

    string recipe::get_ingred_item(int i) const{
        return ingreds.at(i).item;
    }

    string recipe::get_ingred_amount(int i) const{
        return ingreds.at(i).amount;
    }

    void recipe::set_name(string s){
        name = s;
    }

    void recipe::set_time(int t){
        time = t;
    }

    void recipe::set_meal(string s){
            meal = s;
    }

    void recipe::set_ingreds(vector<ingred> recipes){
        ingreds.clear();
        for (int i = 0; i < recipes.size(); i++){
            ingreds.push_back({recipes.at(i).item,recipes.at(i).amount});
        }
    }

    void recipe::add_ingred(ingred i){
        ingreds.push_back(i);
    }

    void recipe::delete_ingred(int index){
        ingreds.erase(ingreds.begin() + index);
    }

    void recipe::set_diet(string s){
        diet = s;
    }

    void recipe::set_ingred(int i, string itm, string amt){
        recipe::set_ingred_item(i, itm);
        recipe::set_ingred_amount(i, amt);
    }

    void recipe::set_ingred_item(int i, string s){
        ingreds.at(i).item = s;
    }

    void recipe::set_ingred_amount(int i, string s){
        ingreds.at(i).amount = s;
    }

    void recipe::print() const{
        
    }
