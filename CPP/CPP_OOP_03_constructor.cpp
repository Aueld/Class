#include <iostream>

using namespace std;

class Fraction
{
	int numerator = 10;
	int denominator = 10;

public:
	Fraction() // 생성자, 초기화 할때 사용
	{
		cout << "Constructor" << endl;
	}

	Fraction(int n, int d)
	{
		cout << "Constructor2" << endl;
	}

	// 복사 생성자, 같은 타입의 클래스를 매개변수로 가짐
	Fraction(const Fraction& data)
	{
		cout << "Comstructor3" << endl;
	}
};

int main()
{
	Fraction frac;
	Fraction frac1(1, 2);
	Fraction frac2{ 1, 2 };
	Fraction frac3(frac2);

	// 이동 생성자, 같은 타입의 클래스를 그대로 사용
	Fraction frac4(move(frac1));



	return 0;
}
