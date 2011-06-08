/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091207, Chapter 17 Extra-Credit Assignment
 */

#include <iostream>
#include <string>
#include <cassert>

#include "LinkedList.h"


int main (int argc, char * const argv[]) {
	
	fsdev::LinkedList<std::string> * norse_gods = new fsdev::LinkedList<std::string>();
	norse_gods->add("Thor");
	norse_gods->add("Odin");
	norse_gods->add("Zeus");
	norse_gods->add("Freia");
	
	fsdev::LinkedList<std::string> * greek_gods = new fsdev::LinkedList<std::string>();
	greek_gods->add("Hera");
	greek_gods->add("Athena");
	greek_gods->add("Mars");
	greek_gods->add("Poseidon");
	
	std::cout << "Norse Gods: " << std::endl;
	norse_gods->print_all();
	std::cout << std::endl;
	
	std::cout << "Greek Gods: " << std::endl;
	greek_gods->print_all();
	
	std::cout << std::endl << "Fixing borked Pantheons" << std::endl << std::endl;
	
	norse_gods->remove(norse_gods->find("Zeus"));
	greek_gods->remove(greek_gods->find("Mars"));
	greek_gods->add("Ares");
	
	std::cout << "Norse Gods: " << std::endl;
	norse_gods->print_all();
	std::cout << std::endl;
	
	std::cout << "Greek Gods: " << std::endl;
	greek_gods->print_all();
	
    return 0;
}
