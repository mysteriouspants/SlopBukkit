/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           6
 Date Due:               16 October 2008
 Date Submitted:         | 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3,GCC 4.0.0, x86
 File Name:              Cart.cpp
*/


#include "Cart.h"
#include "Item.h"

using namespace std;

float Cart::getTotal() {
	double total=0.00;
	for(vector<Item>::iterator iter=Contents.begin();iter<Contents.end();++iter)
		total+=static_cast<double>((*iter).computeCost());
	return total;
}

Cart::Cart() { }
