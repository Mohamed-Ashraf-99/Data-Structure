#include <iostream>
using namespace std;

template <class T>

class stack
{
	int  top;
	T arr[100];  
public:
	stack()
	{
		top = -1;
	}

	void push(T item) 
	{
		if (top >= 99) 
		{
			cout << "Full!" << endl;
		}
		else
		{
			top++;
			arr[top] = item;
		}
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void pop()
	{
		if (isEmpty())
		{
			cout << "Empty!" << endl;
		}
		else
		{
			top--;
		}
		

	}

	void popp(T &item) 
	{
		if (top == -1)
		{
			cout << "Empty!" << endl;
		}
		else
		{
			arr[top] = item;
			top--;
		}


	}

	void getTop(T item) 
	{
		if (top == -1)
		{
			cout << "Empty!" << endl;
		}
		else
		{
			arr[top] = item;
			cout << item << endl;
		}


	}

	void print()
	{
		if (top == -1)
		{
			cout << "Empty" << endl;
		}
		else
		{
			for (int i = top ; i >= 0; i--) 
			{
				cout << "Item" << "[" << i <<"]" << " = " << arr[i] << endl;
			}
		}
	}
};

int main()
{
	stack<int> st;   
	/*st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	st.print();*/
	cout << "==========================" << endl;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	st.pop();
	int x=0;
	st.popp(x);
	st.getTop(x);
	st.print();

	return 0;
}