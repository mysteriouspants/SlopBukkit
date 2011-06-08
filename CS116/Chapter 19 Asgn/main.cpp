/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091212, Chapter 19 Assignment
 */

#include <iostream>
#include <string>

#include "Node.h"
#include "LinkedList.h"
#include "ListIterator.h"

int main (int argc, char * const argv[]) {

	using namespace std;
	using namespace fsdev;
	
	LinkedList<string> * norse_gods = new LinkedList<string>();
	norse_gods->add("Thor");
	norse_gods->add("Odin");
	norse_gods->add("Zeus");
	norse_gods->add("Freia");
	
	LinkedList<string> * greek_gods = new LinkedList<string>();
	greek_gods->add("Hera");
	greek_gods->add("Athena");
	greek_gods->add("Mars");
	greek_gods->add("Poseidon");
	
	cout << "Norse Gods: " << endl;
	ListIterator<string> norse_iter = norse_gods->begin();
	while(norse_iter!=norse_gods->end())
		cout << "  " << *norse_iter++ << endl;
	cout << endl;
	
	cout << "Greek Gods: " << endl;
	ListIterator<string> greek_iter = greek_gods->begin();
	while(greek_iter!=greek_gods->end())
		cout << "  " << *greek_iter++ << endl;
	cout << endl;
	
	cout << endl;
	cout << "Fixing borked pantheons." << endl << endl;
	
	norse_gods->del("Zeus");
	greek_gods->del("Mars");
	greek_gods->add("Ares");
	greek_gods->add("Zeus");
	
	cout << "Norse Gods: " << endl;
	norse_iter = norse_gods->begin();
	while(norse_iter!=norse_gods->end())
		cout << "  " << *norse_iter++ << endl;
	cout << endl;
	
	cout << "Greek Gods: " << endl;
	greek_iter = greek_gods->begin();
	while(greek_iter!=greek_gods->end())
		cout << "  " << *greek_iter++ << endl;
	cout << endl;
    
	return 0;
}
