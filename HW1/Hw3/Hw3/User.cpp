#include "User.h"

User::User(
	const char* userName,
	const char* userPassword,
	const Address& address) : address(address)
{
	this->userName = new char[strlen(userName) + 1];
	strcpy(this->userName, userName);
	this->userPassword = new char[strlen(userPassword) + 1];
	strcpy(this->userPassword, userPassword);
}

User::User(const User& other) : address(other.address)
{
	this->userName = new char[strlen(other.userName) + 1];
	strcpy(this->userName, other.userName);
	this->userPassword = new char[strlen(other.userPassword) + 1];
	strcpy(this->userPassword, other.userPassword);
}

User::~User()
{
	delete[] userName;
	delete[] userPassword;
}

void User::print() const
{
	std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << "User: " << user.userName
		<< ", password: " << user.userPassword << ", ";
	os << user.address;
	return os;
}

