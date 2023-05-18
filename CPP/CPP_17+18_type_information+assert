#include <iostream>

using namespace std;

/*
	Template
*/

template <typename T>
T add(T a, T b)
{
	return a + b;
}

int main()
{
	cout << add(10, 20) << endl;
	cout << add(10.5f, 20.5f) << endl;
	cout << add(22.5, 33.5) << endl;

	return 0;
}

// ----

#include <iostream>
#include <cassert>
// 디버깅 모드에서 도움

using namespace std;

int main()
{
	int x;
	cin >> x;

	// 런타임 도중 체크
	assert(x != 0 && "x is 0"); // false일때 프로그램 오류 강제 발생, "문장 설정 가능"
	
	// 컴파일 직전 체크
	//static_assert(false);

	const int x1 = 6; // = 8;
	const int y1 = 7;

	static_assert(x1 < y1, "x1 is bigger than y1");

	return 0;
}
