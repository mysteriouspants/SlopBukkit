/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 11
 */
 
 #include <iostream>
 #include <string>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// string s = "ape"; if(s=="fool") cout < "Success!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_11.cpp
	PG165_11.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_11.cpp:13: error: no match for Ôoperator<Õ in Ôstd::cout < "Success!\012"Õ
	PG165_11.cpp:13: note: candidates are: operator<(const char*, const char*) <built-in>
	PG165_11.cpp:13: note:                 operator<(void*, void*) <built-in>
	*/
	string s = "ape"; if(s=="fool") cout << "Success!\n";
 	return 0;
 }