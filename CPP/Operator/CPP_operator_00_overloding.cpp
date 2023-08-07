#include <iostream>

using namespace std;

/*
	. .* :: ?: # ##

	비트 연산
	&	|	^

	사용 하지 않음
*/

class Number
{
	int num;

public:
	Number(int num)
		: num(num)
	{}

	int GetNum()
	{
		return num;
	}

	void SetNum(int num)
	{
		this->num = num;
	}
};

int main()
{
	Number a(10), b(20);

	// 객체 끼리의 연산을 사용 하기 위해
	// 연산자 오버로딩

	return 0;
}
