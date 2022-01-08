#include "Retailer.h"

Retailer::Retailer(const char* userName,
	const char* userPassword,
	const Address& address)
	: User(userName, userPassword, address)
{}

Retailer::~Retailer()
{}

void Retailer::print(std::ostream& os) const
{
	os << "Retailer: ";
	User::print(os);
	os << " Products: " << std::endl;
	for (int i = 0; i < itemsAmount; i++)
	{
		os << i << ": ";
		items[i]->product->print(os);
	}
}

std::ostream& operator<<(std::ostream& os, const Retailer& retailer)
{
	retailer.print(os);
	return os;
}