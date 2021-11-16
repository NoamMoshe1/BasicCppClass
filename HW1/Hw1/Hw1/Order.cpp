#include "Order.h"

Order::Order(const User& user,
	Product** products,
	int productsAmount) : user(user)
{
	this->products = products;
	this->productsAmount = productsAmount;
}

Order::~Order()
{
	for (int i = 0; i < productsAmount; i++)
		delete products[i];
	delete[] products;
}

void Order::print() const
{
	std::cout << "Order: " << productsAmount << "Products." << std::endl;
	double totalPrice = 0;
	for (int i = 0; i < productsAmount; i++)
	{
		std::cout << i + 1 << ": ";
		products[i]->print();
		totalPrice += products[i]->getPrice();
	}
	std::cout << "total price is: " << totalPrice << "NIS" << std::endl;
}