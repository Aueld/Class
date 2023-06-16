#include <iostream>

using namespace std;

class A
{
public:
	void Print() { cout << "A" << endl; }
	virtual void Print1() { cout << "A1" << endl; }
	virtual void Print2() { cout << "A2" << endl; }
	virtual void Print3() { cout << "A3" << endl; }
	virtual void Print4() final { cout << "A4" << endl; }
};

class B : public A
{
public:
	void Print() { cout << "B" << endl; }
	void Print1() override { cout << "B1" << endl; }
	void Print2() override { cout << "B2" << endl; }
	void Print3() override final { cout << "B3" << endl; }
	//void Print4() { cout << "B4" << endl; }
};

class C : public B
{
public:
	void Print() { cout << "C" << endl; }
	void Print1() override { cout << "C1" << endl; }
	void Print2() override final { cout << "C2" << endl; }
	//void Print3() override final { cout << "C3" << endl; }
};

class D : public C
{
public:
	void Print() { cout << "D" << endl; }
	void Print1() override { cout << "D1" << endl; }
	//void Print2() override final { cout << "D2" << endl; }
};

int main()
{
	A a;
	B b;
	C c;
	D d;

	A& refB = b;
	A& refC = c;
	A& refD = d;

	cout << "------------ A" << endl;
	a.Print();
	a.Print1();
	a.Print2();
	a.Print3();
	a.Print4();
	cout << endl;

	cout << "------------ B" << endl;
	refB.Print();
	refB.Print1();
	refB.Print2();
	refB.Print3();
	refB.Print4();
	cout << endl;

	cout << "------------ C" << endl;
	refC.Print();
	refC.Print1();
	refC.Print2();
	refC.Print3();
	refC.Print4();
	cout << endl;

	cout << "------------ D" << endl;
	refD.Print();
	refD.Print1();
	refD.Print2();
	refD.Print3();
	refD.Print4();
	cout << endl;

	// 가상 함수 테이블에 가상 함수 저장.
	// 클래스당 하나만 생성
	// final 함수가 선언 될때까지 상위 클래스로
	
	return 0;
}
