#ifndef __ORDER_H
#define __ORDER_H
#include "Product.h"
#include "User.h"
#include <string.h>
#include <iostream>

struct Item
{
	Product* product;
	int retailerIndex;

};

class Order
{
public:
	Order(const User& user,
		Item** items,
		int itemsAmount);
	Order(const Order& other) = delete;
	~Order();
	void print() const;
	//TODO do we need more functions?

private:
	User user;
	Item** items;
	int itemsAmount;
};

#endif // __ORDER_H
