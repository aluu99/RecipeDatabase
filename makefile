####################################################################
#
# Makefile for CMPT 135 Spring 2021, SFU Surrey.
#
#####################################################################

# Set the C++ compiler options:
#   -std=c++17 compiles using the C++17 standard
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

main_test: main.o menu.o recipe.o database.o test.o
	g++ -o main_test main.o menu.o recipe.o database.o test.o -lncurses

menu:
	g++ -c $(CPPFLAGS) menu.cpp -lncurses 

recipe:
	g++ -c $(CPPFLAGS) recipe.cpp -lncurses 

database:
	g++ -c $(CPPFLAGS) database.cpp -lncurses 

test:
	g++ -c $(CPPFLAGS) test.cpp -lncurses 

clean:
	rm -f main_test main.o menu.o recipe.o database.o test.o