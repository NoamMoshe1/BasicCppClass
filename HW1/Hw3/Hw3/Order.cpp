#include "Order.h"

Order::Order(const User& user,
	Item** items,
	int itemsAmount) : 
	user(user), items(items), itemsAmount(itemsAmount)
{}

Order::~Order()
{
	for (int i = 0; i < itemsAmount; i++)
	{
		delete items[i];
	}
	delete[] items;
}

void Order::print() const
{
	std::cout << "Order: " << itemsAmount << " Items." << std::endl;
	double totalPrice = 0;
	for (int i = 0; i < itemsAmount; i++)
	{
		std::cout << i + 1 << ": " << "retailer ID: " << items[i]->retailerIndex;
		items[i]->product->print();
		totalPrice += items[i]->product->getPrice();
	}
	std::cout << "total price is: " << totalPrice << "NIS" << std::endl;
}