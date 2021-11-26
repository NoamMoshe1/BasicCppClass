#ifndef __ECOMMERCE_SYSTEM_H
#define __ECOMMERCE_SYSTEM_H
#include "Costumer.h"
#include "Retailer.h"
#include "Order.h"
#include <string.h>
#include <iostream>

class ECommerceSystem
{
public:
	ECommerceSystem(const char* name,
		int costumersSize = 10,
		int retailersSize = 10,
		int	ordersSize = 10);
	ECommerceSystem(const ECommerceSystem& other) = delete;
	~ECommerceSystem();
	bool addCostumer(Costumer* costumer);
	bool addRetailer(Retailer* retailer);
	bool addProductToRetailer(int retailerIndex, Product* product);
	bool addProductToCostumer(int costumerIndex, int retailerIndex, int productIndex);
	bool payment(int costumerIndex);
	void printRetailers() const;
	void printCostumers() const;

	//TODO do we need more functions?

private:
	char* name;
	Costumer** costumers;
	int costumersAmount;
	int costumersSize;
	bool resizeCostumers();
	Retailer** retailers;
	int retailersAmount;
	int retailersSize;
	bool resizeRetailers();
	Order** orders;
	int ordersAmount;
	int ordersSize;
	bool resizeOrders();
	bool addOrder(Order* order);
};

#endif // __ECOMMERCE_SYSTEM_H


