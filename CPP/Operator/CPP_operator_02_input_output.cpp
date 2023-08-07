#include <iostream>

using namespace std;

//istream >>
//ostream <<

class Point
{
public:
	Point(int x, int y)
		: x(x), y(y)
	{}

	auto GetX() const { return x; }
	auto GetY() const { return y; }

	void Print()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

	//friend - 멤버함수를 전역함수처럼 사용

	friend std::ostream& operator << (ostream& out, const Point& p)
	{
		out << "(" << p.x << ", " << p.y << ")" << endl;
		return out;
	}

	friend std::istream& operator >> (istream& in, Point& p)
	{
		in >> p.x;
		in >> p.y;
		return in;
	}

private:
	int x = 0;
	int y = 0;
};

int main()
{
	Point p1(0, 1), p2(5, 5);

	cout << p1 << ", " << p2 << endl;
	cin >> p1;
	cout << p1 << endl;

	return 0;
}
