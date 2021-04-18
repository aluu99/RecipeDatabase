# RecipeDatabase

CMPT 135 Assignment 5
=====================

Names of Team Members
---------------------

(include the full names, SFU email addresses, and SFU student numbers of all
team members)
Erin Flood (301396466) eflood@sfu.ca
Amanda Luu (301335721) ala242@sfu.ca

Instructions for Compiling and Running
--------------------------------------

(put instructions here for compiling and running your program; hopefully it's
just to type "make" in the shell!)
Type in "make" into the terminal to compile.
Type in "./main_test" into the terminal to run

Limitations
-----------

(if you didn't implement all requested features, list which ones are missing)


Known Bugs
----------

(list all known bugs here)


Extra Features
--------------
(if your program has any extra or special features, tell us about them here)

1. The use of pointers
    - We used a vector of pointers to point to a single vector containing our recipes. Doing so allows us to save memory and also efficiency so that our program can support many recipes without slowing down as much as other databases.
2. A total of 8 different ways to search
    - Finding the perfect recipe is easy with our database as there are eight different ways to find one! You can search by:
        - Exact recipe name
        - Name name keyword
        - Exact time to make 
        - Time range to make
        - Exact ingredient
        - Ingredient keyword
        - Meal type
        - Diet type
3. A total of 6 different fields
    - Our database contains all the essential information you need to know for a recipe. You can access the following:
        - Recipe name
        - URL
        - Time to make
        - Meal type
        - Diet types
