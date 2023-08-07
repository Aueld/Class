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

class Minute
{
	int minute;
public:
	Minute(int minute) : minute(minute) {}

	friend ostream& operator << (ostream& out, Minute& m)
	{
		out << m.minute << endl;
		return out;
	}
};

class Second
{
	int second;
public:
	Second (int second) : second(second) {}

	friend ostream& operator << (ostream& out, Second& s)
	{
		out << s.second << endl;
		return out;
	}
};

class MilliSecond
{
	int milliSecond;
public:
	MilliSecond(int milliSecond) : milliSecond(milliSecond) {}

	friend ostream& operator << (ostream& out, MilliSecond& ms)
	{
		out << ms.milliSecond << endl;
		return out;
	}
};

class Hour
{
	int hour;
public:
	Hour(int hour) : hour(hour) {}

	friend ostream& operator << (ostream& out, Hour& h)
	{
		out << h.hour << endl;
		return out;
	}

	operator Minute()
	{
		return hour * 60;
	}

	operator Second()
	{
		return hour * 60 * 60;
	}

	operator MilliSecond()
	{
		return hour * 60 * 60 * 1000;
	}
};

void PrintHour(Hour hour)
{
	cout << hour;
}

void PrintMinute(Minute minute)
{
	cout << minute;
}

void PrintSecond(Second second)
{
	cout << second;
}

void PrintMilliSecond(MilliSecond ms)
{
	cout << ms;
}

int main()
{
	//Won w(10);

	//Print(1);
	//Print(w);

	//Point p(1.0f, 2.0f, 3.0f);
	//PrintPoint(p);

	Hour h(1);
	PrintHour(h);
	PrintMinute(h);
	PrintSecond(h);
	PrintMilliSecond(h);

	return 0;
}
