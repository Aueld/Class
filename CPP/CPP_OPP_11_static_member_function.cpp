#include <iostream>

using namespace std;

// 객체가 존재 하지 않음, 정적 멤버 변수만 사용 가능
class Test
{
	int value;
	static int value2;

public:
	Test() {}

	void Temp1() { this->value; }
	void Temp1() const { this->value; }

	static void Temp2() { value2; }

	int t;
};

int Test::value2 = 0;

int main()
{
	Test t1;
	//Test::Temp1(); // 불가능
	t1.Temp1();
	
	Test::Temp2(); // static 함수는 일반적인 함수 취급

	void(*ptr1)() = Test::Temp2; // 함수 포인터 사용 가능

	// 멤버 변수 포인터
	int Test::* ptr2 = &Test::t; // 실체화 된 상태가 아님.
	t1.*ptr2 = 10; // 사용

	// 멤버 함수 포인터
	void(Test:: * ptr3)() = &Test::Temp1;
	(t1.*ptr3)(); // 사용

	return 0;
}
