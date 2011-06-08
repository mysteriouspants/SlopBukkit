/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 22
 */
 
 #include <iostream>
 #include <string>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// string<char> s = "Success!\n"; for(int i=0; i<=10; ++i) cout << s[i];
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_22.cpp
	PG165_22.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_22.cpp:13: error: Ôstd::stringÕ is not a template
	*/
	string s = "Success!\n"; for(int i=0; i<=10; ++i) cout << s[i];
 	return 0;
 }