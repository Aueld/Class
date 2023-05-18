#include <iostream>

using namespace std;
// 선언 하고 시작하는 것은 위험한 방법임.
// 이름 충돌이 일어날 확률이 높아짐.
// 차라리 지역 안에서 선언하는 방법 추천.

namespace A
{
	void exFunc()
	{
		cout << "A 정의 함수" << endl;
	}
}

namespace B
{
	void exFunc()
	{
		cout << "B 정의 함수" << endl;
	}
}

// 중첩 이름 공간
namespace myNameSpace1
{
	int a;
	namespace AA
	{
		namespace BB
		{
			namespace CC
			{
				int c;
			}
		}
	}
}

namespace myNameSpace2
{
	int a;

}

// 중복 이름 공간
namespace myNameSpace1
{
	int hello;
} // 이름이 곂치면 같은 이름 공간으로 취급.

// 데이터 영역에 전역 변수
int Aa = 2;

int main()
{
	A::exFunc();
	B::exFunc();

	// 중첩 이름 공간 접근
	myNameSpace1::AA::BB::CC::c = 5;
	myNameSpace1::a = 10;
	myNameSpace2::a = 20;

	// a = 10; 변수의 모호성으로 불가능
	{ // 이름 공간 선언 하지 않고 바로 사용
		using namespace myNameSpace1;

		a = 5;
		myNameSpace2::a = 10;

		using namespace myNameSpace2;

		// a = 10; // 모호성으로 접근 불가능
	}

	int Aa = 10;
	cout << Aa << endl;
	// 전역 변수와 지역 변수가 있으면 지역 변수가 더 우선 순위

	cout << ::Aa << endl;
	// 전역 변수 출력


	return 0;
}
