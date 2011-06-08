/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 8
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o pg165_8 PG165_8.cpp
	cmiller-laptop% ./pg165_8
	Fail!
	*/
 	return 0;
 }