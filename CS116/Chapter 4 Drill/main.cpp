/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090907, Chapter 4 Drills
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#define BUFFERSIZE 256

int main (int argc, char * const argv[]) {
    // insert code here...
	
	double large, small, i, k, sum;
	bool first=true;
	typedef enum {
		CENTIMETERS=0, METERS=1, INCHES=2, FEET=3
	} unitTypes;
	char units[4][3]={ "cm", "m", "in", "ft" };
	double conversion[4]/*to*/[4]={
		//		cm			m			in				ft
		{/*cm*/	1.0000000,	0.0100000,	0.393700787,	0.032808399},
		{/*m*/	100.00000,	1.0000000,	39.37007870,	3.280839900},
		{/*in*/	2.5400000,	0.0254000,	1.000000000,	0.083333333},
		{/*ft*/	30.480000,	0.3048000,	12.00000000,	1.000000000}
	};
	string *input, *tmp;
	vector<double> *history = new vector<double>();
	char *buffer;
	
	cout.setf(ios::fixed);
	while(true) {
		buffer = (char*)malloc(sizeof(char)*BUFFERSIZE);
		input = new string();
		cin >> buffer;
		input->append(buffer);
		free(buffer);

		if(!cin.good()) {
			cout << "not good" << endl;
			break;
		}
		if(input->empty()) {
			cout << "empty" << endl;
			break;
		}
		if(input->compare("exit")==0) {
			cout << "exit" << endl;
			break;
		}
		
		tmp = new string();
		for(size_t j=0; j<input->size();++j) {
			if(((*input)[j]>='0'&&(*input)[j]<='9')||
			   (*input)[j]=='.'||(*input)[j]=='-')
				tmp->append(1,(*input)[j]);
			else
				break;
		}
		i=atof(tmp->c_str());
		cout << *input << " ";
		if(input->find(units[CENTIMETERS])!=-1) {
			k = i*conversion[CENTIMETERS]/*to*/[METERS];
			cout << "(" << k << "m) ";
			if(first) {
				large = k;
				small = k;
				first = false;
			}
			if(k>large) {
				cout << "the largest so far";
				large = k;
			}
			if(k<small) {
				cout << "the smallest so far";
				small = k;
			}
			sum+=k;
			history->push_back(k);
		} else if(input->find(units[METERS])!=-1) {
			if(first) {
				large = i;
				small = i;
				first = false;
			}
			if(i>large) {
				cout << "the largest value so far";
				large = i;
			}
			if(i<small) {
				cout << "the smallest value so far";
				small = i;
			}
			sum+=i;
			history->push_back(i);
		} else if(input->find(units[FEET])!=-1) {
			k = i*conversion[FEET]/*to*/[METERS];
			cout << "(" << k << "m) ";
			if(first) {
				large = k;
				small = k;
				first = false;
			}
			if(k>large) {
				cout << "the largest so far";
				large = k;
			}
			if(k<small) {
				cout << "the smallest so far";
				small = k;
			}
			sum+=k;
			history->push_back(k);
		} else if(input->find(units[INCHES])!=-1) {
			k = i*conversion[INCHES]/*to*/[METERS];
			cout << "(" << k << "m) ";
			if(first) {
				large = k;
				small = k;
				first = false;
			}
			if(k>large) {
				cout << "the largest so far";
				large = k;
			}
			if(k<small) {
				cout << "the smallest so far";
				small = k;
			}
			sum+=k;
			history->push_back(k);
		} else {
			cout << "illegal value";
		}
		
		cout << endl;
		
		delete tmp;
		delete input;
		
	}
	
	sort(history->begin(), history->end());
	
	cout << "history: " << endl;
	for(size_t idx=0;
		idx < history->size();
		++idx) {
		cout << (*history)[idx] << "m" << endl;
	}
	cout << "sum: " << sum << "m" << endl;
	cout << "bye!" << endl;
	
	delete history;
	
    return 0;
}
