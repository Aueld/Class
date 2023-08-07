#include <iostream>

using namespace std;

class Test
{
	int num1;
	int num2;

public:
	Test(int n1, int n2) : num1(n1), num2(n2) {}

};

class Fraction
{
public:
	Fraction() = default;

	Fraction(int num = 0, int den = 0)
		: numerator(num), denominator(den)
		// 멤버 리스트 초기화
	{
		// 복사는 느림.
		cout << "constructor" << endl;
	}

	// 생성자, 소멸자, 복사 생성자, 복사 대입 연산자, 이동 연산자, 이동 대입 연산자

	// 복사 생성자
	Fraction(const Fraction& fraction)
	{
		cout << "copy constructor" << endl;
	}

	// 복사 대입 연산자
	// =
	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		return *this;
	}

private:
	int numerator;
	int denominator;
};

Fraction CreateFraction()
{
	Fraction temp(5, 2);	// 생성자
	return temp;			// 복사 생성자
}

int main()
{
	Test t1(1, 2);
	Test t2(t1);	// 복사 생성자
	Test t3 = t2;	// 복사 생성자, 선언과 동시에 초기화시 복사 생성자 호출
	t3 = t1;		// 복사 대입 연산자

	Fraction frac(3, 5);
	Fraction copy1(frac);	// 복사 생성자
	Fraction copy2 = frac;	// 복사 생성자
	copy1 = copy2;			// 복사 대입 연산자

	CreateFraction();

	return 0;
}
