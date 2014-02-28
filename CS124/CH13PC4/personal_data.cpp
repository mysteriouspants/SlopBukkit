#include "personal_data.hpp"

PersonalData::PersonalData() : _name(""), _address(""), _age(0), _phone_number("") { }

PersonalData::PersonalData(
	std::string& name,
	std::string& address,
	unsigned int age,
	std::string& phone_number)
: _name(name), _address(address), _age(age), _phone_number(phone_number)
{ }

std::string PersonalData::getName() const {
	return _name;
}
void PersonalData::setName(std::string&& name) {
	_name = name;
}

std::string PersonalData::getAddress() const {
	return _address;
}
void PersonalData::setAddress(std::string&& address) {
	_address = address;
}

unsigned int PersonalData::getAge() const {
	return _age;
}
void PersonalData::setAge(unsigned int age) {
	_age = age;
}

std::string PersonalData::getPhoneNumber() const {
	return _phone_number;
}
void PersonalData::setPhoneNumber(std::string&& phone_number) {
	_phone_number = phone_number;
}