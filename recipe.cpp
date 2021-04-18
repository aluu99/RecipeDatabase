#include "recipe.h"
#include "cmpt_error.h"
#include <iostream>
#include <vector>

using namespace std;
    /***************************CONSTRUCTORS*********************/
    // default constructor
    recipe::recipe(){}

    // constructor
    recipe::recipe(string n, string u, int t, string m, vector<string> i, vector<string> d)
    : name(n), url(u), time(t), meal(m), ingreds(i), diet(d){ }

    // copy constructor
    recipe::recipe(const recipe& other)
    : recipe(other.name,other.url, other.time,other.meal,other.ingreds,other.diet) { }

    // destructor
    recipe::~recipe(){
        
    }

    recipe& recipe::operator=(const recipe& r){
        set_name(r.get_name());
        set_url(r.get_url());
        set_time(r.get_time());
        set_meal(r.get_meal());
        set_ingreds(r.get_ingreds());
        set_diets(r.get_diets());
        return *this;
    }

    /***************************METHODS*********************/

    // GETTER METHODS
    string recipe::get_name() const{
        return name;
    }
    
    string recipe::get_url() const{
        return url;
    }

    int recipe::get_time() const {
        return time;
    }

    string recipe::get_meal() const{
        return meal;
    }

    vector<string> recipe::get_ingreds() const{
        return ingreds;
    }

    string recipe::get_ingred(int i) const{
        return ingreds.at(i);
    }

    int recipe::get_num_ingreds() const{
        return ingreds.size();
    }

    vector<string> recipe::get_diets() const{
        return diet;
    }

    string recipe::get_diet(int i) const{
        return diet.at(i);
    }

    int recipe::get_num_diets() const{
        return diet.size();
    }


    // SETTER METHODS
    void recipe::set_name(string s){
        name = s;
    }

    void recipe::set_url(string s) {
        url = s;
    }

    void recipe::set_time(int t){
        if(t < 0){
            cmpt::error("Invalid time amount passed.");
        }

        time = t;
    }

    void recipe::set_meal(string s){
        
        meal = s;
    }

    void recipe::set_ingreds(vector<string> recipes){
        ingreds.clear();
        for (int i = 0; i < recipes.size(); i++){
            ingreds.push_back(recipes.at(i));
        }
    }

    void recipe::set_diets(vector<string> d){
        diet = d;
    }

    // OTHER METHODS
    void recipe::add_ingred(string s){
        ingreds.push_back(s);
    }

    void recipe::change_ingred(int i, string s){
        ingreds.at(i) = s;
    }

    void recipe::delete_ingred(int index){
        ingreds.erase(ingreds.begin() + index);
    }

    void recipe::add_diet(string d){
        // if n/a is chosen, we erase all othe rdiets
        if(d == "n/a"){
            diet.clear();
        }
        
        diet.push_back(d);
    }

    void recipe::delete_diet(int index){
        diet.erase(diet.begin() + index);
    }

    void recipe::print() const{
        cout << "Name: " << name << "\n";
        cout << "URL: " << url << "\n";
        cout << "Time to make: " << time << " minutes \n";
        cout << "Meal type: " << meal << "\n";
        cout << "Ingredients: ";

        for(int i = 0; i < ingreds.size() - 1; i++){
            cout << ingreds[i] << ", ";
        }
        
        cout << ingreds[ingreds.size() - 1] << "\n";

        cout << "Diets: ";

        for(int i = 0; i < diet.size() - 1; i++){
            cout << diet[i] << ", ";
        }

        cout << diet[diet.size() - 1] << "\n";
    }