#include <iostream>

using namespace std;

//상속 접근 지정자      부모 클래스         자식클래스
//public				public				public
//						protected			protected
//						private				접근 불가
//
//protected				public				protected
//						protected			protected
//						private				접근 불가
//
//private				public				private
//						protected			private
//						private				접근 불가

class Base
{
public:
	void Test() {}
	int publicData;

protected:
	int protectedData;

private:
	int privateData;

};

class Derived : private Base
{
public:
	Derived()
	{
		Test();
		publicData;
		protectedData;
		//privateData;
	}
};

class A : public Derived
{
public:
	A()
	{
		//Test();
		//publicData;
		//protedtedData;
		//privateData;
	}
};

int main()
{
	Base base;
	base.publicData;
	
	A a;
	//a.

	return 0;
}
