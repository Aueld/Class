#include <iostream>

using namespace std;

template <class T>
class A
{
public:
	A(const T& value)
		: value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};

// 포인터 클래스 특수화
template <class T>
class A<T*>	// 모든 포인터 타입에 대한 특수화
{
public:
	A(T* value)
		: value(value)
	{}

	void Print()
	{
		cout << *value << endl;
	}

private:
	T* value;
};

int main()
{
	A<int> aint(123);

	aint.Print();

	int temp = 456;
	A<int*> aptr(&temp);
	aptr.Print();	// 포인터 특수화 하지 않을시 주소 출력

	return 0;
}
