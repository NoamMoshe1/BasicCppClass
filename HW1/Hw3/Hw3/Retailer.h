#ifndef __RETAILER_H
#define __RETAILER_H
#include "Product.h"
#include "User.h"
#include <string.h>
#include <iostream>

class Retailer : public User
{
public:
	Retailer(const char* userName,
		const char* userPassword,
		const Address& address);
	virtual ~Retailer();
	void print(std::ostream& os) const override;
	friend std::ostream& operator<<(std::ostream& os, const Retailer& retailer);
};

#endif // __RETAILER_H

