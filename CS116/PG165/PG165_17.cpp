/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 17
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	// int x=2000; char c = x; if(c==2000) cout << "Success!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_17.cpp
	PG165_17.cpp: In function Ôint main(int, char* const*)Õ:
	PG165_17.cpp:12: warning: comparison is always false due to limited range of data type
	// WAY TO GO LLVM-G++, GO GET 'EM TIGER!
	*/
	int x=2000; wchar_t c = x; if(c==2000) cout << "Success!\n";
 	return 0;
 }