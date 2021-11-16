#ifndef __PRODUCT_H
#define __PRODUCT_H
#include "Address.h"
#include <string.h>
#include <iostream>

class Product
{
public:
	enum class Category{CHILDREN,
		ELECTRICITY,
		OFFICE,
		CLOTHING};
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