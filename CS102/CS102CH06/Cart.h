/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           6
 Date Due:               16 October 2008
 Date Submitted:         | 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3,GCC 4.0.0, x86
 File Name:              Cart.h
*/

#ifndef _CART_H__
#define _CART_H__

#include <vector>
#include "Item.h"

using namespace std;

class Cart {
public:
	Cart();
	vector<Item> Contents;
	float getTotal();
};

#endif