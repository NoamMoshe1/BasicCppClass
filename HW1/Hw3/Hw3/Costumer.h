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
	Costumer(const User& user, int itemsSize = 10);
	Costumer(const Costumer& other) = delete;
	~Costumer();
	void print() const;
	friend std::ostream& operator<<(std::ostream& os, const Costumer& costumer);
	bool addProduct(Product* product, int retailerIndex);
	Order* payment();
	bool operator< (const Costumer& rhs) const;
	bool operator> (const Costumer& rhs) const;
	bool operator== (const Costumer& rhs) const;
	bool operator!= (const Costumer& rhs) const;

private:
	User user;
	Item** items;
	int itemsAmount;
	int itemsSize;
	bool resizeItems();
	bool removeItems();
	double getTotalPrice() const;
};

#endif // __COSTUMER_H
