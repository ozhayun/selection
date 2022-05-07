#include "source.h"
#include "Selection.h"
#include "BST.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;


void main() {
	Selection s;
	int numOfElem, kthOrderStatistic, randomNumComp = 0, heapNumComp = 0, bstNumComp = 0;
	std::string line;
	
	cin >> numOfElem;
	vector<Person> personArr(numOfElem);
	//Person* personArr = new Person[numOfElem];
	for (int i = 0; i < numOfElem; i++)
	{
		cin >> personArr[i].id;
		getchar();
		std::getline(cin, personArr[i].name);
	}

	cin >> kthOrderStatistic;

	vector<Person> randomSelectionVector(personArr);
	vector<Person> heapSelectionVector(personArr);
	vector<Person> bstSelectionVector(personArr);

	Person randomSelectionPerson = s.RandSelection(personArr, numOfElem, kthOrderStatistic, randomNumComp);
	Person heapSelectionPerson = s.selectHeap(personArr, numOfElem, kthOrderStatistic, heapNumComp);
	Person bstSelectionPerson = s.BST(personArr, numOfElem, kthOrderStatistic, bstNumComp);

	cout << "RandSelection: " << randomSelectionPerson.id << " " << randomSelectionPerson.name << " " << randomNumComp << " comparisons" << endl;
	cout << "selectHeap: " << heapSelectionPerson.id << " " << heapSelectionPerson.name << " " << heapNumComp << " comparisons" << endl;
	cout << "BST: " << bstSelectionPerson.id << " " << bstSelectionPerson.name << " " << bstNumComp << " comparisons" << endl;
}