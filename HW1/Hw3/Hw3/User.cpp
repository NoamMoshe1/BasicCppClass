#include "User.h"

User::User(
	const char* userName,
	const char* userPassword,
	const Address& address,
	int itemsSize) : address(address), itemsAmount(0), itemsSize(itemsSize)
{
	this->userName = new char[strlen(userName) + 1];
	strcpy(this->userName, userName);
	this->userPassword = new char[strlen(userPassword) + 1];
	strcpy(this->userPassword, userPassword);

	this->items = new Item * [itemsSize];
}

User::User(const User& other) : address(other.address)
{
	this->userName = new char[strlen(other.userName) + 1];
	strcpy(this->userName, other.userName);
	this->userPassword = new char[strlen(other.userPassword) + 1];
	strcpy(this->userPassword, other.userPassword);
	this->items = nullptr;
	this->itemsAmount = 0;
	this->itemsSize = 0;
}


User::~User()
{
	delete[] userName;
	delete[] userPassword;

	for (int i = 0; i < itemsAmount; i++)
	{
		delete items[i];
	}
	delete[] items;
}

void User::print() const
{
	print(std::cout);
}

void User::print(std::ostream& os) const
{
	os << "User: " << userName
		<< ", password: " << userPassword << ", ";
	os << address;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	user.print(os);

	return os;
}

bool User::addProduct(Product* product, int retailerIndex)
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

Product* User::getProduct(int productId)
{
	for (int i = 0; i < itemsAmount; i++)
	{
		if (items[i]->product->getId() == productId)
			return items[i]->product;
	}
	return nullptr;
}

bool User::resizeItems()
{
	Item** biggerItems = new Item * [2 * itemsSize];
	for (int i = 0; i < itemsAmount; i++)
		biggerItems[i] = items[i];
	itemsSize *= 2;
	delete[] items;
	items = biggerItems;
	return true;
}

bool User::removeItems()
{
	items = new Item * [itemsSize];
	itemsAmount = 0;
	return true;
}
