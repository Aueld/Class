#include <iostream>

using namespace std;

template <class T>
class A
{
public:
	A(const T& input){}

	void DoSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void Test() {}
};

// 같은 이름으로 선언
template<>
class A<char>
{
public:
	A(const char& input) {}

	void DoSomething()
	{
		cout << "char type specialization" << endl;
	}
};


int main()
{
	A<int> aint(10);
	A<double> adouble(10.0);
	A<char> achar('a');

	aint.DoSomething();
	adouble.DoSomething();
	achar.DoSomething();

	aint.Test();
	//acher.Test();

	return 0;
}
