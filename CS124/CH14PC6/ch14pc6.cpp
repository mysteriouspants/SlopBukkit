/*! Chris Miller (imperator@pax-imperia.com), CS124
 *! Copyright (C) 2014 Chris Miller.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20140307, Chapter 14 Programming Challenge 6
 */

#include <iostream>
#include <string>
#include "num_days.hpp"
#include "time_off.hpp"
using namespace std;

int main(int args, const char* argv[]) {
	size_t months_worked;
	size_t id;
	string name;

	cout << "Please enter employee id: ";
	cin >> id;

	cout << "Please enter the employee name: ";
	cin.ignore();
	getline(cin,name);

	cout << "Please enter the number of months worked: ";
	cin >> months_worked;

	TimeOff t(id,name,8*months_worked,0,12*months_worked,0,0,0);

	cout << "Maximum sick leave days: " << t.getMaxSickDays().getDays() << endl;
	cout << "Maximum vacation days:   " << t.getMaxVacation().getDays() << endl;

	return 0;	
}