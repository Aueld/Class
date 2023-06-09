#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "CPP_Object_Relationship_03_Teacher.h"
#include "CPP_Object_Relationship_03_Student.h"

class Lecture
{
public:
	Lecture(const std::string& name)
		: name(name)
	{}

	void AssignmentTeacher(Teacher* teacher)
	{
		this->teacher = teacher;
	}

	void AssignmentStudent(Student* student)
	{
		students.push_back(student);
	}

	void Print()
	{
		std::cout << "teacher : " << teacher << std::endl;
		
		for (const auto& student : students)
			std::cout << "student : " << student << std::endl;

		std::cout << std::endl;
	}

private:
	std::string name;
	Teacher* teacher;	// 참조를 통해 만들어야 함.
	std::vector<Student*> students;
};
