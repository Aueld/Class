#include <iostream>

using namespace std;

class Fraction
{
public:
	Fraction() = default;

	Fraction(int num, int den)
		: numerator(num), denominator(den)
		// 멤버 리스트 초기화
	{
		// 복사는 느림.
		cout << "constructor" << endl;
	}

	// 생성자, 소멸자, 복사 생성자, 복사 대입 연산자, 이동 연산자, 이동 대입 연산자

	// 복사 생성자
	Fraction(const Fraction& fraction)
		: numerator(fraction.numerator), denominator(fraction.denominator)
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

	// 변환 생성자
	explicit Fraction(int a)	// 인자 하나만 받는 상황일때 변환 생성자, explicit 사용시 암시적 형변환 호출 방지
		:numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}

	friend std::ostream& operator << (ostream& out, Fraction& frac)
	{
		out << frac.numerator << " / " << frac.denominator << endl;
		return out;
	}

private:
	int numerator;
	int denominator;
};

void PrintFraction(Fraction frac) // 복사 발생
{
	cout << frac;
}

int main()
{
	Fraction frac1(10, 20);
	Fraction frac2(frac1);

	Fraction frac3(1);
	Fraction frac4('a');
	Fraction frac5(3.14f);

	cout << endl;

	PrintFraction(frac1);
	PrintFraction(frac2);
	PrintFraction(frac3);
	PrintFraction(frac4);
	PrintFraction(frac5);

	// explicit 변환 생성자를 불러올 수 없기 때문에 오류
	//PrintFraction('A');
	//PrintFraction(1);
	//PrintFraction(3.14f);

	Fraction frac6(static_cast<int>('A'));
	// static_cast 사용시 형변환 가능

	return 0;
}
