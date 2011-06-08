/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 7
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	//if(cond) cout << "Success!\n"; else cout << "Fail!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o pg165_7 PG165_7.cpp
	PG165_7.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_7.cpp:12: error: ÔcondÕ was not declared in this scope
	*/
	if(true) cout << "Success!\n"; else cout << "Fail!\n";
 	return 0;
 }