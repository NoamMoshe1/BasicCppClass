#ifndef __USER_H
#define __USER_H
#include "Address.h"
#include <string.h>
#include <iostream>

class User
{
public:
	User(
		const char* userName,
		const char* userPassword,
		const Address& address);
	User(const User& other);
	~User();
	void print() const;

private:
	char* userName;
	char* userPassword;
	Address address;
};

#endif // __USER_H