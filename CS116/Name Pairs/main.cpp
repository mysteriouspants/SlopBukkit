/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090920, Pg 334 # 2
 */

#include <iostream>
#include "NamePair.h"

using namespace std;

int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Please enter a list of names separated by spaces, with `done' being the last token entered.\n";
	fsdev::Name_pairs np;
	
	np.read_names();
	std::cout << "Now please supply ages for each name.\n";
	np.read_ages();
	
	np.sort();
	np.print();
	
    return 0;
}
