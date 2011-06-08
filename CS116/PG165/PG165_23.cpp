/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 23
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// int i=0; while(i<10) ++j; if(j<i) cout << "Success!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_23.cpp
	PG165_23.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_23.cpp:12: error: ÔjÕ was not declared in this scope
	PG165_23.cpp:12: error: ÔjÕ was not declared in this scope
	*/
	#define j 0
	int i=0; while(i<10) ++i; if(j<i) cout << "Success!\n";
	#undef j
 	return 0;
 }