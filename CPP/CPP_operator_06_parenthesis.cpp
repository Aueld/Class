#include <iostream>

using namespace std;

//() 연산자, 객체를 함수처럼 사용하고 싶을때

class Counter
{
public:
	int operator()(int i)
	{
		return count += i;
	}
private:
	int count = 0;

};

class Point
{
	int xPos, yPos;

public:
	Point(int x = 0, int y = 0) : xPos(x), yPos(y)
	{}

	Point operator+(const Point& pos) const
	{
		return Point(xPos + pos.xPos, yPos + pos.yPos);
	}

	friend ostream& operator << (ostream& out, const Point& pos)
	{
		out << '[' << pos.xPos << ", " << pos.yPos << ']' << endl;
		return out;
	}
};

class Adder
{
public:
	int operator()(const int& n1, const int& n2)
	{
		return n1 + n2;
	}
	double operator()(const double& n1, const double& n2)
	{
		return n1 + n2;
	}
	Point operator()(const Point& n1, const Point& n2)
	{
		return n1 + n2;
	}
};

int main()
{
	Counter ct;

	ct.operator()(1);
	cout << ct(10) << endl; // Functor(Function Object)
	cout << ct(20) << endl;
	cout << ct(30) << endl;

	{
		Adder adder;

		cout << adder(1, 5) << endl;
		cout << adder(1.1, 5.5) << endl;
		cout << adder(Point(3, 4), Point(7, 8)) << endl;
	}

	return 0;
}
