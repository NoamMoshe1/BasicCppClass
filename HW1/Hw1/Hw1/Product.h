#ifndef __PRODUCT_H
#define __PRODUCT_H
#include "Address.h"
#include <string.h>
#include <iostream>

static const char* categoryStr[] = { "Children",
		"Electricity",
		"Office",
		"Clothing" };

enum class Category {
	CHILDREN,
	ELECTRICITY,
	OFFICE,
	CLOTHING,
	CATEGORY_END
};

class Product
{
public:
	Product(Category category,
		const char* name,
		double price);
	Product(const Product& other) = delete;
	~Product();
	void print() const;
	double getPrice() const;

private:
	Category category;
	char* name;
	double price;
};

#endif // __PRODUCT_H