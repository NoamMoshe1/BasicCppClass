// Submitted to Keren Kalif
// ------------------------------------------------------------
//Cpp H.W Part 2 --------- Noam Moshe 311463228 ---------------
//-------------------------------------------------------------
#include <iostream>
#include "ECommerceSystem.h"
enum OPTIONS {
	ADD_COSTUMER = 1,
	ADD_COSTUMER_WITH_OPERATOR,
	ADD_RETAILER,
	ADD_RETAILER_WITH_OPERATOR,
	ADD_PRODUCT,
	ADD_PRODUCT_TO_RETAILER,
	ADD_PRODUCT_TO_COSTUMER,
	PAYMENT,
	COMPARE_COSTUMERS,
	PRINT_COSTUMERS,
	PRINT_RETAILERS,
	PRINT_PRODUCTS,
	EXIT
};
#define MAX_STRING 1024
void printMenu()
{
	std::cout << std::endl;
	std::cout << "ECommerceSystem menu:" << std::endl;
	std::cout << "\t1. Add Costumer." << std::endl;
	std::cout << "\t2. Add Costumer (Operator)." << std::endl;
	std::cout << "\t3. Add Retailer." << std::endl;
	std::cout << "\t4. Add Retailer (Operator)." << std::endl;
	std::cout << "\t5. Add Product." << std::endl;
	std::cout << "\t6. Add Product To Retailer." << std::endl;
	std::cout << "\t7. Add Product To Costumer." << std::endl;
	std::cout << "\t8. Payment." << std::endl;
	std::cout << "\t9. Compare Costumers." << std::endl;
	std::cout << "\t10. Print Costumers." << std::endl;
	std::cout << "\t11. Print Retailers." << std::endl;
	std::cout << "\t12. Print Products." << std::endl;
	std::cout << "\t13. Exit." << std::endl;
	std::cout << std::endl;
}
void addProduct(ECommerceSystem& eCommerceSystem)
{
	//print instructions
	std::cout << "please enter a product: " << std::endl;
	//cin parameters
	std::cout << "please enter a product ID: " << std::endl;
	int id;
	std::cin >> id;
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
	Product* product = new Product(id, (Category)category, name, price);
	if (eCommerceSystem.addProduct(product) == false)
		delete product;
}
void addCostumer(ECommerceSystem& eCommerceSystem, bool withOperator = false)
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
			name,
			password,
			Address(street, buildingNumber, city, state));
	//activate ecommerce function
	if (withOperator)
	{
		if((eCommerceSystem += costumer) == false)
			delete costumer;
	}
	else
	{ 
		if (eCommerceSystem.addCostumer(costumer) == false)
			delete costumer;
	}
}
void addRetailer(ECommerceSystem& eCommerceSystem, bool withOperator = false)
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
			name,
			password,
			Address(street, buildingNumber, city, state));
	//activate ecommerce function
	if (withOperator)
	{
		if ((eCommerceSystem += retailer) == false)
			delete retailer;
	}
	else
	{
		if (eCommerceSystem.addRetailer(retailer) == false)
			delete retailer;
	}
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
	std::cout << "please enter a product id: " << std::endl;
	int productId;
	std::cin >> productId;
	//activate ecommerce function
	if (eCommerceSystem.addProductToCostumer(costumerIndex, retailerIndex, productId) == false)
	{
		std::cout << "can't add product to costumer!" << std::endl;
		return;
	}
	std::cout << "product added succesfuly to costumer." << std::endl;
}
void addProductToRetailer(ECommerceSystem& eCommerceSystem)
{
	//print instructions
	std::cout << "please enter a retailer index: " << std::endl;
	int retailerIndex;
	std::cin >> retailerIndex;
	//print instructions
	std::cout << "please enter a product index: " << std::endl;
	int productIndex;
	std::cin >> productIndex;
	//activate ecommerce function
	eCommerceSystem.addProductToRetailer(retailerIndex, productIndex);
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
void compareCostumers(ECommerceSystem& eCommerceSystem)
{
	//print instructions
	std::cout << "please enter left costumer index: " << std::endl;
	int leftCostumerIndex;
	std::cin >> leftCostumerIndex;

	std::cout << "please enter right costumer index: " << std::endl;
	int rightCostumerIndex;
	std::cin >> rightCostumerIndex;

	//activate ecommerce function
	eCommerceSystem.compareCostumers(leftCostumerIndex, rightCostumerIndex);
}


int main()
{
	std::cout << "Hello eCommerce system!, please enter the name:" << std::endl;
	char name[MAX_STRING];
	std::cin.getline(name, MAX_STRING);
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
		case ADD_COSTUMER_WITH_OPERATOR:
			addCostumer(eCommerceSystem, true);
			break;
		case ADD_RETAILER:
			addRetailer(eCommerceSystem);
			break;
		case ADD_RETAILER_WITH_OPERATOR:
			addRetailer(eCommerceSystem, true);
			break;
		case ADD_PRODUCT:
			addProduct(eCommerceSystem);
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
		case COMPARE_COSTUMERS:
			compareCostumers(eCommerceSystem);
			break;
		case PRINT_COSTUMERS:
			eCommerceSystem.printCostumers();
			break;
		case PRINT_RETAILERS:
			eCommerceSystem.printRetailers();
			break;
		case PRINT_PRODUCTS:
			eCommerceSystem.printProducts();
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
