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
		int	ordersSize = 10,
		int	productsSize = 10);
	ECommerceSystem(const ECommerceSystem& other) = delete;
	~ECommerceSystem();
	bool addCostumer(User* costumer);
	bool operator+=(Costumer* costumer);
	bool addRetailer(User* retailer);
	bool operator+=(Retailer* retailer);
	bool addProduct(Product* product);
	
	bool addProductToRetailer(int retailerIndex, int productIndex);
	bool addProductToCostumer(int costumerIndex, int retailerIndex, int productId);
	bool payment(int costumerIndex);
	bool compareCostumers(int leftCostumerIndex, int rightCostumerIndex);
	void printRetailers() const;
	void printCostumers() const;
	void printProducts() const;

	//TODO do we need more functions?

private:
	char* name;
	Product** products;
	int productsAmount;
	int productsSize;
	bool resizeProducts();
	User** costumers;
	int costumersAmount;
	int costumersSize;
	bool resizeCostumers();
	User** retailers;
	int retailersAmount;
	int retailersSize;
	bool resizeRetailers();
	Order** orders;
	int ordersAmount;
	int ordersSize;
	bool resizeOrders();
	bool addOrder(Order* order);

	Costumer* getCostumer(int costumerIndex);
	Retailer* getRetailer(int retailerIndex);
};

#endif // __ECOMMERCE_SYSTEM_H


