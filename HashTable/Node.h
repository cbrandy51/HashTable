#pragma once
#include <string>
using namespace std;

struct Node
{
	// Data Members
	string ID;
	double weight;
	Node* next;

	// Purpose: Parameterized constructor for the Node class
	// Parameters: String object, Double value
	// Returns: none
	// -----------------------------------------------------------------
	Node(string n, double w)
	{
		ID = n;
		weight = w;
		next = nullptr;
	};
};