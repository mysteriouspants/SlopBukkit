/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091003, Ch. 10 Asgn
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>
#include <algorithm>

const int not_a_reading= -7777;
const int not_a_month = -1;
const int implausible_min = -200;
const int implausible_max = 200;
std::vector<std::string> month_input_tbl;
std::vector<std::string> month_print_tbl;

struct Day {
	std::vector<double> hour;
	Day();
	double mean();
	std::vector<double>& populate_reading_vector();
};

struct Month {
	int month;
	std::vector<Day> day;
	Month()
	:month(not_a_month), day(32) {
		
	}
	double mean();
	std::vector<double>& populate_reading_vector();
};

struct Year {
	int year;
	std::vector<Month> month;
	Year() :month(12) {
		
	}
	double mean();
	std::vector<double>& populate_reading_vector();
};

struct Reading {
	int day;
	int hour;
	double temperature;
};

bool is_valid(const Reading& r);
void end_of_loop(std::istream& ist, char term, const std::string& message);
void init_input_tbl(std::vector<std::string>& tbl);
void init_print_tbl(std::vector<std::string>& tbl);
int month_to_int(std::string s);
std::string int_to_month(int i);
bool all_blank(const Month& m);

std::istream& operator >> (std::istream& is, Reading& r);
std::istream& operator >> (std::istream& is, Month& m);
std::istream& operator >> (std::istream& is, Year& y);

std::ostream& operator << (std::ostream& os, Reading& r);
std::ostream& operator << (std::ostream& os, Month& m);
std::ostream& operator << (std::ostream& os, Year& y);

int main (int argc, char * const argv[]) {

	/*
	 Write a program that creates a file of data in the form of the temperature
	 Reading type defined in §10.11. Fill the file with at least 50 temperature
	 readings. DONE
	 
	 Call this program store_temps.cpp and the file it creates raw_temps.txt.
	 
	 Write a program that reads the data from raw_temps.txt into a vector and
	 then calculates the mean and median temperatures in your data set.
	 
	 Call this program temp_stats.cpp.
	 
	 Modify the store_temps.cpp program to include a temperature suffix c for
	 Celsius or f for Fahrenheit temperatures. Then modify the temp_stats.cpp
	 program to test each temperature; converting the Celsius readings to
	 Fahrenheit before putting them into the vector.
	 */
	
	std::cout << argv[0] << std::endl;
	
	init_print_tbl(month_print_tbl);
	init_input_tbl(month_input_tbl);
	
	std::vector<Year> y_input= std::vector<Year>();
	std::vector<double> all_readings= std::vector<double>();
	std::ifstream ifs("../../raw_temps.txt");
	if(!ifs) {
		std::cerr << "cannot open file!" << std::endl;
		throw std::runtime_error("cannot open file!");
	}
	std::cout << "Program: " << std::endl;
	Year y;
	while(ifs >> y) {
		std::cout << y;
		std::cout << "Year "<< y.year << " mean reading: " << y.mean() << std::endl;
		all_readings = y.populate_reading_vector();
		std::sort(all_readings.begin(), all_readings.end());
		std::cout << "Mean reading for " << y.year << " " << all_readings[all_readings.size()/2] << std::endl;
		y_input.push_back(y);
	}
	
	std::cout << std::endl << "File: " << std::endl;
	ifs.close();
	ifs.open("../../raw_temps.txt");
	std::string in;
	while(ifs >> in) std::cout << in << ' ';
	
//	for(size_t i=0; i < y_input.size(); ++i) {
//		std::cout << "Year " << y_input[i].year << " mean reading: " << y_input[i].mean() << std::endl;
//	}
	
//	std::cout << "Program: " << std::endl;
//	for(size_t i=0; i<y_input.size(); ++i) {
//		std::cout << y_input[i];
//	}
	
    return 0;
}

Day::Day()
: hour(24) {
	for (size_t i = 0; i<hour.size(); ++i) hour[i]=not_a_reading;
}

double Day::mean() {
	double sum=0.0; int r=0;
	for(size_t i=0; i < hour.size(); ++i) {
		sum += (hour[i]==not_a_reading)?0.0:hour[i];
		r+=(hour[i]==not_a_reading)?0:1;
	}
	return sum/r;
}

double Month::mean() {
	double sum=0.0;
	for(size_t i=0; i < day.size(); ++i) {
		sum += day[i].mean();
	}
	return sum/day.size();
}

double Year::mean() {
	double sum=0.0;
	for(size_t i=0; i < month.size(); ++i)
		sum+=month[i].mean();
	return sum/month.size();
}

std::vector<double>& Year::populate_reading_vector() {
	std::vector<double> toReturn= std::vector<double>();
	for(size_t i = 0; i < month.size(); ++i) {
		std::vector<double> tmp=month[i].populate_reading_vector();
		toReturn.insert(toReturn.end(), tmp.begin(), tmp.end());
	}
	return *(new std::vector<double>(toReturn.begin(), toReturn.end()));
}

std::vector<double>& Month::populate_reading_vector() {
	std::vector<double> toReturn= std::vector<double>();
	for(size_t i=0; i < day.size(); ++i) {
		std::vector<double> tmp=day[i].populate_reading_vector();
		toReturn.insert(toReturn.end(), tmp.begin(), tmp.end());
	}
	return *(new std::vector<double>(toReturn.begin(), toReturn.end()));
}

std::vector<double>& Day::populate_reading_vector() {
	std::vector<double> toReturn= std::vector<double>();
	for(size_t i=0; i < hour.size(); ++i) {
		if(hour[i]!=not_a_reading)
			toReturn.push_back(hour[i]);
	}
	return *(new std::vector<double>(toReturn.begin(), toReturn.end()));
}

bool is_valid(const Reading& r) {
	if(r.day<1||31<r.day) return false;
	if(r.hour<0||23<r.hour) return false;
	if(r.temperature<implausible_min||implausible_max<r.temperature)
		return false;
	return true;
}
void end_of_loop(std::istream& ist, char term, const std::string& message) {
	if(ist.fail()) {
		ist.clear();
		char ch;
		if(ist>>ch && ch==term) return;
		std::cerr << message << std::endl;
		throw std::runtime_error(message);
	}
}
void init_input_tbl(std::vector<std::string>& tbl) {
	tbl.push_back("jan");
	tbl.push_back("feb");
	tbl.push_back("mar");
	tbl.push_back("apr");
	tbl.push_back("may");
	tbl.push_back("jun");
	tbl.push_back("jul");
	tbl.push_back("aug");
	tbl.push_back("sep");
	tbl.push_back("oct");
	tbl.push_back("nov");
	tbl.push_back("dec");
}
void init_print_tbl(std::vector<std::string>& tbl) {
	tbl.push_back("January");
	tbl.push_back("February");
	tbl.push_back("March");
	tbl.push_back("April");
	tbl.push_back("May");
	tbl.push_back("June");
	tbl.push_back("July");
	tbl.push_back("August");
	tbl.push_back("September");
	tbl.push_back("October");
	tbl.push_back("November");
	tbl.push_back("December");
}
int month_to_int(std::string s) {
	for(int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
	return -1;
}
std::string int_to_month(int i) {
	if(i<0||12<=i) {
		std::cerr << "bad month index" << std::endl;
		throw std::runtime_error("bad month index");
	}
	return month_print_tbl[i];
}
bool all_blank(const Month& m) {
	bool all_blank=true;
	for(size_t i=0; i < m.day.size(); ++i) {
		for(size_t j=0; j < m.day[i].hour.size(); ++j)
			if(m.day[i].hour[j]!=not_a_reading) {
				all_blank=false;
				break;
			}
		if(all_blank==false)
			break;
	}
	return all_blank;
}

std::istream& operator >> (std::istream& is, Reading& r) {
	char ch1;
	if(is>>ch1 &&ch1!='(') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}
	
	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if(!is || ch2!=')') {
		std::cerr << "Error: messed up reading!" << std::endl;
		throw std::runtime_error("messed up reading!");
	}
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

std::istream& operator >> (std::istream& is, Month& m) {
	char ch=0;
	if(is >> ch && ch!='{') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}
	
	std::string month_marker;
	std::string mm;
	is >> month_marker >> mm;
	if(!is || month_marker!="month") {
		std::cerr << "Error: bad start of month!" << std::endl;
		throw std::runtime_error("messed up month marker!");
	}
	m.month = month_to_int(mm);
	
	Reading r;
	int duplicates = 0;
	int invalids = 0;
	while(is>>r) {
		if(is_valid(r)) {
			if(m.day[r.day].hour[r.hour] != not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else {
			++invalids;
		}
	}
	if(invalids) {
		std::cerr << "invalid readings in month " << invalids << std::endl;
		throw std::runtime_error("invalid readings in month");
	}
	if(duplicates) {
		std::cerr << "duplicate readings in month " << duplicates << std::endl;
		throw std::runtime_error("duplicate readings in month");
	}
	end_of_loop(is,'}',"bad end of month");
	return is;
}

std::istream& operator >> (std::istream& is, Year& y) {
	char ch;
	is >> ch;
	if(ch!='{') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}
	
	std::string year_marker;
	int yy;
	is >> year_marker >> yy;
	if(!is || year_marker!="year") {
		std::cerr << "bad start of year" << std::endl;
		throw std::runtime_error("bad start of year");
	}
	y.year = yy;
	
	while(true) {
		Month m;
		if(!(is >> m)) break;
		y.month[m.month] = m;
	}
	
	end_of_loop(is,'}',"bad end of year");
	return is;
}

std::ostream& operator << (std::ostream& os, Reading& r) {
	
	os << "( " << r.day << ' ' << r.hour << ' ' << r.temperature << " )";
	
	return os;
}

std::ostream& operator << (std::ostream& os, Month& m) {
	
	if(all_blank(m))
		return os;
	
	os << "{ month " << month_input_tbl[(m.month>-1&&m.month<12)?m.month:0] << ' ';
	Reading r;
	for(size_t i=0; i < m.day.size(); ++i) {
		Day d = m.day[i];
		for(size_t j=0; j<d.hour.size(); ++j) {
			if(d.hour[j]==not_a_reading)
				continue;
			r.day = i;
			r.hour = j;
			r.temperature = d.hour[j];
			os << r << ' ';
		}
	}
	os << '}';
	
	return os;
}

std::ostream& operator << (std::ostream& os, Year& y) {
	
	os << "{ year " << y.year << ' ';
	for(size_t i=0; i<y.month.size(); ++i) {
		if(all_blank(y.month[i]))
			continue;
		os << y.month[i] << " ";
	}
	os << '}';
	
	return os;
}
