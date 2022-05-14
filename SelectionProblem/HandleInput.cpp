#include "HandleInput.h"


using std::cin;

// This function fill the vector with new persons data
bool HandleInput::getPersonsData(vector<Person>& personArr, int numOfElem)
{
	int count = 0;
	Person p;

	// Check validation of connections and add them to connections vector

	// Get the data
	for (int i = 0; i < numOfElem; i++)
	{
		cin >> p.id;
		getchar();
		std::getline(cin, p.name);
		if (!isPersonExist(personArr, i, p))
			personArr[i] = p;
		else
			return false;
	}
	return true;
}

// This function check if person already exists
bool HandleInput::isPersonExist(vector<Person>& personArr, int size, Person personToCheck)
{
	for (int i = 0; i < size; i++)
		if (personArr[i] == personToCheck)
			return true;
	return false;
}

// This function check if search is valid
bool HandleInput::isValidSearch(int numOfElem, int& k)
{
	cin >> k;
	if ((k > numOfElem) || (k < 1))
		return false;
	return true;
}