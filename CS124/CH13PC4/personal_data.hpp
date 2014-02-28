#include <string>

class PersonalData {
	std::string _name;
	std::string _address;
	unsigned int _age;
	std::string _phone_number;
public:
	PersonalData();
	PersonalData(std::string&,std::string&,unsigned int,std::string&);

	std::string getName() const;
	void setName(std::string&&);

	std::string getAddress() const;
	void setAddress(std::string&&);

	unsigned int getAge() const;
	void setAge(unsigned int);

	std::string getPhoneNumber() const;
	void setPhoneNumber(std::string&&);
};