#include <iostream>
#include <list>
#include <map>
#include <set>
using namespace std;
#include "HashTable.h"


void main()
{
	HashTable<int, int> ht;
	map<int, int> m;
	set<int> s;

	for (int i = 0; i < 50; i++)
	{
		ht.Add(i, i * i);
		m[i] = i * i;
		s.insert(i);
	}
	
	cout << ht.GetValue(10) << endl;
	cout << m[10] << endl;
	cout << (s.find(55) != s.end()) << endl;
}