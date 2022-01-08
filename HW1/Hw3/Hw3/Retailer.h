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
	Product* getProduct(int productId);
	void print() const;
	friend std::ostream& operator<<(std::ostream& os, const Retailer& retailer);

private:
	User user;
	Product** products;
	int productsAmount;
	int productsSize;
	bool resizeProducts();
};

#endif // __RETAILER_H

