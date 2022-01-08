#include "Costumer.h"

Costumer::Costumer(const char* userName,
	const char* userPassword,
	const Address& address)
	: User(userName, userPassword, address)
{}

Costumer::~Costumer()
{}

Order* Costumer::payment()
{
	Order* order = new Order(*this, items, itemsAmount);
	removeItems();
	return order;
}

void Costumer::print(std::ostream& os) const
{
	os << "Costumer: ";
	User::print(os);
	os << " Items: " << itemsAmount << " Items." << std::endl;
	double totalPrice = getTotalPrice();
	for (int i = 0; i < itemsAmount; i++)
	{
		os << i + 1 << ": " << " retailer ID: " << items[i]->retailerIndex << " ";
		items[i]->product->print(os);
	}
	os << "total price is: " << totalPrice << "NIS" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Costumer& costumer)
{
	costumer.print(os);
	return os;
}

double Costumer::getTotalPrice() const
{
	double totalPrice = 0;
	for (int i = 0; i < itemsAmount; i++)
	{
		totalPrice += items[i]->product->getPrice();
	}
	return totalPrice;
}

bool Costumer::removeItems()
{
	items = new Item *[itemsSize];
	itemsAmount = 0;
	return true;
}

bool Costumer::operator< (const Costumer& rhs) const
{
	return this->getTotalPrice() < rhs.getTotalPrice();
}

bool Costumer::operator> (const Costumer& rhs) const
{
	return rhs < *this;
}

bool Costumer::operator==(const Costumer& rhs) const
{
	return (this->getTotalPrice() == rhs.getTotalPrice());
}

bool Costumer::operator!= (const Costumer& rhs) const
{
	return !(*this == rhs);
}

