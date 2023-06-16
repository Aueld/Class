#include <iostream>

// 공변 반환형

using namespace std;

class A
{
public:
	virtual A* GetThisPointer() { cout << "A" << endl; return this; }
	void Print() { cout << "A" << endl; }
};

class B : public A
{
public:
	B* GetThisPointer() override { cout << "B" << endl; return this; }
	void Print() { cout << "B" << endl; }
};

int main()
{
	B b;

	b.Print();

	cout << "Adress : " << b.GetThisPointer() << endl;
	cout << "TypeID : " << typeid(b.GetThisPointer()).name() << endl;

	// typeid : 런타임의 타입 아이디 문자열 반환

	cout << endl;

	A& ref = b;
	// 업캐스팅
	ref.Print();
	
	cout << "Adress : " << ref.GetThisPointer() << endl;
	cout << "TypeID : " << typeid(ref.GetThisPointer()).name() << endl;

	/*
		& 참조
		별명을 주는 것. typeid가 다른 이유는 공변 반환형 때문
	*/

	/*
		RTTI : Run Time Type Information
		프로그램 실행중 실시간의 타입 반환
	*/

	return 0;
}
