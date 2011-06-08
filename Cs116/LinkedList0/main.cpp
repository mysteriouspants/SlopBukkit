/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091207, Chapter 17 Assignment
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "GenericStruct.h"
#include "Link.h"

int main (int argc, char * const argv[]) {
	
	using namespace std;
	using namespace fsdev;
	
	srand( time( NULL ) );
	
	vector<string> names;
	names.push_back("Chris");
	names.push_back("Von");
	names.push_back("David");
	names.push_back("Na'ama");
	names.push_back("Jesus");
	names.push_back("Pablo");
	names.push_back("George");
	names.push_back("Adrian");
	names.push_back("Michael");
	names.push_back("Jon");
	
	vector<string> jobs;
	jobs.push_back("Unemployed");
	jobs.push_back("Teacher");
	jobs.push_back("Student");
	jobs.push_back("Programmer");
	
	vector<string> status;
	status.push_back("bored");
	status.push_back("working");
	status.push_back("sleeping");
	status.push_back("planning world domination");
	
	vector<string> other;
	other.push_back("other0");
	other.push_back("other1");
	other.push_back("other2");
	
	Link root(GenericStruct(names[rand()%names.size()],
							jobs[rand()%jobs.size()],
							status[rand()%status.size()],
							other[rand()%other.size()])
					 );
	
	for(size_t i=0; i!=10; ++i) {
		root.add_ordered(GenericStruct(names[rand()%names.size()],
									   jobs[rand()%jobs.size()],
									   status[rand()%status.size()],
									   other[rand()%other.size()])
						 );
	}
	
	cout << "Unsorted people: " << endl;
	root.print_all();
	
	Link * unemployed = NULL;
	Link * teachers = NULL;
	Link * students = NULL;
	Link * programmers = NULL;
	
	Link * cursor = &root;
	
	do {
		
		if(cursor->data.str1==jobs[0])
			if(unemployed==NULL)
				unemployed = new Link(cursor->data);
			else
				unemployed->add_ordered(cursor->data);
		else if(cursor->data.str1==jobs[1])
			if(teachers==NULL)
				teachers = new Link(cursor->data);
			else 
				teachers->add_ordered(cursor->data);
		else if(cursor->data.str1==jobs[2])
			if(students==NULL)
				students = new Link(cursor->data);
			else
				students->add_ordered(cursor->data);
		else
			if(programmers==NULL)
				programmers = new Link(cursor->data);
			else
				programmers->add_ordered(cursor->data);
		
		cursor = cursor->next;
	} while (cursor != NULL);
	
	cout << endl << "Sorted by job: " << endl;
	
	cout << "Unemployed: " << endl;
	if(unemployed!=NULL)
		unemployed->print_all();
	else
		cout << "No unemployed people.  Hooray Obama!" << endl;

	cout << endl << "Teachers: " << endl;
	if(teachers!=NULL)
		teachers->print_all();
	else
		cout << "No teachers.  Boo Obama!" << endl;
	
	cout << endl << "Students: " << endl;
	if(students!=NULL)
		students->print_all();
	else
		cout << "No students.  Have they all become teachers?" << endl;
	
	cout << endl << "Programmers: " << endl;
	if(programmers!=NULL)
		programmers->print_all();
	else
		cout << "Oh no, no more programmers!  Curse you outsourcing!" << endl;
	
    return 0;
}
