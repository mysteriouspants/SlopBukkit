/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090920, Pg 334 # 2
 */

#include <string>
#include <vector>

namespace fsdev {
	class Name_pairs {
	public:
		Name_pairs();
		
		std::vector<std::string> getNames();
		std::vector<double> getAges();
		
		void setNames(std::vector<std::string> _names);
		void setAges(std::vector<double> _ages);
		
		void read_names();
		void read_ages();
		
		void print();
		void sort();
	private:
		std::vector<std::string>	names;
		std::vector<double>			ages;
	};
}
