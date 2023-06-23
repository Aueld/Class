#include <iostream>

using namespace std;

template <typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

// 특정 자료형에 대한 예외처리
template <>
char GetMax(char x, char y)
{
	cout << "warning : comparing chars" << endl;

	return NULL;
}

// 클래스의 경우
template <class T>
class Storage
{
public:
	Storage(T value)
		: value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};

template <>
void Storage<double>::Print()
{
	cout << "double : " << value << endl;
}

int main()
{
	cout << GetMax(1, 2) << endl;
	cout << GetMax('d', 'x') << endl;

	Storage<int> sto1(5);
	Storage<double> sto2(3);

	sto1.Print();
	sto2.Print();

	return 0;
}
