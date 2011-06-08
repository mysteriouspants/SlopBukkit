/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 4
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// cout << success << endl;
 	/*
 	cmiller-laptop% llvm-g++ -o pg165_4 PG165_4.cpp
	PG165_4.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_4.cpp:12: error: ÔsuccessÕ was not declared in this scope
	*/
	cout << "success" << endl;
 	return 0;
 }