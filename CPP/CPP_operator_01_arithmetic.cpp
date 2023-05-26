#include <iostream>

using namespace std;

#pragma region 1. 전역함수에 의한 연산자 오버로딩
//class Won
//{
//public:
//	Won(int value) : value(value) {}
//
//	int GetValue()
//	{
//		return value;
//	}
//
//private:
//	int value;
//
//	friend int operator+(const Won& lhs, const Won& rhs);
//
//	// 생성자 내부 계산
//	friend Won operator-(const Won& lhs, const Won& rhs);
//};
//
//int main()
//{
//
//	Won l(10), r(20);
//
//	int result1 = l + r;
//
//	cout << result1 << endl;
//
//	Won result2(l - r);
//
//	cout << result2.GetValue() << endl;
//
//	return 0;
//}
//
//int operator+(const Won& lhs, const Won& rhs)
//{
//	return lhs.value + rhs.value;
//}
//
//Won operator-(const Won& lhs, const Won& rhs)
//{
//	return lhs.value - rhs.value;
//}
#pragma endregion

#pragma region 2. 멤버함수에 의한 연산자 오버로딩
class Won
{
public:
	Won(int value) : value(value) {}

	int GetValue() const { return value; }

	// l과 r => l.operator+(r)
	int operator+(const Won& rhs)
	{
		return value + rhs.value;
	}

	Won operator-(const Won& rhs)
	{
		return value - rhs.value;
	}

private:
	int value;
};

int main()
{
	Won l(10), r(20);

	int result1 = l + r;
	cout << result1 << endl;

	Won result2 = l - r;
	cout << result2.GetValue() << endl;

	return 0;
}


#pragma endregion
