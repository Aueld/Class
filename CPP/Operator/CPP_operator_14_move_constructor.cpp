#include <iostream>

using namespace std;

class Test
{
public:
	Test() = default;
	Test(const Test& t)		// L value
	{}

	Test(const Test&& t)	// R value, 한번만 사용 됨
	{}

	Test& operator = (const Test&& t)
	{}
	// 객체의 소유권 이동, 객체를 다른 객체로 이동하기 위해 사용
};

int main()
{
	Test t;
	Test t2(t);

	Test t3(std::move(t));
	t2 = std::move(t);

	return 0;
}
