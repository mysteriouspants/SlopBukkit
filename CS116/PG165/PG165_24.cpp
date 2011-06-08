/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 24
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	int x = 4; double d = 5/(x-2); if (d=2*x+0.5) cout << "Success!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_24.cpp
	cmiller-laptop% ./a.out                       
	Success!
	*/
 	return 0;
 }