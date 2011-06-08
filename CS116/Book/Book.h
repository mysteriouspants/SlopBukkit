/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090926, pg 334 # 9
 */

#include <string>
#include <iostream>

namespace fsdev {
	
	typedef struct {
		size_t field1;
		size_t field2;
		size_t field3;
		unsigned char field4;
	} ISBN;
	
	typedef enum {
		YES,
		NO
	} shelf_status;
	
	typedef enum {
		fiction,
		nonfiction,
		periodical,
		biography,
		children
	} book_genre;
	
	class Book {
	private:
		ISBN _isbn;
		std::string _title;
		std::string _author;
		size_t _year;
		shelf_status _onShelf;
		book_genre _genre;
	public:
		Book();
		Book(
			 ISBN isbn,
			 std::string title,
			 std::string author,
			 size_t year,
			 book_genre genre,
			 shelf_status onShelf
			 );
		
		ISBN isbn() const { return _isbn; };
		std::string title() const { return _title; };
		std::string author() const { return _author; };
		size_t year() const { return _year; };
		book_genre genre() const { return _genre; };
		shelf_status onShelf() const { return _onShelf; };
		
		void setIsbn(ISBN isbn);
		void setTitle(std::string title);
		void setAuthor(std::string author);
		void setYear(size_t year);
		void setGenre(book_genre genre);
		void setOnShelf(shelf_status onShelf);
		
		friend std::istream& operator >> (std::istream& is, Book& book);
		
	};
	
	bool operator == (const ISBN& isbn1, const ISBN& isbn2);
	bool operator != (const ISBN& isbn1, const ISBN& isbn2);
	bool operator == (const Book& book1, const Book& book2);
	bool operator != (const Book& book1, const Book& book2);
	
	std::ostream& operator << (std::ostream& os, const ISBN& isbn);
	std::ostream& operator << (std::ostream& os, const Book& book);
	
	std::istream& operator >> (std::istream& is, ISBN& isbn);
	std::istream& operator >> (std::istream& is, Book& book);
	
	std::ostream& operator << (std::ostream& os, const book_genre& genre);
	std::istream& operator >> (std::istream& is, book_genre& genre);
	
}
