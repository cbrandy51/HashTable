#include "HashTable.h"
using namespace std;


HashTable::HashTable()
{
	for (int i = 0; i < CAPACITY; i++)
		table[i] = new List;
}

void HashTable::clear()
{
	for (int i = 0; i < CAPACITY; i++)
		table[i] = new List;
}

void HashTable::insert(string n, double w)
{
	int idx = hash(n);

	table[idx]->addEnd(n, w);
}

int HashTable::hash(string n)
{
	int temp = 0;

	for (int i = 0; i < 2; i++)
	{
		if (isupper(n[i]) || islower(n[i]))
			temp += (int)n[i];
	}
	return (temp % CAPACITY);
}

double HashTable::retrieve(string n)
{
	int idx = hash(n);

	return table[idx]->find(n);
}

double HashTable::operator [](string n)
{
	int idx = hash(n);

	return table[idx]->find(n);
}