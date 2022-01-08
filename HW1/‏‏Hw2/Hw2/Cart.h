#ifndef __ORDER_H
#define __ORDER_H

class Cart
{
public:
	Cart(int productsSize);
	Cart(const Cart& other) = delete;
	~Cart();
	void print() const;

private:
	Product** products;
	int productsAmount;
};

#endif // __ORDER_H


