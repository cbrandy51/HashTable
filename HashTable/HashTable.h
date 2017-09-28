#pragma once
#include "List.h"
#include "Node.h"
#include <cctype>
#include <string>
using namespace std;

// Global Data Member
const int CAPACITY = 50;

class HashTable
{
public:
	// Purpose: Default constructor for the HashTable class
	// Parameters: none
	// Returns: none
	// -----------------------------------------------------------------
	HashTable();

	// Purpose: Removes all members from the hash table
	// Parameters: none
	// Returns: none
	// -----------------------------------------------------------------
	void clear();

	// Purpose: Inserts a value into the hash table
	// Parameters: none
	// Returns: none
	// -----------------------------------------------------------------
	void insert(string n, double w);

	// Purpose: Retrieves the data from a specific index in the hash table
	// Parameters: String object, Double value
	// Returns: Double value
	// ----------------------------------------------------------------------
	double retrieve(string n);

	// Purpose: Uses a key to properly index data for the hash table
	// Parameters: String object
	// Returns: none
	// -----------------------------------------------------------------
	int hash(string n);

	// Purpose: Retrieves the data from a specific index in the hash table
	// Parameters: String object
	// Returns: Double value
	// -----------------------------------------------------------------------
	double operator [](string n);
private:
	// Data Member
	List* table[CAPACITY];
};

