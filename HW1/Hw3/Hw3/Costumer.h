#ifndef __COSTUMER_H
#define __COSTUMER_H
#include "Product.h"
#include "User.h"
#include "Order.h"
#include <string.h>
#include <iostream>

class Costumer : public User
{
public:
	Costumer(const char* userName,
		const char* userPassword,
		const Address& address);
	virtual ~Costumer();
	void print(std::ostream& os) const override;
	friend std::ostream& operator<<(std::ostream& os, const Costumer& costumer);
	Order* payment();
	bool operator< (const Costumer& rhs) const;
	bool operator> (const Costumer& rhs) const;
	bool operator== (const Costumer& rhs) const;
	bool operator!= (const Costumer& rhs) const;

private:
	bool removeItems();
	double getTotalPrice() const;
};

#endif // __COSTUMER_H
