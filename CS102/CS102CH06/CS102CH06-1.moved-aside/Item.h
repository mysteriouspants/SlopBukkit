/*
 *  Item.h
 *  CS102CH06
 *
 *  Created by Chris Miller on 10/9/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _ITEM_H__
#define _ITEM_H__

class Item {
public:
	float Price, Discount;
	int Quantity;
	bool Taxable;
	char *Name;
	float computeCost();
}

#endif