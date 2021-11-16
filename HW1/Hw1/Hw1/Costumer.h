#ifndef __COSTUMER_H
#define __COSTUMER_H
#include "Product.h"
#include "User.h"
#include "Order.h"
#include <string.h>
#include <iostream>

class Costumer
{
public:
	Costumer(const User& user, int productSize = 10);
	Costumer(const Costumer& other) = delete;
	~Costumer();
	void print() const;
	bool addProduct(Product* product);
	Order* payment();
	//TODO do we need more functions?

private:
	User user;
	Product** products;
	int productsAmount;
	int productsSize;
	bool resizeProducts();
	bool removeProducts();
};

#endif // __COSTUMER_H
