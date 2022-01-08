#include "Costumer.h"

Costumer::Costumer(const User& user, int itemsSize) : 
	user(user), itemsAmount(0), itemsSize(itemsSize)
{
	this->items = new Item * [itemsSize];
}

Costumer::~Costumer()
{
	for (int i = 0; i < itemsAmount; i++)
	{
		delete items[i];
	}
	delete[] items;
}

bool Costumer::addProduct(Product* product, int retailerIndex)
{
	if (product == nullptr)
		return false;
	if (itemsAmount + 1 == itemsSize)
		if (resizeItems() == false)
			return false;
	Item* item = new Item();
	item->product = product;
	item->retailerIndex = retailerIndex;
	items[itemsAmount] = item;
	itemsAmount++;
	return true;
}

Order* Costumer::payment()
{
	Order* order = new Order(user, items, itemsAmount);
	removeItems();
	return order;
}

void Costumer::print() const
{
	std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Costumer& costumer)
{
	os << "Costumer: ";
	os << costumer.user;
	os << " Items: " << costumer.itemsAmount << " Items." << std::endl;
	double totalPrice = costumer.getTotalPrice();
	for (int i = 0; i < costumer.itemsAmount; i++)
	{
		os << i + 1 << ": " << " retailer ID: " << costumer.items[i]->retailerIndex << " ";
		costumer.items[i]->product->print();
	}
	os << "total price is: " << totalPrice << "NIS" << std::endl;
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

bool Costumer::resizeItems()
{
	Item** biggerItems = new Item * [2 * itemsSize];
	for (int i = 0; i < itemsAmount; i++)
		biggerItems[i] = items[i];
	itemsSize *= 2;
	delete[] items;
	items = biggerItems;
	return true;
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

