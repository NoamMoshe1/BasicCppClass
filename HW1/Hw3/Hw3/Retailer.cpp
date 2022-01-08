#include "Retailer.h"

Retailer::Retailer(const User& user, int productSize) : user(user)
{
	this->products = new Product*[productSize];
	this->productsAmount = 0;
	this->productsSize = productSize;
}

Retailer::~Retailer()
{
	delete[] products;
}

bool Retailer::addProduct(Product* product)
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

Product* Retailer::getProduct(int productId)
{
	for (int i = 0; i < productsAmount; i++)
	{
		if(products[i]->getId() == productId)
			return products[i];
	}
	return nullptr;
}

void Retailer::print() const
{
	std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Retailer& retailer)
{
	os << "Retailer: ";
	os << retailer.user;
	os << " Products: " << std::endl;
	for (int i = 0; i < retailer.productsAmount; i++)
	{
		os << i << ": ";
		retailer.products[i]->print();
	}
	return os;
}

bool Retailer::resizeProducts()
{
	Product** biggerProducts = new Product*[2*productsSize];
	for (int i = 0; i < productsAmount; i++)
		biggerProducts[i] = products[i];
	productsSize *= 2;
	delete[] products;
	products = biggerProducts;
	return true;
}
