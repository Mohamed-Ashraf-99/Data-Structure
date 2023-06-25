#pragma once

template <class K, class V>
struct KeyValuePair
{
	K Key;
	V Value;
};

template <class K, class V>
class HashTable
{
	list<KeyValuePair<K, V>> buckets[100];

	unsigned int hash(unsigned int x) {
		x = ((x >> 16) ^ x) * 0x45d9f3b;
		x = ((x >> 16) ^ x) * 0x45d9f3b;
		x = (x >> 16) ^ x;
		return x;
	}

	int GetPosition(K key)
	{
		unsigned int h = hash(key);
		int position = h % 100;
		return position;
	}

public:
	void Add(K key, V value)
	{
		int position = GetPosition(key);
		KeyValuePair<K, V> pair = { key, value };
		buckets[position].push_back(pair);
	}

	V GetValue(K key)
	{
		int position = GetPosition(key);
		for (auto it = buckets[position].begin(); it != buckets[position].end(); it++)
		{
			if (it->Key == key)
				return it->Value;
		}

		throw exception("Key not found!");
	}
};