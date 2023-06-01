#include <iostream>

using namespace std;

// * ->

class Number
{
	int num;

public:
	Number(int n) : num(n) {}

	void ShowData()
	{
		cout << num << endl;
	}

	Number* operator -> () // 주소값 반환이 목적
	{
		return this;
	}

	Number& operator * () // 값 반환
	{
		return *this;
	}
};

int main()
{
	Number num(20);
	num.ShowData();
	
	*num = 30; // 생성자에 대입
	num.ShowData();
	num->ShowData(); // num.operator->()->ShowData();

	num.operator*() = 50;
	num.operator*().ShowData();

	return 0;
}
