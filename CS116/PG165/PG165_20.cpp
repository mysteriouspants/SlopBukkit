/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 20
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// int i=0; int j=9; while (i<10) ++j; if (j<i) cout << "Success!\n";
 	// oh yes big surprise an infinite loop!
 	int i=0; int j=9; while (i<10) ++i; if (j<i) cout << "Success!\n";
 	return 0;
 }