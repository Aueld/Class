#include <iostream>
// const 멤버함수

using namespace std;

class Data
{
	int value1;
	mutable int value2;

public:
	Data() : value1(0), value2(0) {}

	int& GetValue() { cout << "not const" << endl; return value1; }

	// 오버로딩 가능
	// &가 붙으면 참조하는 형태, 우회적으로 수정 불가, 값 변경 불가
	const int& GetValue() const { cout << "const" << endl; return value1; }

	//void SetValue(int value) const { this->value1 = value; } // 수정 불가능
	const void SetValue(int value) const { this->value2 = value; } // mutable 붙으면 수정 가능
	// 상수 함수에서도 수정 할 수 있는 변수

};

void Print(const Data& data)
{
	data.GetValue();
}

int main()
{
	Data data1;
	const Data data2;

	data1.GetValue();
	data2.GetValue(); // 상수 함수만 가능

	//const 붙여서 사용하는 방법이 더 나은 방법
	Print(data1);
	Print(data2);


	return 0;
}#include <iostream>
// const 멤버함수

using namespace std;

class Data
{
	int value1;
	mutable int value2;

public:
	Data() : value1(0), value2(0) {}

	int& GetValue() { cout << "not const" << endl; return value1; }

	// 오버로딩 가능
	// &가 붙으면 참조하는 형태, 우회적으로 수정 불가, 값 변경 불가
	const int& GetValue() const { cout << "const" << endl; return value1; }

	//void SetValue(int value) const { this->value1 = value; } // 수정 불가능
	const void SetValue(int value) const { this->value2 = value; } // mutable 붙으면 수정 가능
	// 상수 함수에서도 수정 할 수 있는 변수

};

void Print(const Data& data)
{
	data.GetValue();
}

int main()
{
	Data data1;
	const Data data2;

	data1.GetValue();
	data2.GetValue(); // 상수 함수만 가능

	//const 붙여서 사용하는 방법이 더 나은 방법
	Print(data1);
	Print(data2);


	return 0;
}
