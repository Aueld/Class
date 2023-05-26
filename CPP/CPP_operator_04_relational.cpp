#include <iostream>

using namespace std;

// < > <= >= == !=

class Won
{
	int value;
	int value1;
public:
	Won(int value, int value1) : value(value), value1(value1) {}
	
	auto GetValue() const { return value; }
	void SetValue(const int& value)
	{
		this->value = value;
		this->value1 = value1;
	}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

	bool operator == (const Won& rhs) const // 내부에서 값이 변경되지 않으면 const 키워드 사용 하는 편이 안전
	{
		return value == rhs.value && value1 == rhs.value1;
	}

	bool operator != (const Won& rhs) const // 내부에서 값이 변경되지 않으면 const 키워드 사용 하는 편이 안전
	{
		// 상단에 선언한 객체간 비교 연산 이용
		return !(*this == rhs);
	}

	bool operator < (const Won& rhs) const
	{
		return value < rhs.value;
	}

	friend bool test(const Won& lhs, const Won& rhs);
};

bool test(const Won& lhs, const Won& rhs)
{
	return lhs.value > rhs.value;
}

int main()
{

	Won w1(10, 10), w2(20, 20);

	if (w1 == w2)
		cout << "같다" << endl;
	else if (w1 != w2)
		cout << "다르다" << endl;

	if (w1 < w2)
		cout << w2 << endl;
	else
		cout << w1 << endl;

	return 0;
}

