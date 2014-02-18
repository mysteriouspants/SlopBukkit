/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140217, Chapter 13 Programming Challenge 5
 */

#include <string>

#ifndef RETAIL_ITEM_HPP
#define RETAIL_ITEM_HPP

class RetailItem {
	std::string _description;
	int _unitsOnHand;
	double _price;
public:
	RetailItem();
	RetailItem(std::string&&,int,double);

	std::string getDescription() const;
	void setDescription(const std::string&&);

	int getUnitsOnHand() const;
	void setUnitsOnHand(int);

	double getPrice() const;
	void setPrice(double);
};

#endif