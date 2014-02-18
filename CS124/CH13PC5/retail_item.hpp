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