#include <iostream>

using namespace std;

class Student1
{
	int id;
	string name;

public:
	Student1(const int& id, const string& name)
		: id(id), name(name)
	{}

	// 위임 생성자
	Student1(const string& name)
		: Student1(0, name)
	{}
};

class Student2
{
	int id;
	string name;

public:
	// 함수 초기화
	Student2(const int& id, const string& name)
	{
		Initialize(id, name);
	}

	Student2(const string& name)
	{
		Initialize(0, name);
	}

	void Initialize(const int& id, const string& name)
	{

	}
};

int main()
{

	return 0;
}
