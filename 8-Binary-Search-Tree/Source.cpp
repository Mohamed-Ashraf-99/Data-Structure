#include <iostream>
#include <exception>
using namespace std;
#include "BST.h"


void main()
{
	BST<int> bst;
	bst.Add(15);
	bst.Add(10);
	bst.Add(20);
	bst.Add(8);
	bst.Add(12);
	bst.Add(18);
	bst.Add(25);
	bst.Add(16);
	bst.Add(19);
	bst.Add(30);

	cout << bst.Exists(16) << endl;
	cout << bst.Exists(45) << endl;
}