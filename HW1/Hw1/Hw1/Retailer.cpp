#include "Retailer.h"

Retailer::Retailer(const User& user, int productSize) : user(user)
{
	this->products = new Product*[productSize];
	this->productsAmount = 0;
	this->productsSize = productSize;
}

Retailer::~Retailer()
{
	for (int i = 0; i < productsAmount; i++)
		delete products[i];
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

Product* Retailer::getProduct(int ProductIndex)
{
	if ((ProductIndex > productsAmount)
		|| (ProductIndex < 0))
		return nullptr;
	return products[ProductIndex];
}

void Retailer::print() const
{
	std::cout << "Retailer: ";
	user.print();
	std::cout << "Products: " << std::endl;
	for (int i = 0; i < productsAmount; i++)
	{
		std::cout << i << ": ";
		products[i]->print();
	}
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
