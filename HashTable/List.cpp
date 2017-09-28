#include "List.h"
using namespace std;

double List::find(string n)
{
	return find(head, n);
}

double List::find(Node* nn, string n)
{
	if (nn == nullptr)
		return 0.0;
	else if (nn->ID == n)
		return nn->weight;
	else
		return find(nn->next, n);
}

void List::addEnd(string n, double w)
{
	Node* NN = new Node(n, w);

	if (head == nullptr)
		head = NN;
	else
		addEnd(n, w, head);
}

void List::addEnd(string n, double w, Node* nn)
{
	if (nn->next == nullptr)
		nn->next = new Node(n, w);
	else
		addEnd(n, w, nn->next);
}