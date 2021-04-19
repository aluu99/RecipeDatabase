# RecipeDatabase

CMPT 135 Assignment 5
=====================

Names of Team Members
---------------------

Erin Flood (301396466) eflood@sfu.ca
Amanda Luu (301335721) ala242@sfu.ca

Instructions for Compiling and Running
--------------------------------------

Type in "make" into the terminal to compile.
Type in "./main_test" into the terminal to run

Database Description
--------------------

Our database is a virtual recipe box! It allows the user to store, add, search for and delete their favourite recipes. By simply following along with the menu prompts, the user has easy access to use and update their recipe box.

Limitations
-----------

1. The ncurses library was not used to help draw menus.
2. No handling of commas that appear in strings in a comma separated list; however, due to the nature of the fields and list items, no commas would be in the strings.

Known Bugs
----------

When a recipe has multiple of the same type of ingredient (ie. tomato, tomato paste, etc.), it will show up mutliple times when you search by keyword.

Extra Features
--------------

1. The use of pointers
    - We used a vector of pointers (rb_by_name and rb_by_time) to point to a single vector containing our recipes (recipe_box) in alphabetical and time ascending order, respectively. Doing so allows us to save memory and also efficiency so that our program can support more recipes than other databases.
2. A total of 8 different ways to search
    - Finding the perfect recipe is easy with our database as there are eight different ways to find one! You can search by:
        - Exact recipe name
        - Recipe name keyword
        - Exact time to make 
        - Time range to make
        - Exact ingredient
        - Ingredient keyword
        - Meal type
        - Diet type
3. A total of 6 different fields of varying datatypes
    - The database consists of one int field, 3 string fields, and 2 vector fields.
        - The vector fields allow for multiple ingredients and diet types to be saved.
    - Our database contains all the essential information you need to know for a recipe. You can access the following:
        - Recipe name   (string)
        - URL           (string)
        - Time to make  (int)
        - Meal type     (string)
        - Diet types    (vector string)
        - Ingredients   (vector string)

Future Improvements
-------------------

We would like to implement the following features:
    - Ncurses menus
    - Edit a recipe: allow users to edit an existing recipe
    - Save to favourites: allow users to save favourite recipes to a    
        separate list
    - Allow user to click URL and be directed to the website
    - Allow user to store the amount of ingredients needed
