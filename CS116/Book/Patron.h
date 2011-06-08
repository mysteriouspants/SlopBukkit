/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090926, pg 334 # 9
 */

#include <string>

namespace fsdev {
	
	class Patron {
	private:
		std::string _name;
		unsigned long _card_number;
		long double _balance;
	public:
		Patron();
		Patron(std::string name,
			   unsigned long card_number,
			   long double balance);
		
		std::string name() const { return _name; };
		unsigned long card_number() const { return _card_number; };
		long double balance() const { return _balance; };
		
		void setName(std::string name);
		void setCard_number(unsigned long card_number);
		void setBalance(long double balance);
		
		bool hasDebt() const { return _balance<0.0; };
		
		friend bool operator == (const Patron& patron1, const Patron& patron2);
	};
	
	bool operator == (const Patron& patron1, const Patron& patron2);
	bool operator != (const Patron& patron1, const Patron& patron2);
	
}
