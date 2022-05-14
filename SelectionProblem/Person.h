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

	Person() = default;

	Person(const Person& p) {
		id = p.id;
		name = std::string(p.name);
	}

	friend bool operator==(const Person& p1, const Person& p2)
	{ 
		if (p1.id == p2.id)
			return true;
		return false;
	}
};




