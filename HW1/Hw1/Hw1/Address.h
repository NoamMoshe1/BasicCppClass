#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <string.h>
#include <iostream>

class Address
{
public:
	Address(
		const char* street,
		const int buildingNumber,
		const char* city,
		const char* state);
	Address(const Address& other);
	~Address();
	void print() const;
	//TODO do we need more functions?

private:
	char* street;
	int buildingNumber;
	char* city;
	char* state;
	
};

#endif // __ADDRESS_H