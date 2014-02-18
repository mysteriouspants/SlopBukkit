/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140217, Chapter 13 Programming Challenge 6
 */

#include <iostream>
#include "inventory.hpp"

int main(int args, const char* argv[]) {
	std::cout << "Initialising inv0 with arguments of 1, 10, 19.97f..." << std::endl;
	Inventory inv0 = Inventory(1, 10, 19.97);
	std::cout << "inv0.getTotalCost: " << inv0.getTotalCost() << std::endl;

	std::cout << "Changing inv0's cost to 19.98..." << std::endl;
	inv0.setCost(19.98f);
	std::cout << "inv0.getTotalCost: " << inv0.getTotalCost() << std::endl;

	std::cout << "Changing inv0's quantity to 11..." << std::endl;
	inv0.setQuantity(11);
	std::cout << "inv0.getTotalCost: " << inv0.getTotalCost() << std::endl;

	return 0;
}