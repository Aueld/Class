#include <iostream>

using namespace std;

#pragma region this Pointer
/*
class Test1
{
	int num;

public:
	Test1(int n) : num(n)
	{
		cout << "num : " << num << endl;
		cout << "num address  : " << &num << endl;
		cout << "this address : " << this << endl;
	}

	void ShowTest1Data()
	{
		cout << num << endl;
	}

	// 객체의 포인터 반환
	Test1* GetThisPointer()
	{
		return this;
	}
};

class Test2
{
	int a;
	int b;
	int c;

public:
	Test2() {}
	~Test2() {}

	auto GetA()
	{
		cout << this << endl;
		return a;
	}

	void SetA(const int& a)
	{
		// name hiding 현상, this 사용으로 해결
		this->a = a;
	}
};

int main()
{
	Test1 t1(100);
	Test1* ptr1 = t1.GetThisPointer();
	cout << ptr1 << endl;
	ptr1->ShowTest1Data();

	Test1 t2(200);


	return 0;
}
*/
#pragma endregion

#pragma region chaning member function

class Calc
{
	int value;

public:
	Calc(int value) : value(value){}

	/*
	void Add(int value) { this->value += value; }
	void Sub(int value) { this->value -= value; }
	void Mul (int value) { this->value *= value; }
	void Div(int value) { this->value /= value; }
	void Mod(int value) { this->value %= value; }
	*/
	
	// 참조에 의한 호출
	// & 반환, 객체를 참조 할 수 있는 정보를 전달
	Calc& Add(int value) { this->value += value; return *this; }
	Calc& Sub(int value) { this->value -= value; return *this; }
	Calc& Mul(int value) { this->value *= value; return *this; }
	Calc& Div(int value) { this->value /= value; return *this; }
	Calc& Mod(int value) { this->value %= value; return *this; }

	void ShowValue()
	{
		cout << value << endl;
	}
};

int main()
{
	cout << "a" << "b" << "c" << "d" << endl;

	Calc calc(10);
	calc.Add(5);
	calc.Sub(2);

	calc.ShowValue();

	calc.Add(2).Mod(2).Mul(4).Sub(10);

	calc.ShowValue();

	// ananimous object, 익명 객체
	// 한번 사용하고 재활용 불가능
	Calc(20).Add(1).Div(3).ShowValue();

	return 0;
}

#pragma endregion
