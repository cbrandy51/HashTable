#include "HashTable.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Purpose: Parses an entire file and writes everything to console
// Parameters: Stream object, HashTable object
// Returns: none
// -----------------------------------------------------------------
void FormulaParser(ifstream& f, HashTable& h);

int main() 
{
	// data members for creating the hashtable
	char input;
	string name = "";
	string sweight = "";
	double weight = 0.0;
	ifstream read;
	HashTable htable;

	read.open("PeriodicTableElements.txt");
	if (read.fail())
	{
		cerr << "Could not open input file." << endl;
		exit(0);
	}

	do
	{
		weight = 0.0; // re-zeros the weight value
		name = ""; // emptys out name string
		sweight = ""; // emptys out weight string
		read.get(input);
		if (isupper(input))
		{
			name = input;
			read.get(input);
			if (islower(input))
			{
				name += input;
				read.get(input);
				if (islower(input))
				{
					name += input;
					read.get(input); // discards the space character
					read.get(input);
					while (input != '\n')
					{
						sweight += input;
						read.get(input);
					};
					weight = stod(sweight);
					htable.insert(name, weight);
				}
				else if (input == ' ') // discards the space character
				{
					read.get(input);
					while (input != '\n')
					{
						sweight += input;
						read.get(input);
					};
					weight = stod(sweight);
					htable.insert(name, weight);
				}
			}
			else if (input == ' ') // discards the space character
			{
				read.get(input);
				while (input != '\n')
				{
					sweight += input;
					read.get(input);
				};
				weight = stod(sweight);
				htable.insert(name, weight);
			}
		}
	} while (read && read.peek() != EOF); // makes one loop per element with its weight
	read.close();


	ifstream file;
	file.open("formulas.txt");
	if (file.fail())
	{
		cerr << "Could not open second input file." << endl;
		exit(0);
	}

	FormulaParser(file, htable);
	file.close();

	system("PAUSE");
	return 0;
}

void FormulaParser(ifstream& f, HashTable& h)
{
	// data members for parsing the formulas file
	char input = ' ';
	string temp = "";
	int temp2 = 0;
	string formula;
	string name;
	double total;
	double total2;

	do
	{
		// resets variables after each formula
		formula = ""; 
		total = 0.0;
		total2 = 0.0;

		f.get(input); // gets first line of input for every formula
		while (input != '\n' && input != EOF) // makes a loop per group of atoms in formula
		{
			name = "";
			formula += input; // builds the formula string character by character
			if (isupper(input))
			{
				name += input; // builds the name of the atom character by character
				if (f.peek() != '\n')
					f.get(input);
				if (islower(input))
				{
					formula += input;
					name += input;
					if (f.peek() != '\n')
						f.get(input);
					if (islower(input)) // wont ever really get here...
					{
						formula += input;
						f.get(input);
					}
					else if (isupper(input))
					{
						if (f.peek() == '\n')
							f.get(input);
						total += h[name]; // the current atom weight is saved
					}
					else if (isdigit(input))
					{
						formula += input;
						temp = input;
						if (isdigit(f.peek())) // checks for case of a two digit multiplier
						{
							f.get(input);
							temp += input;
							formula += input;
						}
						temp2 = stoi(temp);
						total += ((h[name]) * temp2);
						if (f.peek() == ')') // checks if next character is a closed parenthesis
						{
							f.get(input);
							formula += input;
							if (isdigit(f.peek())) // checks for a multiplier on the parenthesized section
							{
								f.get(input);
								formula += input;
								temp = input;
								temp2 = stoi(temp);
								total *= temp2;
							}
							total += total2; // combines totals
						}
						f.get(input);
					}
					else if (input == '(') // checks for open parenthesis
					{
						formula += input;
						total += h[name];
						total2 = total;
						total = 0.0;
						f.get(input);
					}
				}
				else if (isupper(input))
				{
					total += h[name];
					if (f.peek() == '\n')
						f.get(input);
				}
				else if (isdigit(input))
				{
					formula += input;
					temp = input;
					if (isdigit(f.peek()))
					{
						f.get(input);
						temp += input;
						formula += input;
					}
					temp2 = stoi(temp);
					total += ((h[name]) * temp2); 
					if (f.peek() == ')')
					{
						f.get(input);
						formula += input;
						if (isdigit(f.peek()))
						{
							f.get(input);
							formula += input;
							temp = input;
							temp2 = stoi(temp);
							total *= temp2;
						}
						total += total2;
					}
					f.get(input);
				}
				else if (input == '(')
				{
					formula += input;
					total += h[name];
					total2 = total;
					total = 0.0;
					f.get(input);
				}
				else if (input == ')') // checks for closed parenthesis
				{
					formula += input;
					if (isdigit(f.peek()))
					{
						f.get(input);
						formula += input;
						temp = input;
						temp2 = stoi(temp);
						total *= temp2;
					}
					total += total2;
					f.get(input);
				}
			}
			else if (input == '(')
			{
				total2 = total; // saves total up to this point
				total = 0.0; // resets total for what is inside the parenthesis
				f.get(input);
			}
		}
		cout << "The molecular weight for " << formula << " is: " << total << endl;
	} while (f && f.peek() != EOF); // makes one loop per formula 
}