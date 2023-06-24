#include <iostream>
#include <exception>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		this->data = 0;
		this->next = NULL;
	}
};

class Queue 
{
public:
	Node* front;
	Node* rear;
	int counter = 0;
	Queue()
	{
		front = rear = NULL;
	}

	bool isEmpty()
	{
		if (front == rear == NULL)
			return true;
		else
			return false;
	}

	void enqueue(int item)
	{
		Node* newNode = new Node;
		newNode->data = item;
		if (isEmpty)
		{
			front = rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		counter++;
	}

	void display()
	{
		Node* Temp = front;
		while (Temp != NULL)
		{
			cout << Temp->data << "  ";
			Temp = Temp->next;
		}
	}

	void dequeue()
	{
		if (isEmpty())
		{
			cout << "No item found" << endl;
		}
		else if (front == rear)
		{
			delete front;
			front == rear == NULL;
		}
		else
		{
			Node* Temp = front;
			front = front->next;
			delete Temp;
		}
		counter--;
	}

	int count()
	{
		Node* Temp = front;
		while (Temp != NULL)
		{
			Temp = Temp->next;
		}
		return counter;
	}

	bool isFound(int item)
	{
		Node* Temp = front;
		while (Temp != NULL)
		{
			if (Temp->data == item)
			{
				return true;
			}
			Temp = Temp->next;
		}
		return true;
	}

	void clear()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}

	int getFront()
	{
		return front->data;
	}

	int getRear()
	{
		return rear->data;
	}
};

void main()
{
	Queue q;

	for (int i = 0; i <= 3; i++)
	{
		int item;
		cout << "Enter item to Enqueue" << endl;
		cin >> item;
		q.enqueue(item);
	}
	q.display();
}