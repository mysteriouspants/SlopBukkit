/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 16
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	#define then
 	if(true)then cout << "Success!\n"; else cout << "Fail!\n";
 	#undef then
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_16.cpp
	PG165_16.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_16.cpp:12: error: ÔthenÕ was not declared in this scope
	PG165_16.cpp:12: error: expected `;' before ÔcoutÕ
	*/
 	return 0;
 }