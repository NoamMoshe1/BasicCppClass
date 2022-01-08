// Submitted to Keren Kalif
// ------------------------------------------------------------
//Cpp H.W Part 1 --------- Noam Moshe 311463228 ---------------
//-------------------------------------------------------------
#include <iostream>
#include "ECommerceSystem.h"
enum OPTIONS {
	ADD_COSTUMER = 1,
	ADD_RETAILER,
	ADD_PRODUCT_TO_RETAILER,
	ADD_PRODUCT_TO_COSTUMER,
	PAYMENT,
	PRINT_COSTUMERS,
	PRINT_RETAILERS,
	EXIT
};
#define MAX_STRING 1024
void printMenu()
{
	std::cout << std::endl;
	std::cout << "ECommerceSystem menu:" << std::endl;
	std::cout << "\t1. Add Costumer." << std::endl;
	std::cout << "\t2. Add Retailer." << std::endl;
	std::cout << "\t3. Add Product To Retailer." << std::endl;
	std::cout << "\t4. Add Product To Costumer." << std::endl;
	std::cout << "\t5. Payment." << std::endl;
	std::cout << "\t6. Print Costumers." << std::endl;
	std::cout << "\t7. Print Retailers." << std::endl;
	std::cout << "\t8. Exit." << std::endl;
	std::cout << std::endl;
}
void addCostumer(ECommerceSystem& eCommerceSystem)
{
	//print instructions
	std::cout << "please enter a costumer: " << std::endl;
	//cin parameters
	char name[MAX_STRING];
	std::cout << "please enter a costumer name: " << std::endl;
	std::cin >> name;
	char password[MAX_STRING];
	std::cout << "please enter a costumer password: " << std::endl;
	std::cin >> password;
	std::cout << "please enter a costumer address: " << std::endl;
	char street[MAX_STRING];
	std::cout << "please enter a costumer street: " << std::endl;
	std::cin >> street;
	int buildingNumber;
	std::cout << "please enter a costumer building Number: " << std::endl;
	std::cin >> buildingNumber;
	char city[MAX_STRING];
	std::cout << "please enter a costumer city: " << std::endl;
	std::cin >> city;
	char state[MAX_STRING];
	std::cout << "please enter a costumer state: " << std::endl;
	std::cin >> state;
	//create costumer
	Costumer* costumer = new Costumer(
		User(
			name,
			password,
			Address(street, buildingNumber, city, state)));
	//activate ecommerce function
	if (eCommerceSystem.addCostumer(costumer) == false)
		delete costumer;
}
void addRetailer(ECommerceSystem& eCommerceSystem)
{
	//print instructions
	std::cout << "please enter a retailer: " << std::endl;
	//cin parameters
	char name[MAX_STRING];
	std::cout << "please enter a retailer name: " << std::endl;
	std::cin >> name;
	char password[MAX_STRING];
	std::cout << "please enter a retailer password: " << std::endl;
	std::cin >> password;
	std::cout << "please enter a retailer address: " << std::endl;
	char street[MAX_STRING];
	std::cout << "please enter a retailer street: " << std::endl;
	std::cin >> street;
	int buildingNumber;
	std::cout << "please enter a retailer building Number: " << std::endl;
	std::cin >> buildingNumber;
	char city[MAX_STRING];
	std::cout << "please enter a retailer city: " << std::endl;
	std::cin >> city;
	char state[MAX_STRING];
	std::cout << "please enter a retailer state: " << std::endl;
	std::cin >> state;
	//create retailer
	Retailer* retailer = new Retailer(
		User(
			name,
			password,
			Address(street, buildingNumber, city, state)));
	//activate ecommerce function
	if (eCommerceSystem.addRetailer(retailer) == false)
		delete retailer;
}
void addProductToCostumer(ECommerceSystem& eCommerceSystem)
{
	//print instructions
	std::cout << "please enter a costumer index: " << std::endl;
	int costumerIndex;
	std::cin >> costumerIndex;
	std::cout << "please enter a retailer index: " << std::endl;
	int retailerIndex;
	std::cin >> retailerIndex;
	std::cout << "please enter a product index: " << std::endl;
	int productIndex;
	std::cin >> productIndex;
	//activate ecommerce function
	if (eCommerceSystem.addProductToCostumer(costumerIndex, retailerIndex, productIndex) == false)
	{
		std::cout << "can't add product to costumer!" << std::endl;
		return;
	}
	std::cout << "product added succesfuly to costumer." << std::endl;
}
void addProductToRetailer(ECommerceSystem& eCommerceSystem)
{
	//print instructions
	std::cout << "please enter a product: " << std::endl;
	//cin parameters
	std::cout << "please enter a product category: " << std::endl;
	std::cout << "Category options:" << std::endl;
	for (int i = 0; i < (int)Category::CATEGORY_END; i++)
	{
		std::cout << "\t" << i << ":" << categoryStr[i] << std::endl;
	}
	int category;
	std::cin >> category;
	if ((category >= (int)Category::CATEGORY_END)
		|| (category < 0))
	{
		std::cout << category << "is invalid category!" << std::endl;
		return;
	}
	char name[MAX_STRING];
	std::cout << "please enter a product name: " << std::endl;
	std::cin >> name;
	std::cout << "please enter a product price: " << std::endl;
	int price;
	std::cin >> price;
	std::cout << "please enter a retailer index: " << std::endl;
	int retailerIndex;
	std::cin >> retailerIndex;
	//create product
	Product* product = new Product((Category)category, name, price);
	//activate ecommerce function
	if (eCommerceSystem.addProductToRetailer(retailerIndex, product) == false)
		delete product;
}
void payment(ECommerceSystem& eCommerceSystem)
{
	std::cout << "please enter a costumer index: " << std::endl;
	int costumerIndex;
	std::cin >> costumerIndex;
	//activate ecommerce function
	if (eCommerceSystem.payment(costumerIndex) == false)
		return;
		//TODO
}


int main()
{
	std::cout << "Hello eCommerce system!, please enter the name:" << std::endl;
	char name[MAX_STRING];
	std::cin >> name;
	ECommerceSystem eCommerceSystem(name);
	while (true)
	{
		int choice = -1;
		printMenu();
		std::cout << "Enter your choice:" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
		switch (choice)
		{
		case ADD_COSTUMER:
			addCostumer(eCommerceSystem);
			break;
		case ADD_RETAILER:
			addRetailer(eCommerceSystem);
			break;
		case ADD_PRODUCT_TO_COSTUMER:
			addProductToCostumer(eCommerceSystem);
			break;
		case ADD_PRODUCT_TO_RETAILER:
			addProductToRetailer(eCommerceSystem);
			break;
		case PAYMENT:
			payment(eCommerceSystem);
			break;
		case PRINT_COSTUMERS:
			eCommerceSystem.printCostumers();
			break;
		case PRINT_RETAILERS:
			eCommerceSystem.printRetailers();
			break;
		case EXIT:
			return 0;
		default:
			//print error TODO
			break;
		};
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
