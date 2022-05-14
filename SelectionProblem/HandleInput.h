#pragma once
#include "Person.h"
#include "vector"

#include <iostream>
#include <algorithm>


using std::vector;

class HandleInput
{
public:
	static bool getPersonsData(vector<Person>& personArr, int numOfElem);
	static bool isPersonExist(vector<Person>& personArr, int size, Person personToCheck);
	static bool isValidSearch(int numOfElem, int & k);
};

