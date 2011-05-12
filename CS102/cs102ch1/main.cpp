/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           Chapter 1 - Simple Program
 Date Due:               11 September 2008
 Date Submitted:         06 September 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3, GCC 4.0.1, x86
 File Name:              main.cpp
 */
//This program calculates the users pay.
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits>

using namespace std;

int main () {
    float hours, rate, pay;
	char tmp[50]; bool loop_esc=false;
	
	do { // prompt user for hours worked
		cout.flush();
		cout << "How many hours did you work? ";
		cin >> tmp;
	
		// reprompt if bad input it given
		for(int idx=0; tmp[idx]!='\0'; ++idx)
			if((tmp[idx]<'0'||tmp[idx]>'9')&&tmp[idx]!='.') {
				cout << "Numerical input only please!" << endl;
				loop_esc=true;
				break;
			}
		
		// flip it, since a continue in the for loop would have
		// done nothing, whereas by changing the value of loop_esc
		// it signals that the input didn't validate
		if(loop_esc)
			loop_esc=false;
		else 
			loop_esc=true;
		
	} while (!loop_esc);
	loop_esc=false;
	
	hours = atof(tmp); // since correct input has now been given,
	// parse the inputed string to a float for use

	// use a similar construct
	do {
		cout.flush();
		cout << "How much did you get paid per hour? $";
		cin >> tmp;
		
		for(int idx=0; tmp[idx]!='\0'; ++idx)
			if((tmp[idx]<'0'||tmp[idx]>'9')&&tmp[idx]!='.') {
				cout << "Numerical input only please!" << endl;
				loop_esc=true;
				break;
			}
		
		if(loop_esc)
			loop_esc=false;
		else 
			loop_esc=true;
		
	} while(!loop_esc);
	
	rate=atof(tmp);
	
	pay = hours * rate;
	
	cout << "You have earned $";
	
	// use cstdio for finer output control
	printf("%4.2f\n",pay);
	
	// emulate system("PAUSE") for non-Win32 platforms
	cout << "Press the any key to continue..." << endl ;
	cout.flush();
	// according to some guy who knows more STL than me, this is the right
	// way to do it.  Still doesn't work right on Darwin, I suspect an issue
	// with the BSD curses implementation.
	cin.ignore( numeric_limits<streamsize>::max(), '\n');
	
    return 0;
}

/*
 How many hours did you work? twenty
 Numerical input only please!
 How many hours did you work? 20
 How much did you get paid per hour? $not enough
 Numerical input only please!
 How much did you get paid per hour? $Numerical input only please!
 How much did you get paid per hour? $1.75
 You have earned $35.00
 Press the any key to continue...
*/ 
