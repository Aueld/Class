#pragma once
#include "CPP_Inheritance_02_person.h"

// 전방 선언
class Person;

class Student : public Person
{
public:
	Student(const std::string& name)
		: Person(name)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name)
	{
		this->name = name;
	}

	void Studty()
	{

	}
};
