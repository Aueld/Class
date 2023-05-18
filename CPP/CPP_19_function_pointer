#include <iostream>
#include <functional>

using namespace std;

bool func(const int& x)
{
	return x > 0;
}

typedef bool(*funcPtr)(const int&);

using funcType = bool(*)(const int&);

int main()
{
	// 반환형 이름 매개변수
	bool (*pf)(const int&) = func;

	// typedef 사용
	funcPtr f = func;

	// using 사용
	funcType f2 = func;

	// 라이브러리 사용
	function<bool(const int&)> f3 = func;

	return 0;
}
