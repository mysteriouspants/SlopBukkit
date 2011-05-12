/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           8
 Date Due:               20 November 2008
 Date Submitted:         20 November 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3,GCC 4.2.0, x86
 File Name:              main.cpp
*/
#include <iostream>
#include <vector>
#include <cstdlib>

struct Floor {
	int floor_num, rooms, occupied;
};

struct Hotel {
	// number of floors is equal to floors.size()
	bool has_thirteenth;
	std::vector<Floor> *floors;
};

int get_int(int min, int max);
bool get_bool();
void print_pad(int num);

int main (int argc, char * const argv[]) {
	std::cout << "Hotel Electronic Booking System" << std::endl << std::endl;
	Hotel this_hotel;
	std::cout << "Please answer some questions about your hotel." << std::endl;
		
	std::cout << "How many floors do you have? ";
	this_hotel.floors=new std::vector<Floor>(get_int(0, 32000));
		
	if((*(this_hotel.floors)).size()>=13) {
		std::cout << "Do you have a thirteenth floor? ";
		this_hotel.has_thirteenth=get_bool();
	}
		
	for(int i=0;i!=(*(this_hotel.floors)).size();++i) {
		if(!this_hotel.has_thirteenth&&i==12)
			continue;
		Floor this_floor;
		this_floor.floor_num=i+1;
		std::cout << "How many rooms are on floor " << i+1 << "? ";
		this_floor.rooms=get_int(0, 500);
		std::cout << "How many rooms are occupied on floor " << i+1 << "? ";
		this_floor.occupied=get_int(0, this_floor.rooms);
		(*(this_hotel.floors))[i]=this_floor;
	}
	
	std::vector<Floor>::iterator iter;
	
	std::cout.width(2);
	std::cout.flags(std::ios::internal);
	
	std::cout << "Hotel Occupancy by Floor:" << std::endl;
	for( iter=(*(this_hotel.floors)).begin();iter<(*(this_hotel.floors)).end();iter++ ) {
		Floor fl=*iter;
		std::cout << "  Floor " << fl.floor_num << " has " << fl.rooms << " rooms ";
		std::cout << "of which " << fl.occupied << " are in use.";
		std::cout << "  There are " << fl.rooms-fl.occupied << " rooms free, or ";
		std::cout.precision(4);
		std::cout << (static_cast<float> (fl.occupied)/static_cast<float>(fl.rooms))*100.0F << "% occupancy.";
		std::cout << std::endl;
	}
	
	std::cout << "Total Hotel Occupancy:" << std::endl;
	std::cout << "  " << (*(this_hotel.floors)).size();
	print_pad((*(this_hotel.floors)).size());
	std::cout << " total floors in hotel" << std::endl;
	std::cout << "  ";
	int total_rooms=0,total_occupied=0;
	for ( iter=(*(this_hotel.floors)).begin();iter<(*(this_hotel.floors)).end();iter++ ) {
		total_rooms+=(*iter).rooms;
		total_occupied+=(*iter).occupied;
	}
	std::cout << total_rooms;
	print_pad(total_rooms);
	std::cout << " total rooms in this hotel." << std::endl;
	std::cout << "  " << total_occupied;
	print_pad(total_occupied);
	std::cout << " number of occupied rooms in this hotel." << std::endl;
	std::cout << "  " << total_rooms-total_occupied;
	print_pad(total_rooms-total_occupied);
	std::cout << " number of available rooms in this hotel." << std::endl;
	std::cout << "  " << (static_cast<float>(total_occupied)/static_cast<float>(total_rooms))*100.0F <<
		"% global hotel occupancy." << std::endl;
	
    // insert code here...
    char throwaway;
	std::cout << "Press the any key to continue\r\n";
	std::cin.get(throwaway);
    return 0;
}

int get_int(int min, int max) {
	int tmp;
	do {
		std::cin >> tmp;
		if(tmp<min||tmp>max){
			std::cout << "I'm sorry, but your input is invalid.  You must input a ";
			std::cout << "number between " << min << " and " << max << "!" << std::endl;
		} else {
			return tmp;
		}
	} while ( true ) ;
}

bool get_bool() {
	int tmp;
	std::cout << "Please enter a number.  Anything greater than zero will be interpreted as true." << std::endl;
	std::cin >> tmp;
	if(tmp>0)return true;
	else return false;
	/*
	 char *tmp;
	 do { // uncomment if you think your implementation of iostream and cstdlib is more
			// standard than the implementation I was using.  This failed fantastically
		std::cin >> tmp;
		// convert to upper case
		for(int i=0;i!=sizeof(tmp)/sizeof(char);++i)
			if(tmp[i]>='a'&&tmp[i]<='z')tmp[i]-='a'-'A';
		if(strcmp(tmp,"TRUE")||strcmp(tmp,"YES")||strcmp(tmp,"Y")) {
			return true;
		}
		if(strcmp(tmp,"FALSE")||strcmp(tmp,"NO")||strcmp(tmp,"N")) {
			return false;
		}
		// else continue and ask again
		std::cout << "I'm sorry, but your input is not valid.  You must input ";
		std::cout << "either 'true', 'false', 'yes', 'no', 'y', or 'n'." << std::endl;
	} while ( true ) ;*/
}

void print_pad(int num) {
	if(num<9) std::cout << " ";
	if(num<99) std::cout << " ";
	if(num<999) std::cout << " ";
}

/*
 Hotel Electronic Booking System
 
 Please answer some questions about your hotel.
 How many floors do you have? 3
 How many rooms are on floor 1? 3
 How many rooms are occupied on floor 1? 4
 I'm sorry, but your input is invalid.  You must input a number between 0 and 3!
 3
 How many rooms are on floor 2? 2
 How many rooms are occupied on floor 2? 2
 How many rooms are on floor 3? 5
 How many rooms are occupied on floor 3? 4
 Hotel Occupancy by Floor:
 Floor 1 has 3 rooms of which 3 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 2 has 2 rooms of which 2 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 3 has 5 rooms of which 4 are in use.  There are 1 rooms free, or 80% occupancy.
 Total Hotel Occupancy:
 3    total floors in hotel
 10   total rooms in this hotel.
 9   number of occupied rooms in this hotel.
 1    number of available rooms in this hotel.
 90% global hotel occupancy.
 Press the any key to continue
 Hotel Electronic Booking System
 
 Please answer some questions about your hotel.
 How many floors do you have? 14
 Do you have a thirteenth floor? Please enter a number.  Anything greater than zero will be interpreted as true.
 0
 How many rooms are on floor 1? 1
 How many rooms are occupied on floor 1? 1
 How many rooms are on floor 2? 1
 How many rooms are occupied on floor 2? 1
 How many rooms are on floor 3? 1
 How many rooms are occupied on floor 3? 1
 How many rooms are on floor 4? 1
 How many rooms are occupied on floor 4? 1
 How many rooms are on floor 5? 1
 How many rooms are occupied on floor 5? 1
 How many rooms are on floor 6? 1
 How many rooms are occupied on floor 6? 1
 How many rooms are on floor 7? 1
 How many rooms are occupied on floor 7? 1
 How many rooms are on floor 8? 1
 How many rooms are occupied on floor 8? 1
 How many rooms are on floor 9? 1
 How many rooms are occupied on floor 9? 1
 How many rooms are on floor 10? 1
 How many rooms are occupied on floor 10? 1
 How many rooms are on floor 11? 1
 How many rooms are occupied on floor 11? 1
 How many rooms are on floor 12? 1
 How many rooms are occupied on floor 12? 1
 How many rooms are on floor 14? 1
 How many rooms are occupied on floor 14? 1
 Hotel Occupancy by Floor:
 Floor 1 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 2 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 3 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 4 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 5 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 6 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 7 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 8 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 9 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 10 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 11 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 12 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Floor 0 has 0 rooms of which 0 are in use.  There are 0 rooms free, or nan% occupancy.
 Floor 14 has 1 rooms of which 1 are in use.  There are 0 rooms free, or 100% occupancy.
 Total Hotel Occupancy:
 14   total floors in hotel
 13   total rooms in this hotel.
 13   number of occupied rooms in this hotel.
 0    number of available rooms in this hotel.
 100% global hotel occupancy.
 Press the any key to continue 
*/


