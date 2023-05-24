#include <iostream>

using namespace std;

/*
	// 타입 추론
	auto
	매개변수로는 사용 불가능
*/

auto add(int x, int y) -> int; // 명시적 표현

int main()
{
	int a = 10;
	float b = 3.14f;

	auto re = a + b;

	cout << re << endl;

	return 0;
}

auto add(int x, int y) -> int
{
	return x + y;
}
