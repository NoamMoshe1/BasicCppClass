#include "Address.h"

Address::Address(
	const char* street,
	const int buildingNumber,
	const char* city,
	const char* state)
{
	this->street = new char[strlen(street) + 1];
	strcpy(this->street, street);
	this->buildingNumber = buildingNumber;
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);
	this->state = new char[strlen(state) + 1];
	strcpy(this->state, state);
}

Address::Address(const Address& other) 
{
	this->street = new char[strlen(other.street) + 1];
	strcpy(this->street, other.street);
	this->buildingNumber = other.buildingNumber;
	this->city = new char[strlen(other.city) + 1];
	strcpy(this->city, other.city);
	this->state = new char[strlen(other.state) + 1];
	strcpy(this->state, other.state);
}

Address::~Address()
{
	delete[] street;
	delete[] city;
	delete[] state;
}

void Address::print() const
{
	std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Address& address)
{
	os << "Address: " << address.street
		<< ", " << address.buildingNumber
		<< ", " << address.city
		<< ", " << address.state << std::endl;
	return os;
}