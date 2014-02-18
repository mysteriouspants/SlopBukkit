/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140217, Chapter 13 Programming Challenge 6
 */

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

class Inventory {
	int _itemNumber;
	int _quantity;
	double _cost;
	double _totalCost;
public:
	Inventory();
	Inventory(int,int,double);

	void setItemNumber(int);
	int getItemNumber() const;

	void setQuantity(int);
	int getQuantity() const;

	void setCost(double);
	double getCost() const;

	void setTotalCost();
	double getTotalCost() const;
};

#endif