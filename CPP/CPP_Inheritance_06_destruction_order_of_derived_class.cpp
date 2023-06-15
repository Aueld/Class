#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A constructor" << endl;
	}
	~A()
	{
		cout << "A destructor" << endl;
	}

private :
	// 내부 단편화 문제를 완화할때는 가장 작은 자료형이 위로 가게 작성
	int a;
};

class B : public A
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}
	~B()
	{
		cout << "B destructor" << endl;
	}
private:
	double b;
};

int main()
{
	B b;

	cout << sizeof(A) << endl;	
	cout << sizeof(B) << endl;	// 메모리 내부 단편화

	return 0;
}
