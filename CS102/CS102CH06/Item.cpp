/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           6
 Date Due:               16 October 2008
 Date Submitted:         | 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3,GCC 4.0.0, x86
 File Name:              Item.cpp
*/

#include "Item.h"

#include <iostream>
using namespace std;

float Item::computeCost() {
	return ((Price * static_cast<float>(Quantity)) - ((Price * static_cast<float>(Quantity)) * (Discount*0.01))) * ((Taxable)?TAX:1.00F);
}

Item::Item() { }