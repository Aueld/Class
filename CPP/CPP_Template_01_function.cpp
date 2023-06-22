#include <iostream>

using namespace std;

// 사용자 정의 자료형
template <typename T>
T GetMax(T x, T y) { return (x > y) ? x : y; }

class Won
{
public:
	Won(int value = 0) : value(value) {}

	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

private:
	int value = 0;
};

int main()
{
	Won a(7), b(3);

	cout << GetMax<int>(1, 5) << endl;
	cout << GetMax<Won>(a, b) << endl;

	cout << GetMax(1.0, 5.4) << endl;
	cout << GetMax(a, b) << endl;
	cout << GetMax(Won(6), Won(2)) << endl;

	return 0;
}
