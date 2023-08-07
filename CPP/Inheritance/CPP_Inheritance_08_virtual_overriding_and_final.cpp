#include <iostream>

using namespace std;

class A // final //, 클래스 뒤에 사용시 더이상 상속 불가능
{
public:
	//override 할 함수는 virtual 키워드 사용
	virtual void Print(int x) { cout << "A" << endl; }
	virtual void doSomethint() {}
};

class B : public A
{
public:
	// 함수 이름, 매개변수 자료형이 다 같아야 override
	void Print(int x) { cout << "B" << endl; }
	void doSomethint() override final {};
};

class C : public A
{
public:
	// 명시적 표현, final 키워드는 마지막 override 함수
	void Print(int x) override final { cout << "C" << endl; }
	void doSomethint() override {}
};

class D : public B
{
public:
	// final 키워드로 인해 불가능
	//void doSomethint() override {}
};

int main()
{
	B b;
	C c;

	b.Print(5);
	b.A::Print(5);
	c.Print(5);

	// 포인터의 자료형으로 판단
	A& a1 = b;
	A& a2 = c;

	a1.Print(5);
	a2.Print(5);

	return 0;
}
