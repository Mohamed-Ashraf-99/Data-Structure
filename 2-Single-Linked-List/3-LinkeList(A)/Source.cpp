#include <iostream>
#include<algorithm>
using namespace std;

;

class LinkedList
{
	struct Node
	{
		int data;
		Node* next;
	};
	Node* Head;
	Node* Tail;
public:

	LinkedList()
	{
		Head = NULL; 
		Tail = NULL;
	}

	bool IsEmpty()
	{
		return Head == NULL;
	}

	int counter = 0;
	void AddFirst(int item)
	{
		
		Node* newnode = new Node; 
		newnode->data = item;
		if (IsEmpty())
		{
			Head = Tail = newnode;
			newnode->next = NULL;
			counter++;
		}
		else
		{
			newnode->next = Head;
			Head = newnode;
			counter++;
		}
	}

	
	void AddEnd(int item)
	{

		Node* newnode = new Node;
		newnode->data = item;
		if (IsEmpty())
		{
			Head = Tail = newnode; 
			newnode->next = NULL;
			counter++;
		}
		else
		{
			Tail->next = newnode; 
			newnode->next = NULL; 
			Tail = newnode;
			counter++;
		}

	}

	void InsertAtPos(int pos, int item)
	{
		Node* newnode = new Node;
		newnode->data = item;
		Node* Temp = Head;
		if (pos<0 || pos >counter)
		{
			cout << "Out of range !" << endl;
		}
		else
		{
			Node* newnode = new Node;
			newnode->data = item;
			if (pos == 0)
			{
				AddFirst(item); 
			}
			else if (pos == counter)
			{
				AddEnd(item);
			}
			else
			{
				Node* Temp = Head;
				for (int i = 1; i < pos; i++)
				{
					Temp = Temp->next;
				}
				newnode->next = Temp->next; 
				Temp->next = newnode; 
				counter++;  
			}
			

		}
	}

	void Print()
	{
		Node* Temp = Head;
		while (Temp != NULL)
		{
			cout << Temp->data << endl;
			Temp = Temp->next; 
		}
	}

	void DeleteFirst()
	{
		if (IsEmpty())
			return;
		else if (counter == 1)
		{
			delete Head;
			Head = Tail = NULL;
			counter--;
		}
		else
		{
			Node* Temp = Head;
			Head = Head->next;
			delete Temp;
			counter--;
		}
	}

	void DeleteLast()
	{
		if (IsEmpty())
			return;
		else if (counter == 1)
		{
			delete Head;
			Head = Tail = NULL;
			counter--;
		}
		else
		{
			Node* Temp = Head->next;
			Node* Prev = Head;
			while (Temp != Tail) 
			{
				Prev = Temp;
				Temp = Temp->next;
			}
			delete Temp;
			Prev->next = NULL;
			Tail = Prev;
			counter--;
		}
	}

	void remove(int element)
	{
		if (IsEmpty())
		{
			cout << "Out of range" << endl;
			return;
		}
		Node* Temp;
		Node* Prev;
		if (Head->data == element)
		{
			Temp = Head;
			Head = Head->next; 
			delete Temp;
			counter--;
			if (counter == 0)
			{
				Tail = NULL;
			}

		}
		else
		{
			Temp = Head->next;
			Prev = Head;
			while (Temp != NULL)
			{
				if (Temp->data == element)
				{
					break;
				}
				Prev = Temp;
				Temp = Temp->next;	
			}
			if (Temp == NULL)
			{
				cout << "Element Not Found" << endl;
			}
			else
			{
				Prev->next = Temp->next;
				if (Tail == NULL)
				{
					Tail = Prev;
				}
				delete Temp;
				counter--;
			}

		}


	}

	void reverse()
	{
		Node* Prev, * Next, * Temp;
		Prev = NULL;
		Temp = Head; 
		Next = Head->next;
		while (Next != NULL || Temp != NULL)
		{
			Next = Temp->next;
			Temp->next = Prev;
			Prev = Temp;
			Temp = Next;
		}

		Head = Prev;
	}

	int search(int element)
	{
		Node* Temp = Head;
		int pos = 0; 
		while (Temp != NULL)
		{
			
			if (Temp->data == element)
			{
				return pos; 
				Temp = Temp->next;
				pos++;
			}
			else
			{
				return -1;
			}
				
			
		}
	}
};



int main()
{
	LinkedList List;
	int item;
	/*cout << "Enter item:" << endl;
	cin >> item;
	List.AddFirst(item);
	cout << "Enter item:" << endl;
	cin >> item;
	List.AddEnd(item);
	cout << "Enter item:" << endl;
	cin >> item;
	List.AddEnd(item);
	cout << "Display ELements" << endl;
	List.Print();*/
	List.AddEnd(10);
	List.AddEnd(20);
	List.AddEnd(30);
	List.AddEnd(40);
	List.InsertAtPos(0, 222);
	List.DeleteLast();
	List.Print();



	return 0;
}