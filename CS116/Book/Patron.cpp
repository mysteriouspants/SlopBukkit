/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090926, pg 334 # 9
 */

#include "Patron.h"

namespace fsdev {

	Patron::Patron() {
		
	}
	
	Patron::Patron(std::string name,
		   unsigned long card_number,
		   long double balance)
		   : _name(name),
		   _card_number(card_number),
		   _balance(balance) {
		
	}
	
	void Patron::setName(std::string name) { _name = name; }
	void Patron::setCard_number(unsigned long card_number) { _card_number = card_number; }
	void Patron::setBalance(long double balance) { _balance = balance; }
	
	bool operator == (const Patron& patron1, const Patron& patron2) {
		return patron1._card_number==patron2._card_number;
	}
	
	bool operator != (const Patron& patron1, const Patron& patron2) {
		return !(patron1==patron2);
	}
	
}
