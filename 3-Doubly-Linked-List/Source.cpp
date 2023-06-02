#include <iostream>
using namespace std;

class DoubleLinKedList
{
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	}; 
	Node* Head;
	Node* Tail;
	int counter;
public:

	DoubleLinKedList()
	{
	 Head = NULL;  
	 Tail = NULL;
	 counter = 0; 
	} 

	
	bool IsEmpty()
	{
		return Head == Tail == NULL; 
	}

	
	void InsertFirst(int item)
	{
		Node* newNode = new Node;
		newNode->data = item; 
		if (counter == 0) 
		{
			Head = Tail = newNode;
			newNode->next = newNode->prev = NULL;
			counter++;
		}
		else
		{
			newNode->next = Head;
			newNode->prev = NULL;
			Head = newNode;
			counter++;
		}
		
	}
	
	/// <summary>
	/// Insert node from the end of list
	/// </summary>
	void InsertLast(int item)
	{
		Node* newnode = new Node; 
		newnode->data = item;
		if (counter == 0)  
		{
			Head = Tail = newnode;
			newnode->next = newnode->prev = NULL;
			counter++;
		}
		else
		{
			newnode->next = NULL;
			newnode->prev = Tail;
			Tail->next = newnode; 
			Tail = newnode; 
			counter++;
		}
		
	}

	/// <summary>
	/// Insert item at specific position
	/// </summary>
	/// <param name="pos">Positon of node</param>
	/// <param name="item">Value of data</param>
	void InsertAtPosition(int pos, int item)
	{
		Node* newnode = new Node;
		newnode->data = item;
		if (pos < 0 || pos > counter)
		{
			cout << "Out of range" << endl;
			return;
		}
		else
		{
			if (pos == 0)
			{
				InsertFirst(item);
				counter++;
			}
			else if (pos == counter)
			{
				InsertLast(item);
				counter++;
			}
			else
			{
				Node* Temp = Head;
				for (int i = 1; i < pos; i++)
				{
					Temp = Temp->next;
				}
				newnode->next = Temp->next;
				newnode->prev = Temp;
				Temp->next = newnode;
				Temp->next->prev = newnode;
				counter++;
			}
		}
	}

	/// <summary>
	/// Print Nodes Data
	/// </summary>
	void Print()
	{
		cout << "Elemet List" << endl;
		Node* Temp = Head;
		while (Temp != NULL)
		{
			cout << Temp->data << endl;
			Temp = Temp->next;
		}
	}

	/// <summary>
	/// Delete the first node
	/// </summary>
	void DeleteFirst()
	{
		if (counter == 0)
		{
			cout << "No items found" << endl;
			return;
		}
		else if (counter == 1)
		{
			delete Head;
			Head == Tail == NULL;
		}
		else
		{
			Node* Temp = Head;
			Head = Head->next;
			Head->prev = NULL;
			delete Temp;
		}
		counter--;
	}

	/// <summary>
	/// Delete the last node
	/// </summary>
	void DeleteLast()
	{
		if (counter == 0)
		{
			cout << "List is Empty" << endl;
		}
		else if (counter == 1)
		{
			delete Head;
			Head == Tail == NULL;
		}
		else
		{
			Node* Temp = Tail;
			Tail = Tail->prev; 
			Tail->next = NULL;
			delete Temp;
		}
		counter--;
	}

	/// <summary>
	/// Delete specific node
	/// </summary>
	/// <param name="item">Value of data</param>
	void Delete(int item)
	{
		if (counter == 0)
		{
			cout << "No items found" << endl;
			return;
		}
	    if (Head->data == item)
		{
			DeleteFirst();
		}
		else
		{
			Node* Temp = Head->next;

			while ( Temp != NULL )
			{
				if (Temp->data == item)
				{
					break;
				}
				Temp = Temp->next;
			}
			if (Temp == NULL)
			{
				cout << "No items found" << endl;
				return;
			}
			else if (Temp->next == NULL)
			{
				DeleteLast();
			}
			else
			{
				Temp->prev->next = Temp->next;
				Temp->next->prev = Temp->prev;
				delete Temp;
			}
			
		}
		counter--;
	}

	/// <summary>
	/// Print items by reverse
	/// </summary>
	void reverse()
	{
		cout << "Elemet List" << endl;
		Node* Temp = Tail; 
		while (Temp != NULL)
		{
			cout << Temp->data << endl;
			Temp = Temp->prev;
		}
	}
};

int main()
{
	DoubleLinKedList List;

	/*List.InsertFirst(10);
	List.InsertLast(20); 
	List.InsertLast(30);
	List.InsertLast(40);
	List.InsertLast(50);
	List.InsertAtPosition(2, 545);
	List.Print();
	cout << endl;*/
	cout << "===============================" << endl;
	List.InsertFirst(10);
	List.InsertLast(20);
	List.InsertLast(30);
	List.InsertLast(40);
	List.InsertLast(50);
	//List.DeleteFirst();
	//List.DeleteLast();
	List.Delete(30);
	List.Print();
	cout << endl;

	return 0;
}