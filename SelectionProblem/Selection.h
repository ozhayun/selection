#pragma once
#include "Person.h"
#include "Random.h"
#include <vector>

using std::vector;

class Selection {
	Random random;
	//static Heap heap;
	//static BST bst
public:
	const Person& RandSelection(vector<Person>& personArr, int n, int k, int& numComp) {
		return random.Selection(personArr, n, k, numComp);
	}


	const Person& selectHeap(vector<Person>& personArr, int n, int k, int& numComp)
	{

	}

	const Person& BST(vector<Person>& personArr, int n, int k, int& numComp)
	{

	}

};

