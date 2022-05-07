#pragma once
#include <string>

class Person {
public:
	int id;
	std::string name;

	friend void swap(Person& p1, Person& p2)
	{
		std::swap(p1.id, p2.id);
		p1.name.swap(p2.name);
	}

	//Person& operator=(const Person& p) {
	//	id = p.id;
	//	name = p.name;
	//}

	Person() = default;

	Person(const Person& p) {
		id = p.id;
		name = std::string(p.name);
	}
};

