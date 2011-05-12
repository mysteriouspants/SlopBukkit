/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 Ð 9:40	
 Student ID:             0345979
 Assignment #:           Chapter 2
 Date Due:               18 September 2008
 Date Submitted:         17 September 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3, GCC 4.0.1, x86
 File Name:              main.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;

struct Choant { // char, float, int
	char	MiddleInitial;
	int		Age;
	float	Height;
};

void outputChoant(Choant foo, char* title);

int main () {
	Choant me;
	me.MiddleInitial='R';
	me.Age=18;
	me.Height=75.0f;

	outputChoant(me, "Myself");
	
	Choant amigo;
	amigo.MiddleInitial='S';
	amigo.Age=18;
	amigo.Height=76.0f;
	
	outputChoant(amigo, "Mi Amigo");
	
	cout << "Please enter your middle initial: ";
	cin.get(me.MiddleInitial);
	cout << "Please enter your age (in years): ";
	cin >> me.Age;
	cout << "Please enter your height (in inches): ";
	cin >> me.Height;
	
	outputChoant(me, "You Entered:");
	
	// average the two ages
	amigo.Height = (me.Age + amigo.Age) / 2;
	
	cout << "The average of my friend's age and your age is: " << amigo.Height << endl;
	
	// pause before exiting
	cout << "Press the any key to continue.\b";
	cin.get(me.MiddleInitial);
	
    return 0;
}

// wee helper function to prevent me from repeating myself
void outputChoant(Choant foo, char* title="Anonymous"){
	cout << title << endl;
	printf("\tMiddle Initial: %c\n", foo.MiddleInitial);
	printf("\tAge:            %2i\n", foo.Age);
	printf("\tHeight:         %1.1f\n", foo.Height);
}

/*
 [Session started at 2008-09-16 23:32:39 -0700.]
 Myself
 Middle Initial: R
 Age:            18
 Height:         75.0
 Mi Amigo
 Middle Initial: S
 Age:            18
 Height:         76.0
 Please enter your middle initial: R
 Please enter your age (in years): 18
 Please enter your height (in inches): 76
 You Entered:
 Middle Initial: R
 Age:            18
 Height:         76.0
 The average of my friend's age and your age is: 18
 Press the any key to continue.
 The Debugger has exited with status 0.
 [Session started at 2008-09-16 23:33:02 -0700.]
 Myself
 Middle Initial: R
 Age:            18
 Height:         75.0
 Mi Amigo
 Middle Initial: S
 Age:            18
 Height:         76.0
 Please enter your middle initial: T
 Please enter your age (in years): 900
 Please enter your height (in inches): 3
 You Entered:
 Middle Initial: T
 Age:            900
 Height:         3.0
 The average of my friend's age and your age is: 459
 Press the any key to continue.
*/
