#include "Costumer.h"

Costumer::Costumer(const User& user, int productSize) : user(user)
{
	this->products = new Product * [productSize];
	this->productsAmount = 0;
	this->productsSize = productSize;
}

Costumer::~Costumer()
{
	delete[] products;
}

bool Costumer::addProduct(Product* product)
{
	if (product == nullptr)
		return false;
	if (productsAmount + 1 == productsSize)
		if (resizeProducts() == false)
			return false;
	products[productsAmount] = product;
	productsAmount++;
	return true;
}

Order* Costumer::payment()
{
	Order* order = new Order(user, products, productsAmount);
	removeProducts();
	return order;
}

void Costumer::print() const
{
	std::cout << "Costumer: ";
	user.print();
	std::cout << "Products: " << productsAmount << " Products." << std::endl;
	double totalPrice = 0;
	for (int i = 0; i < productsAmount; i++)
	{
		std::cout << i + 1 << ": ";
		products[i]->print();
		totalPrice += products[i]->getPrice();
	}
	std::cout << "total price is: " << totalPrice << "NIS" << std::endl;
}

bool Costumer::resizeProducts()
{
	Product** biggerProducts = new Product * [2 * productsSize];
	for (int i = 0; i < productsAmount; i++)
		biggerProducts[i] = products[i];
	productsSize *= 2;
	delete[] products;
	products = biggerProducts;
	return true;
}

bool Costumer::removeProducts()
{
	this->products = new Product * [this->productsSize];
	this->productsAmount = 0;
	return true;
}
