/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090920, Ch 8 Lab 2
 */

#include <iostream>

using namespace std;

void swap_v(int,int);
void swap_r(int&,int&);
//void swap_cr(const int&,const int&);

int main (int argc, char * const argv[]) {
	int x=7;
	int y=9;
	cout << x << " " << y << endl;
	swap_r(x, y);
	cout << x << " " << y << endl;
	swap_v(7, 9);
	const int cx=7;
	const int cy=9;
	cout << cx << " " << cy << endl;
	swap_v(cx,cy);
	cout << cx << " " << cy << endl;
	swap_v(7.7,9.9);
	double dx=7.7;
	double dy=9.9;
	cout << dx << " " << dy << endl;
	swap_v(dx,dy);
	cout << dx << " " << dy << endl;
	swap_v(dx,dy);
	cout << dx << " " << dy << endl;
	
    return 0;
}

void swap_v(int a,int b) {
	int temp; temp = a; a=b; b=temp;
}
void swap_r(int& a,int& b) {
	int temp; temp = a; a=b; b=temp;
}
//void swap_cr(const int& a,const int& b) {
//	int temp; temp = a; a=b; b=temp;
//}
