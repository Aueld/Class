#include <iostream>

using namespace std;

/*
	RVO : Return Value Optimization
	// 객체의 반환

	NRVO : Named Return Value Optimization
	// 이름 있는 객체의 반환
*/

class Test
{
	int value1;
	int value2;
public:
	static int count;

public:
	Test(int value)
		: value1(value), value2(count++)
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	Test(const Test& rhs)
		:value1(rhs.value1), value2(count++)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}
};

int Test::count = 1;

Test MakeRVO(int value)
{
	return Test(value);
}

Test MakeNRVO(int value)
{
	Test test(value);
	return test;
}

int main()
{
	cout << "RVO" << endl;
	Test t1 = MakeRVO(1);

	cout << "NRVO" << endl;
	Test t2 = MakeNRVO(2);


	return 0;
}
