#pragma once
#include <string>

class Person
{
public:
	Person() = default;
	Person(const std::string& name)
		: name(name)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name)
	{
		this->name = name;
	}

protected:
	std::string name;
};
