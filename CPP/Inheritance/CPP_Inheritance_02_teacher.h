#pragma once
#include "CPP_Inheritance_02_person.h"

class Person;

class Teacher : public Person
{
	Teacher(const std::string& name)
		: Person(name)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name)
	{
		this->name = name;
	}

	void Teach()
	{

	}
};
