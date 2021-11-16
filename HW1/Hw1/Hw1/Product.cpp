#include "Product.h"

const char* categoryStr[] = { "Children",
		"Electricity",
		"Office",
		"Clothing" };

Product::Product(Category category,
	const char* name,
	double price)
{
	this->category = category;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->price = price;
}

Product::~Product()
{
	delete[] name;
}

void Product::print() const
{
	std::cout << "Product: " << name
		<< ", Category: " << categoryStr[(int)category] 
		<< ", Price: " << price << "NIS" << std::endl;
}

double Product::getPrice() const
{
	return price;
}
