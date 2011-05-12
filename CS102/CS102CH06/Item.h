/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           6
 Date Due:               16 October 2008
 Date Submitted:         | 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3,GCC 4.0.0, x86
 File Name:              Item.h
*/

#ifndef _ITEM_H__
#define _ITEM_H__

#define TAX 1.07F

class Item {
public:
	Item();
	float Price, Discount;
	int Quantity;
	bool Taxable;
	char *Name;
	float computeCost();
};

#endif
