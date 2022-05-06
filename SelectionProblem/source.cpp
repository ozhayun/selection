#include "source.h"
#include "Selection.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;


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
	int numOfElem, requestedInd;
	std::string line;
	
	cin >> numOfElem;
	Person* personArr = new Person[numOfElem];
	for (int i = 0; i < numOfElem; i++)
	{
		cin >> personArr[i].id;
		getchar();
		std::getline(cin, personArr[i].name);
	}

	cin >> requestedInd;
	
	Selection s;
	
	Person p = s.Select(personArr, 0, numOfElem, requestedInd);
	cout << p.id << " " << p.name << endl;

}