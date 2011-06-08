/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 9
 */
 
 #include <string>
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	//string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_9.cpp
	PG165_9.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_9.cpp:13: error: ÔbooÕ was not declared in this scope
	PG165_9.cpp:13: error: expected `;' before ÔcÕ
	PG165_9.cpp:13: error: ÔcÕ was not declared in this scope
	*/
	string s = "ape"; bool c = "fool"<s; if (c) cout << "Success!\n";
 	return 0;
 }