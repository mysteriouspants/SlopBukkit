#include <iostream>
#include <vector>
#include <stdio.h>
#include "personal_data.hpp"

static size_t number_of_persons = 3;

std::ostream& operator<<(std::ostream&,const PersonalData&);

int main(int argc, const char* argv[]) {

	std::vector<PersonalData> personal_data(number_of_persons);

	for(size_t i=0; i < number_of_persons; ++i) {
		std::cout << "Entering information for person " << i << std::endl;
		std::string name, address, phone_number; unsigned int age;
		std::cout << "Enter a name for this person: ";
		std::getline(std::cin, name);

		std::cout << "Enter an address for this person: ";
		std::getline(std::cin, address);

		std::cout << "Enter an age for this person: ";
		std::cin >> age;
		std::cin.ignore();

		std::cout << "Enter a phone number for this person: ";
		std::getline(std::cin, phone_number);

		personal_data[i] = PersonalData(name,address,age,phone_number);
	}


	std::cout << std::endl << "All persons:" << std::endl;
	for(size_t i=0; i < number_of_persons; ++i) {
		std::cout << "  " << personal_data[i] << std::endl;
	}

	return 0;
}

std::ostream& operator<<(std::ostream& os,const PersonalData& pd) {
	os << "<PersonalData name:'" << pd.getName() << "' address:'" << pd.getAddress() << "' age:" << pd.getAge() << " phone_number:'" << pd.getPhoneNumber() << "'>";
	return os;
}