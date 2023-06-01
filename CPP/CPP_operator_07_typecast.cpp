#include <iostream>

using namespace std;

class Won
{
	int value = 0;
public:
	Won(int value = 0) : value(value) {}

	operator int() // operator 자료형()
	{
		return value;
	}
};

class Point
{
	float x;
	float y;
	float z;

public:
	Point(float x, float y, float z) : x(x), y(y), z(z) {}

	operator float* () // * 사용으로 연속적인 데이터 취급 가능
	{
		return &x;
	}
};

void PrintPoint(float points[3])
{
	cout << points[0] << ", " << points[1] << ", " << points[2] << endl;
}

void Print(int val)
{
	cout << val << endl;
}

int main()
{
	Won w(10);

	Print(1);
	Print(w);

	Point p(1.0f, 2.0f, 3.0f);
	PrintPoint(p);

	return 0;
}
