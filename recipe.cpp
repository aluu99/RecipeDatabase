#include "recipe.h"
#include "database.h"


using namespace std;

    /***************************CON/DE-STRUCTORS***************************/

    // Default constructor
    recipe::recipe(){}

    // Constructor
    recipe::recipe(string n, string u, int t, string m, vector<string> i, vector<string> d)
    : name(n), url(u), time(t), meal(m), ingreds(i), diet(d){ }

    // Copy constructor
    recipe::recipe(const recipe& other)
    : recipe(other.name,other.url, other.time,other.meal,other.ingreds,other.diet) { }

    // Destructor
    recipe::~recipe(){}

    /******************************OVERLOADING*****************************/

    recipe& recipe::operator=(const recipe& r){
        set_name(r.get_name());
        set_url(r.get_url());
        set_time(r.get_time());
        set_meal(r.get_meal());
        set_ingreds(r.get_ingreds());
        set_diets(r.get_diets());
        return *this;
    }

    bool operator==(recipe a, recipe b){
        if(a.get_name() != b.get_name()) return false;
        if(a.get_url() != b.get_url()) return false;
        if(a.get_time() != b.get_time()) return false;
        if(a.get_meal() != b.get_meal()) return false;
        if(a.get_ingreds() != b.get_ingreds()) return false;
        if(a.get_diets() != b.get_diets()) return false;
        return true;
    }

    /********************************METHODS******************************/

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

    void recipe::set_url(string s){
        url = s;
    }

    void recipe::set_time(int t){
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

    // Print Recipe Info
    
    void recipe::print() const{
        cout << "Name: " << name << "\n";
        cout << "URL: " << url << "\n";
        cout << "Time to make: " << time << " minutes \n";
        cout << "Meal type: " << meal << "\n";
        cout << "Ingredients: " << vector_to_string(ingreds) << "\n";
        cout << "Diets: " << vector_to_string(diet) << "\n";
    }