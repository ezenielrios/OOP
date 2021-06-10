//RetailItem Class
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//class declaration
class RetailItem
{
private:
	string description; //Item description
	int unitsOnHand;   //Units on hand
	double price;      //Item price

public:
	//Regular Constructor
	RetailItem(string description, int unitsOnHand, double price)
	{
		description = description; unitsOnHand = unitsOnHand; price = price;
	}
	//Default Constructor
	RetailItem()
	{
		description = "";
		unitsOnHand = 0;
		price = 0;
	};

	// Mutators
	void setDescription(string description)
	{
		description = description;
	}

	void setUnitsOnHand(int unitsOnHand)
	{
		unitsOnHand = unitsOnHand;
	}

	void setPrice(double price)
	{
		price = price;
	}

	// Accessors
	string getDescription()
	{
		return description;
	}

	int getUnitsOnHand()
	{
		return unitsOnHand;
	}

	double getPrice()
	{
		return price;
	}
};

// Function prototype
void displayItem(RetailItem);

int totalInventory(RetailItem item1, RetailItem item2, RetailItem item3);
int main()
{
	int choice = 0;
	int itemNumber = 0;
	int sum = 0;

	//Create three RetailItems objects.
	RetailItem item1;
	RetailItem item2("Jeans", 40, 34.95);
	RetailItem item3("Long sleeve shirt", 20, 24.95);

	cout << "Welcome to the Retail store!" << endl;
	double newPrice = -1;
	int newInventory = -1;
	string newDescription = "";
	while (newPrice < 0) {
		cout << "Price must be greater than 0. \n Please enter the price for item1: ";
		cin >> newPrice;
		item1.setPrice(newPrice);
	}
	while (newInventory < 0) {
		cout << "Inventory must be greater than 0. \nPlease enter the untis on hand for item1: ";
		cin >> newInventory;
		item1.setUnitsOnHand(newInventory);
	}
	cin.ignore();
	cout << "Please enter the description for item 1: ";
	getline(cin, newDescription);
	item1.setDescription(newDescription);


	cout << "\n\nDisplay all items" << endl;
	displayItem(item1);
	displayItem(item2);
	displayItem(item3);



	cout << "\n\nDisplay the total inventory" << endl;
	sum = totalInventory(item1, item2, item3);
	cout << "The total inventory is " << sum << endl;

	//Display each item's data
	system("pause");
	return 0;
}

void displayItem(RetailItem item)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "Description: " << item.getDescription() << endl;
	cout << "Units on hand: " << item.getUnitsOnHand() << endl;
	cout << "Price: $" << item.getPrice() << endl << endl;
}

int totalInventory(RetailItem item1, RetailItem item2, RetailItem item3)
{
	int sum = 0;
	sum += item1.getUnitsOnHand() + item2.getUnitsOnHand() + item3.getUnitsOnHand();
	return sum;
}
