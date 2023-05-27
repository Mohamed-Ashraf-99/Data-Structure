#pragma once

template <class T>

class Array
{
	T* InternatlMemory;
	int Size;
	int CurrentIndex;

	/// <summary>
	/// Expand Array Size
	/// </summary>
	void ExpandArray()
	{
		T* NewArray = new T[Size * 1.5];
		for (int i = 0; i < Size; i++)
		{
			NewArray[i] = InternatlMemory[i];
		}

		delete[] InternatlMemory;
		InternatlMemory = NewArray;
		Size *= 1.5;
	}
public:
	Array()
	{
		this->InternatlMemory = 0;
		this->CurrentIndex = 0;
		this->Size = 0;
	}

	Array(int size)
	{
		this->Size = size;
		this->InternatlMemory = new T[size];
		this->CurrentIndex = 0;
	}

	~Array()
	{
		if (this->InternatlMemory)
		{
			delete[]InternatlMemory;
			this->InternatlMemory = 0;
		}
	}

	void Fill() //Fill items into the Array
	{
		int item;
		cout << "How Many Items Do you want to fill? " << endl;
		cin >> item;
		if (item >= this->Size) 
		{
			ExpandArray();
		}
		for (int i = 0; i < item; i++)
		{
			cout << "Enter item of index: " << i << endl;
			cin >> InternatlMemory[i];
			this->CurrentIndex++;
		}
		

	}


	//Display The Array Content
	void Display()
	{
		cout << "Display Array Items: " << endl;
		cout << endl;
		for (int i = 0; i < this->CurrentIndex; i++)
		{
			cout << "Value of index: " << i << " = " << InternatlMemory[i] << endl;
		}
		cout << endl;
	}

	/// <summary>
	/// Get numbers of items in the Array
	/// </summary>
	/// <returns>Current Index</returns>


	/// <summary>
	/// Add new item to the end of Array
	/// </summary>
	/// <param name="item">Item to be added to the Array List</param>
	void Add(int item)
	{
		if (!InternatlMemory)
		{
			this->Size = 10;
			InternatlMemory = new T[Size];
		}
		//Expand the Array
		if (this->CurrentIndex == this->Size)
		{
			ExpandArray();
		}
		InternatlMemory[this->CurrentIndex] = item;
		this->CurrentIndex++;
	}

	/// <summary>
	/// Add an item to a specific location
	/// </summary>
	/// <param name="Item">Item to be added</param>
	/// <param name="Location">Location to be inserted</param>
	void Insert(int item, int Location)
	{
		if (Location >= 0 && Location <= this->Size)
		{
			for (int i = this->CurrentIndex; i > Location; i--)
			{
				InternatlMemory[i] = InternatlMemory[i - 1];
			}
			InternatlMemory[Location] = item;
			CurrentIndex++;
		}
	}

	/// <summary>
	/// Delete an item at a specific location
	/// </summary>
	/// <param name="Location">Location for the item to be deleted</param>
	void Delete(int Location)
	{
		if (Location >= 0 && Location <= this->Size)
		{
			for (int i = Location; i <= this->CurrentIndex; i++)
			{
				InternatlMemory[i] = InternatlMemory[i + 1];
			}
			CurrentIndex--;
		}
		else
		{
			//cout << "Out of range" << endl;
		}
	}

	/// <summary>
	/// Find an item in the Array List
	/// </summary>
	/// <param name="item">Item to be found</param>
	/// <returns>Location of the item or -1 if not found</returns>
	int Find(int item)
	{

		for (int i = 0; i < CurrentIndex; i++)
		{
			if (this->InternatlMemory[i] == item)
			{
				return i; 
				break;
			}
				
		}
	}

	/// <summary>
	/// Sort the entire Array List
	/// </summary>
	void Sort()
	{

	}


	int& operator[](int index)
	{
		if (index >= this->CurrentIndex)
		{
			//cout << "Out of range exception" << endl;;
		}
		return InternatlMemory[index];
	}

	int GetCount()
	{
		return CurrentIndex;
	}

	/// <summary>
	/// Get the Array size
	/// </summary>
	/// <returns>Current Size</returns>
	int GetSize()
	{
		return Size;
	}
};







