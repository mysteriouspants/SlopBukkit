#include "retail_item.hpp"

RetailItem::RetailItem() : _description(""), _unitsOnHand(0), _price(0.0f) { }

RetailItem::RetailItem(const char* description,int unitsOnHand,double price) :
	_description(description), _unitsOnHand(unitsOnHand), _price(price) { }

RetailItem::RetailItem(std::string& description,int unitsOnHand,double price) :
	_description(description), _unitsOnHand(unitsOnHand), _price(price) { }

std::string RetailItem::getDescription() const { return _description; }
void RetailItem::setDescription(std::string& description) {
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