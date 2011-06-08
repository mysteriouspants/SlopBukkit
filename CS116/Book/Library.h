/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090926, pg 334 # 9
 */

#include "Book.h"
#include "Patron.h"

#include <vector>

/**
 Create a Library class.  Include vectors of Books and Patrons.  Include
 a struct called Transaction.  Have it include a Book, a Patron, and a
 Date from the chapter.  Make a vector of Transactions.  Create functions
 to add books to the library, add patrons to the library, and check out
 books.  Whenever a user checks out a book, have the library make sure
 that both the user and the book are in the library.  If they aren't
 report an error.  Then check to make sure that the user owes no fees.
 If the user does, report an error.  If not, create a Transaction, and
 place it in the vector of Transactions.  Also create a method will
 return a vector that contains the names of all Patrons who owe fees.
 */

namespace fsdev {
	
	struct Transaction {
		Book& book;
		Patron& patron;
		// date
	};
	
	class Library {
	private:
		std::vector<Book> _books;
		std::vector<Patron> _patrons;
	public:
		
	};
	
}
