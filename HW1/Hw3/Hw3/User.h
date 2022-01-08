#ifndef __USER_H
#define __USER_H
#include "Address.h"
#include <string.h>
#include <iostream>
#include "Product.h"

class User
{
public:
	User(const char* userName,
		const char* userPassword,
		const Address& address,
		int itemsSize = 10);
	User(const User& other);
	virtual ~User();
	virtual bool addProduct(Product* product, int ownerIndex);
	virtual Product* getProduct(int productId);
	virtual void print() const;
	virtual void print(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const User& user);

protected:
	char* userName;
	char* userPassword;
	Address address;

	Item** items;
	int itemsAmount;
	int itemsSize;
	bool resizeItems();
	bool removeItems();
};

#endif // __USER_H