/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 15
 */
 
 #include <string>
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_15.cpp
	cmiller-laptop% ./a.out
	Succes%
	*/
	string s = "Success!\n"; for (int i=0; i<s.length(); ++i) cout << s[i];
	/*
	cmiller-laptop% llvm-g++ -o a.out PG165_15.cpp
	cmiller-laptop% ./a.out                       
	Success!
	*/
 	return 0;
 }