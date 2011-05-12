// main.cpp

#include <stdio.h>
#include <string>
#include <strstream>
using namespace std;

extern "C" void asmMain( );
extern "C" void printSingle( float d, int precision );

void printSingle( float d, int precision )
{
	strstream temp;
	temp << "%." << precision << "f" << '\0';
	printf(temp.str( ), d );
}


int main( )
{
/* You must include at least one statement that
	uses floating-point values, to force Visual C++
	to load the floating-point module. Otherwise,
	a "floating point not loaded" error occurs. */

	double d = 3.5;

	asmMain( );
	return 0;
}