#include <iostream>
#include <exception>
#include <vector>
using namespace std;
#include "ArrayList.h"

void Menu()
{
	cout << endl;
	cout << endl;
	cout << "========Array List=========" << endl;
	cout << "CHoice from the following" << endl;
	cout << "1-Add new item to the end of Array" << endl;
	cout << "2-Add an item to a specific location" << endl;
	cout << "3-Delete an item at a specific location" << endl;
	cout << "4-Find an item in the Array List" << endl;
	cout << "5-Get Array Size" << endl;
	cout << "6-Get Array Current Number of Index" << endl;
	cout << "7-Display Array contetnt" << endl;
	cout << "8-Exit!" << endl;
	cout << endl;
}


int main()
{
	int item;
	Array<int> list(10);
	list.Fill();
	Menu();
	int choice;
	int Location;
	cin >> choice;
	switch (choice)
	{

	case 1:
		cout << "Add item" << endl;
		cin >> item;
		list.Add(item);
		list.GetSize();
		list.GetCount();
		list.Display();
		break;

	case 2:
		cout << "Enter the item & Location" << endl;
		cin >> item >> Location;
		list.Insert(item, Location);
		list.GetSize();
		list.GetCount();
		list.Display();
		break;

	case 3:
		cout << "Enter the index you want to delete" << endl;
		cin >> Location;
		list.Delete(Location);
		list.GetSize();
		list.GetCount();
		list.Display();
		break;

	case 4:
		cout << "Enter the item" << endl;
		cin >> item;
		list.Find(item);
			cout << "Item Found @ index: " << list.Find(item) << endl;
		break;

	case 5:
		cout << "Current size of Array" << " = " << list.GetSize() << endl;
		break;

	case 6:
		cout << "Current index of Array" << " = " << list.GetCount() << endl;
		break;

	case 7:
		list.Display();
		break;

	default:
		break;
	}
	return 0;
}


