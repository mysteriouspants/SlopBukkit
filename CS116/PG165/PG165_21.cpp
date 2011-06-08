/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 21
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// int x = 2; double d = 5/(x-2); if(d==2*x+0.5) cout << "Success!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_21.cpp
	cmiller-laptop% ./a.out                       
	zsh: floating point exception  ./a.out
	*/
	int x = 2; double d = 5.0f-(x-1.5f); if(d==2.0f*x+0.5f) cout << "Success!\n";
 	return 0;
 }