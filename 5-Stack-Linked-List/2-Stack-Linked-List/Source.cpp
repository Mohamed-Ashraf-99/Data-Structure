#include <iostream>
#include <exception>

using namespace std;

template <class T>

class stack
{
	struct Node
	{
		T data;
		Node* next;
	};
	Node* top, * cur;
		top = NULL;
	counter = 0;
public:
	bool isEmpty()
	{
		return top = NULL;
	}
	void push(T item)
	{
		Node* newNode = new Node;
		newNode->data = item;
		if (isEmpty)
		{
			top = newNode;
			newNode->next = NULL;
			counter++;
		}
		else
		{
			newNode->next = top;
			top = newNode;
			counter++;
		}
	}

	void pop()
	{
		if (isEmpty)
		{
			throw exception"No item found";
		}
		else
		{
			Node* temp = top;
			top = top->next; 
			temp = temp->next = NULL;
			delete temp;
		}
	}

	void pop(T& item)
	{
		if (isEmpty)
		{
			throw exception"No item found";
		}
		else
		{
			item = top->data;
			Node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}

	void getTop(T& item)
	{
		if (isEmpty)
		{
			throw exception"No item found";
		}
		else
		{
			item = top->data;
		}
	}

	void display()
	{
		cur = top;
		while (cur != NULL) 
		{
			cout << cur->data << endl;
			cur = cur->next;
		}
	}

};

void main()
{
	stack<int> S;
}