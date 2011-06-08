/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090914, Pg. 165 # 12
 */
 
 #include <iostream>
 #include <string>
 
 using namespace std;
 
 int main ( int argc, char * const argv[] ) {
 	//string s = "ape"; if(s+"fool") cout < "Success!\n";
 	/*
 	cmiller-laptop% llvm-g++ -o a.out PG165_12.cpp
	PG165_12.cpp: In function ‘int main(int, char* const*)’:
	PG165_12.cpp:13: error: could not convert ‘std::operator+(const std::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*) [with _CharT = char, _Traits = std::char_traits<char>, _Alloc = std::allocator<char>](((const char*)"fool"))’ to ‘bool’
	PG165_12.cpp:13: error: no match for ‘operator<’ in ‘std::cout < "Success!\012"’
	PG165_12.cpp:13: note: candidates are: operator<(const char*, const char*) <built-in>
	PG165_12.cpp:13: note:                 operator<(void*, void*) <built-in>
	*/
	string s = "ape"; if(s+"fool"==s+"fool") cout << "Success!\n";
 	return 0;
 }