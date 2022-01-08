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
	Product(int id,
		Category category,
		const char* name,
		double price);
	Product(const Product& other) = delete;
	~Product();
	void print() const;
	double getPrice() const;
	int getId() const;

private:
	Category category;
	char* name;
	double price;
	int id;

};

#endif // __PRODUCT_H