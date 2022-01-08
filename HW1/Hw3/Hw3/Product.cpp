#include "Product.h"

Product::Product(int id,
	Category category,
	const char* name,
	double price) : 
	category(category),
	price(price),
	id(id)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Product::~Product()
{
	delete[] name;
}

void Product::print(std::ostream& os) const
{
	os << "Product " << id << ": " << name
		<< ", Category: " << categoryStr[(int)category] 
		<< ", Price: " << price << "NIS" << std::endl;
}

void Product::print() const
{
	print(std::cout);
}

std::ostream& operator<<(std::ostream& os, const Product& product)
{
	product.print(os);
	return os;
}

double Product::getPrice() const
{
	return price;
}

int Product::getId() const
{
	return id;
}
