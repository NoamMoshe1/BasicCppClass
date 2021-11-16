#ifndef __ORDER_H
#define __ORDER_H
#include "Product.h"
#include "User.h"
#include <string.h>
#include <iostream>

class Order
{
public:
	Order(const User& user,
		Product** products,
		int productsAmount);
	Order(const Order& other) = delete;
	~Order();
	void print() const;
	//TODO do we need more functions?

private:
	User user;
	Product** products;
	int productsAmount;
};

#endif // __ORDER_H
