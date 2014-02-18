/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140217, Chapter 13 Programming Challenge 5
 */

#include "retail_item.hpp"

RetailItem::RetailItem() : _description(""), _unitsOnHand(0), _price(0.0f) { }

RetailItem::RetailItem(std::string&& description,int unitsOnHand,double price) :
	_description(description), _unitsOnHand(unitsOnHand), _price(price) { }

std::string RetailItem::getDescription() const { return _description; }
void RetailItem::setDescription(const std::string&& description) {
	_description = description;
}

int RetailItem::getUnitsOnHand() const { return _unitsOnHand; }
void RetailItem::setUnitsOnHand(int unitsOnHand) {
	_unitsOnHand = unitsOnHand;
}

double RetailItem::getPrice() const { return _price; }
void RetailItem::setPrice(double price) {
	_price = price;
}