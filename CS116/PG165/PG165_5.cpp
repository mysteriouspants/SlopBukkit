/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 5
 */
 
 #include <vector>
 #include <iostream>
 #include <string>
 #include <cstring>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	//string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o pg165_5 PG165_5.cpp
	PG165_5.cpp: In function ‘int main(int, char* const*)’:
	PG165_5.cpp:14: error: invalid conversion from ‘int’ to ‘const char*’
	PG165_5.cpp:14: error:   initializing argument 1 of ‘std::basic_string<_CharT, _Traits, _Alloc>::basic_string(const _CharT*, const _Alloc&) [with _CharT = char, _Traits = std::char_traits<char>, _Alloc = std::allocator<char>]’
	PG165_5.cpp:14: error: cannot convert ‘std::string’ to ‘int’ in assignment
	*/
	string res = "7"; vector<int> v(10); v[5] = atoi(res.c_str()); cout << "Success!\n";
 	return 0;
 }