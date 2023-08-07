#include <iostream>

using namespace std;

/*
	static cast			// 정적 형변환, 명시적 형변환
	const cast
	reinterpret cast	// 포인터까지 형변환
	dynamic cast		// 다운캐스팅 할 때 사용, 비교적 안전한 형변환, 하지만 런타임때 검사해서 느림

	// 캐스트를 사용 하는 상황이 좋지는 않은 상황, 되도록 사용하지 않는것이 좋은 코드

	부모 -> 자식 : 업캐스팅
	부모 클래스 포인터 -> 자식 클래스 포인터 : 다운캐스팅
*/

class Base
{
public:
	virtual void Print() { cout << " Base " << endl; }

	int base = 0;
};

class Derived1 : public Base
{
public:
	virtual void Print() { cout << " Derived1 " << endl; }

	int d1 = 1;
};

class Derived2 : public Base
{
public:
	virtual void Print() { cout << " Derived2 " << endl; }

	int d2 = 2;
};

void DoSomething(Base* b)
{
	//Derived2* baseToD2 = static_cast<Derived2*>(b);
	Derived2* baseToD2 = dynamic_cast<Derived2*>(b);

	baseToD2->d2 = 777;
}

int main()
{
	Derived1 d1;
	Derived2 d2;
	Base* base = &d1; //upcasting

	//downcasting
	//Derived1* baseToD1 = static_cast<Derived1*>(base);
	Derived1* baseToD1 = dynamic_cast<Derived1*>(base);

	// 정적 형변환시 다른 클래스의 값을 변경하는 경우가 생길 수 있음.
	// 클래스간 데이터 수정까지 가능해짐
	DoSomething(&d1);
	cout << d1.d1 << endl;

	// 동적 형변환시 런타임 검사에서 걸림.

	return 0;
}
