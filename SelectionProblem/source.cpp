#include "Selection.h"
#include "BST.h"
#include "HandleInput.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;


int main() {
	Selection s;
	int seed, numOfElem, kthOrderStatistic, randomNumComp = 0, heapNumComp = 0, bstNumComp = 0;
	std::string line;
	
	// For srand
	cin >> seed;
	srand(seed);
	getchar();

	// Get num of persons
	cin >> numOfElem;
	if (numOfElem > 0)
	{
		vector<Person> personArr(numOfElem);
		if (HandleInput::getPersonsData(personArr, numOfElem) && HandleInput::isValidSearch(numOfElem, kthOrderStatistic))
		{
			Person randomSelectionPerson = s.RandSelection(personArr, numOfElem, kthOrderStatistic, randomNumComp);
			Person heapSelectionPerson = s.selectHeap(personArr, numOfElem, kthOrderStatistic, heapNumComp);
			Person bstSelectionPerson = s.BSTselect(personArr, numOfElem, kthOrderStatistic, bstNumComp);

			cout << "RandSelection: " << randomSelectionPerson.id << " " << randomSelectionPerson.name << " " << randomNumComp << " comparisons" << endl;
			cout << "selectHeap: " << heapSelectionPerson.id << " " << heapSelectionPerson.name << " " << heapNumComp << " comparisons" << endl;
			cout << "BST: " << bstSelectionPerson.id << " " << bstSelectionPerson.name << " " << bstNumComp << " comparisons" << endl;
		}
		else
			cout << "invalid input" << endl;
	}
	else
		cout << "invalid input" << endl;
}
	
	
	