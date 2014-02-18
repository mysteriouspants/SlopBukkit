/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140217, Chapter 13 Programming Challenge 6
 */

#include "inventory.hpp"

Inventory::Inventory() : _itemNumber(0), _quantity(0), _cost(0.0f), _totalCost(0.0f) { }

Inventory::Inventory(int itemNumber, int quantity, double cost) :
	_itemNumber(itemNumber), _quantity(quantity), _cost(cost) {
	setTotalCost();
}

void Inventory::setItemNumber(int itemNumber) {
	_itemNumber = itemNumber;
}

int Inventory::getItemNumber() const {
	return _itemNumber;
}

void Inventory::setQuantity(int quantity) {
	_quantity = quantity;
	setTotalCost();
}

int Inventory::getQuantity() const {
	return _quantity;
}

void Inventory::setCost(double cost) {
	_cost = cost;
	setTotalCost();
}

double Inventory::getCost() const {
	return _cost;
}

void Inventory::setTotalCost() {
	_totalCost = _cost * _quantity;
}

double Inventory::getTotalCost() const {
	return _totalCost;
}