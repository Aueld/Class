#include <iostream>

using namespace std;

class Test
{
public:
	Test()
	{
		cout << "Constructor" << endl;
	}

	~Test() // 메모리 해제 같은 소멸시 해야 할 것 들
	{
		cout << "Destructor" << endl;
	}
};

class IntArray
{
	int* arr = nullptr;
	int length = 0;

public:
	IntArray(const int& intLength)
	{
		length = intLength;
		arr = new int[length];
		cout << "constructor" << endl;
	}
	
	~IntArray()
	{
		cout << "Destructor" << endl;
		delete[] arr;
	}
};

int main()
{
	Test t;
	cout << "_______________1" << endl;
	{
		cout << "_______________2" << endl;
		Test t1;
		cout << "_______________3" << endl;
	}
	cout << "_______________4" << endl;

	return 0;
}
