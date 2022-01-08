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
	friend std::ostream& operator<<(std::ostream& os, const User& user);

private:
	char* userName;
	char* userPassword;
	Address address;
};

#endif // __USER_H