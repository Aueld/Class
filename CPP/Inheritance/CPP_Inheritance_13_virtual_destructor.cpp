#include <iostream>

using namespace std;

class Base
{
public:
	Base() { cout << "Base()" << endl; }
	virtual ~Base() { cout << "~Base()" << endl; }
	//virtual ~Base() {}
};

class Derived : public Base
{
public:
	~Derived()
	{
		cout << "~Derived()" << endl;
		//TODO : arr 동적 메모리 해제
	}

private:
	int* arr = nullptr;
};

int main()
{
	Base b;

	Base* base = new Derived;
	// 업캐스팅했을때 하위 클래스의 소멸자가 은닉되어
	// 메모리 해제가 되지 않아 메모리 누수 현상이 일어남.
	// 가상 소멸자로 해결 가능.
	delete base;

	// 부모 클래스 소멸자엔 virtual 키워드를 붙여 사용하는 것을 권장

	return 0;
}
