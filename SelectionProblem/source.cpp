#include "source.h"
#include "Selection.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;


void print(Person* personArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << personArr[i].id <<endl;
		cout << personArr[i].name << endl;
		cout << endl;
	}
}

void main()
{
	Selection selection;
	int numOfElem, kthOrderStatistic, randomNumComp = 0;
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

	
	Person randomSelectionPerson = selection.RandSelection(randomSelectionVector, numOfElem, kthOrderStatistic, randomNumComp);
	cout << "RandSelection: " << randomSelectionPerson.id << " " << randomSelectionPerson.name << " " << randomNumComp << " comparisons" << endl;
}