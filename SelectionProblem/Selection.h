#pragma once
#include "Person.h"
#include "Random.h"
#include "MinHeap.h"
#include "BST.h"
#include <vector>

using std::vector;

class Selection {
	Random random;
	MinHeap minHeap;
	BST bst;

	Person randomPerson;
	Person heapPerson;
	Person bstPerson;
public:
	const Person& RandSelection(vector<Person>& personArr, int n, int k, int& numComp);
	const Person& selectHeap(vector<Person>& personArr, int n, int k, int& numComp);
	const Person& BSTselect(vector<Person>& personArr, int n, int k, int& numComp);
};

