#ifndef __RETAILER_H
#define __RETAILER_H
#include "Product.h"
#include "User.h"
#include <string.h>
#include <iostream>

class Retailer
{
public:
	Retailer(const User& user, int productSize = 10);
	Retailer(const Retailer& other) = delete;
	~Retailer();
	bool addProduct(Product* product);
	void print() const;
	//TODO do we need more functions?

private:
	User user;
	Product** products;
	int productsAmount;
	int productsSize;
	bool resizeProducts();
};

#endif // __RETAILER_H

