/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090912, Pg. 169 # 14
 */

/**
 built to the specification in the book, which is remarkably user-unfriendly.
 just start typing a steady stream of day/number pairs, separated by spaces.  When
 you're done type exit and it'll go to town.
 
 example session:
 
 mon 12 tue 13 fri 4 mon 1 saturday 11 funions 12
 exit
 sunday:
     sum: 0
 monday:
     12
     1
     sum: 13
 tuesday:
     13
     sum: 13
 wednesday:
     sum: 0
 thursday:
     sum: 0
 friday:
     4
     sum: 4
 saturday:
     11
     sum: 11
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef enum {
	SUNDAY=0,
	MONDAY=1,
	TUESDAY=2,
	WEDNESDAY=3,
	THURSDAY=4,
	FRIDAY=5,
	SATURDAY=6
} WEEKDAYS;

string dayStrings[7][3] = {
	/*SUNDAY*/ {
		"sunday",
		"sun",
		"sun" // done to prevent undefined behavior
		// after the array bounds
	},
	/*MONDAY*/ {
		"monday",
		"mon",
		"m"
	},
	/*TUESDAY*/ {
		"tuesday",
		"tue",
		"tu"
	},
	/*WEDNESDAY*/ {
		"wednesday",
		"wed",
		"w"
	},
	/*THURSDAY*/ {
		"thursday",
		"thur",
		"th"
	},
	/*FRIDAY*/ {
		"friday",
		"fri",
		"f"
	},
	/*SATURDAY*/ {
		"saturday",
		"sat",
		"sat"
	}
};

vector< string* > * split(string * str, const char * token);

int main (int argc, char * const argv[]) {
	
	vector< vector<int>* > * input = new vector< vector<int>* >();
	for(size_t i=0;i<7;++i) input->push_back(new vector<int>());
	
	string * istring = new string();
	
	do {
		
		char * in = (char*)malloc(sizeof(char)*256);
		cin >> in;
		
		if(strcmp(in, "exit")==0) {
			free(in);
			break;
		} else {
			istring->append(in);
			istring->append(" ");
			free(in);
		}
		
	} while ( true ) ;
	
	vector< string* > * cuts = split(istring, " ");

	for(size_t i=0; i<cuts->size()-1; i+=2) {
		for(size_t dayidx=0; dayidx<7;++dayidx) {
			for(size_t varidx=0; varidx<3;++varidx) {
				if(((*cuts)[i])->compare(dayStrings[dayidx][varidx])==0) {
					// cuts[i+1] is to be added to input[dayidx]
					(*input)[dayidx]->push_back(atoi(((*cuts)[i+1])->c_str()));
					continue;
				}
			}
		}
		// should not be reachable if there is good input
		--i;
	}
	
	cout << "rejected values: " << input->size()/(cuts->size()/2) << endl;
	long total;
	for(size_t i=0; i<7;++i) {
		total=0;
		cout << dayStrings[i][0] << ":" << endl;
		for(size_t j=0;j<(*input)[i]->size();++j) {
			cout << "    " << (*(*input)[i])[j] << endl;
			total+=(*(*input)[i])[j];
		}
		cout << "    sum: " << total << endl;
	}
	
    return 0;
}

vector< string* > * split(string * str, const char * token) {
	vector< string* > * cuts = new vector< string* >();
	size_t term;
	for(size_t i=0; i<str->length();) {
		term = str->find(token, i);
				//cout << i << " " << term << '\n';
		cuts->push_back(new string(str->substr(i, term-i)));
		i=++term;
	}
	return cuts;
}
