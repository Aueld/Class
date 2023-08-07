#include <iostream>

using namespace std;

#pragma region friend global function
//class A
//{
//private:
//	int value = 1;
//
//	// 전역 변수에서 private 접근 가능
//	friend void doSomething1(const A& a);
//	
//	// friend 키워드 사용시 전역함수 취급
//	friend void doSomething2(const A& a)
//	{
//		cout << a.value << endl;
//	}
//
//};
//
//void doSomething1(const A& a)
//{
//	cout << a.value << endl;
//}
//
//int main()
//{
//
//
//
//	return 0;
//}

#pragma endregion


#pragma region friend member class
// 다른 클래스의 멤버에 접근 하고 싶을때

//class B; // 전방 선언
//
//class A
//{
//public:
//	void attack(B& b);
//	//{ // b의 내부에 대한 정보가 없어 오류가 발생, 외부에서 정의
//	//	cout << "b의 체력 : " << b.hp << endl;
//	//}
//};
//
//class B
//{
//	int hp = 100;
//
//	friend void A::attack(B& b);
//};
//
//int main()
//{
//	A a;
//	B b;
//
//	a.attack(b);
//
//	return 0;
//}
//
//void A::attack(B& b)
//{
//	cout << "b의 체력 : " << b.hp << endl;
//	cout << "공격" << endl;
//	b.hp -= 10;
//	cout << "b의 체력 : " << b.hp << endl;
//}

#pragma endregion


#pragma region friend class
// 다른 클래스 전체에 접근 하고 싶을때

class A
{
public:
	void PrintBValue1(class B& b);
	void PrintBValue2(class B& b);
};

class B
{
	friend A;

private:
	int value1 = 10;
	int value2 = 20;
};

void A::PrintBValue1(B& b)
{
	cout << b.value1 << endl;
}

void A::PrintBValue2(B& b)
{
	cout << b.value2 << endl;
}


int main()
{
	A a;
	B b;
	a.PrintBValue1(b);
	a.PrintBValue2(b);

	return 0;
}

#pragma endregion

/*
	friend 많이 사용시 은닉이 불가능해짐
	사용시 주의할 것
*/
