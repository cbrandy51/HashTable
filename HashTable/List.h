#pragma once
#include "Node.h"
#include <string>
using namespace std;

class List
{
public:
	// Purpose: Default Constructor for the List class
	// Parameters: none
	// Returns: none
	// -----------------------------------------------------------------
	List() { head = nullptr; };

	// Purpose: Adds a node/value to the end of the list
	// Parameters: String object, Double value
	// Returns: none
	// -----------------------------------------------------------------
	void addEnd(string n, double w);

	// Purpose: Finds a certain value in the list
	// Parameters: String object
	// Returns: Double value
	// -----------------------------------------------------------------
	double find(string n);
private:
	// Purpose: Helper function to the addEnd function
	// Parameters: String object, Double value, Node pointer
	// Returns: none
	// -----------------------------------------------------------------
	void addEnd(string n, double w, Node* nn);

	// Purpose: Helper function to the find function
	// Parameters: Node pointer, String object
	// Returns: Double value
	// -----------------------------------------------------------------
	double find(Node* nn, string n);

	// Data Member
	Node* head;
};

