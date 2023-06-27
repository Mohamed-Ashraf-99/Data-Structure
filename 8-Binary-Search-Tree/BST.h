#pragma once

template <class T>
struct Node
{
	T value;
	Node* Left;
	Node* Right;
	Node()
	{
		Left = Right = 0;
	}
};


template <class T>
class BST
{
	Node<T>* root;
public:
	BST()
	{
		root = 0;
	}

	void Add(T value)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = value;
		if (!root)
		{
			root = newNode;
		}
		else
		{
			Node<T>* temp = root;
			while (temp)
			{
				if (temp->value == value)
				{
					throw exception("Key already exists!");
				}
				else if (temp->value > value)
				{
					if (temp->Left)
						temp = temp->Left;
					else
					{
						temp->Left = newNode;
						break;
					}
				}
				else
				{
					if (temp->Right)
						temp = temp->Right;
					else
					{
						temp->Right = newNode;
						break;
					}
				}
			}
		}
	}

	bool Exists(T value)
	{
		Node<T>* temp = root;
		while (temp)
		{
			if (temp->value == value)
				return true;
			else if (temp->value > value)
				temp = temp->Left;
			else
				temp = temp->Right;
		}

		return false;
	}
};