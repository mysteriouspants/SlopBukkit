/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090926, pg 334 # 9
 */

#include "Book.h"

#include <cstring>

namespace fsdev {
	
	Book::Book() {
		
	}

	Book::Book(
			  ISBN isbn,
			  std::string title,
			  std::string author,
			  size_t year,
			  book_genre genre,
			  shelf_status onShelf
			  ) : _isbn(isbn),
				  _title(title),
				  _author(author),
				  _year(year),
				  _genre(genre),
				  _onShelf(onShelf) {
		
	}

	void Book::setIsbn(ISBN isbn) {
		_isbn = isbn;
	}
	void Book::setTitle(std::string title) {
		_title = title;
	}
	void Book::setAuthor(std::string author) {
		_author = author;
	}
	void Book::setYear(size_t year) {
		_year = year;
	}
	void Book::setGenre(book_genre genre) {
		_genre = genre;
	}
	void Book::setOnShelf(shelf_status onShelf) {
		_onShelf = onShelf;
	}

	bool operator == (const ISBN& isbn1,
					  const ISBN& isbn2) {
		return (isbn1.field1==isbn2.field1
				&&
				isbn1.field2==isbn2.field2
				&&
				isbn1.field3==isbn2.field3
				&&
				isbn1.field4==isbn2.field4
				);
	}
	bool operator != (const ISBN& isbn1,
					  const ISBN& isbn2) {
		if(isbn1.field1==isbn2.field1
		   &&
		   isbn1.field2==isbn2.field2
		   &&
		   isbn1.field3==isbn2.field3
		   &&
		   isbn1.field4==isbn2.field4
		   )
			return false;
		else
			return true;
	}
	bool operator == (const Book& book1,
					  const Book& book2) {
		return book1.isbn()==book2.isbn();
	}
	bool operator != (const Book& book1,
					  const Book& book2) {
		return book1.isbn()!=book2.isbn();
	}
	
	std::ostream& operator << (std::ostream& os,
							   const ISBN& isbn) {
		os << isbn.field1 << '-' << isbn.field2 << '-' << isbn.field3 << '-' << isbn.field4;
		return os;
	}
	std::ostream& operator << (std::ostream& os,
							   const Book& book) {
		os << book.author() << ", " << book.title() << " (" << book.genre() << ')' << std::endl;
		os << "    ISBN: " << book.isbn() << std::endl;
		return os;
	}
	
	std::istream& operator >> (std::istream& is,
							   ISBN& isbn) {
		is >> isbn.field1 >> isbn.field2 >> isbn.field3;
		isbn.field4='\0';
		while(!isalnum(isbn.field4))
			is >> isbn.field4;
		return is;
	}
	std::istream& operator >> (std::istream& is,
							   Book& book) {
		// clever use of friend function to avoid nasty syntaxing
		is >> book._title >> book._author >> book._year >> book._genre >> book._isbn;
		return is;
	}
	
	std::ostream& operator << (std::ostream& os,
							   const book_genre& genre) {
		switch(genre) {
			case fiction:
				os << "fiction";
				break;
			case nonfiction:
				os << "non-fiction";
				break;
			case periodical:
				os << "periodical";
				break;
			case biography:
				os << "biography";
				break;
			case children:
				os << "children";
				break;
			default:
				os << "eep!";
				break;
		}
		return os;
	}
	std::istream& operator >> (std::istream& is,
							   book_genre& genre) {
		std::string in;
		is >> in;
		if(in=="fiction")
			genre = fiction;
		else if(in=="non-fiction")
			genre = nonfiction;
		else if(in=="periodical")
			genre = periodical;
		else if(in=="biography")
			genre = biography;
		else if(in=="children")
			genre = children;
		else 
			genre = fiction; // hehe
		return is;
	}

}
