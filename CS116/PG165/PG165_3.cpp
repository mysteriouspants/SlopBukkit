/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 3
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// cout << "Success" << !\n"
 	/*
 	cmiller-laptop% llvm-g++ -o pg165_3 PG165_3.cpp
 	PG165_3.cpp:12: error: stray Ô\Õ in program
	PG165_3.cpp:12:27: warning: missing terminating " character
	PG165_3.cpp:12: error: missing terminating " character
	PG165_3.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_3.cpp:12: error: ÔnÕ was not declared in this scope
	PG165_3.cpp:13: error: expected `;' before ÔreturnÕ
 	*/
 	
 	cout << "Success" << "!\n";
 	
 	return 0;
 }