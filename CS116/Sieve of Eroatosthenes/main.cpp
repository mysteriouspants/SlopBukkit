/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090903, pg.128#13
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

#define MAX_NUMBER 300		// play with this to output more numbers
#define COLUMNS 15			// if you have a particularly small terminal you may
							// wish to decrease this number

#define PRIME      "PRIME"	// for best results these should
#define ELIMINATED " FAIL"	// all be the same length
#define UNTESTED   "  ???"

void describeTable(vector<char> * table);

int main (int argc, char * const argv[]) {
	
	vector<char> * n5rs = new vector<char>(MAX_NUMBER);
	for(size_t i=0;i<MAX_NUMBER;++i) (*n5rs)[i]='\0';
	
	// 2 is prime
	(*n5rs)[1]='p';
	for(size_t i=1;pow(i,2)<n5rs->size();++i) {
		if((*n5rs)[i]=='\0')
			(*n5rs)[i]='p';
		for(size_t j=i+i+1;j<n5rs->size();j+=i+1)
			(*n5rs)[j]='e';
	}
	// cleanup the rest of the vector, setting untested
	// indexes to show as not prime
	for(size_t i=sqrt(n5rs->size())-1;i<n5rs->size();++i)
		if((*n5rs)[i]=='\0')
			(*n5rs)[i]='p';
	
	cout << "Solution:" << endl;
	describeTable(n5rs);
	
	delete n5rs;
    return 0;
	
}

void describeTable(vector<char> * table) {
	cout << fixed << right;
	cout.precision(4);
	size_t w = (int)(log(MAX_NUMBER)/log(10)) + 1;
	if(w<strlen(PRIME))
		w = strlen(PRIME);
	for(size_t i=0;i<table->size();i+=COLUMNS) {
		for(size_t j=i;j<table->size()&&j<i+COLUMNS;++j) {
			cout.width(w);
			cout << j+1 << "  ";
		}
		cout << endl;
		for(size_t j=i;j<table->size()&&j<i+COLUMNS;++j) {
			cout.width(w);
			if((*table)[j]=='p')
				cout << PRIME;
			else if((*table)[j]=='e')
				cout << ELIMINATED;
			else
				cout << UNTESTED;
			cout << "  ";
		}
		cout << endl << endl;
	}
}
