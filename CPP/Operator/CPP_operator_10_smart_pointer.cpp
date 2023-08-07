#include <iostream>

using namespace std;

class Point
{
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point 객체 생성" << endl;
	}
	~Point()
	{
		cout << "Point 객체 소멸" << endl;
	}

	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	friend ostream& operator << (ostream& out, Point& pos)
	{
		out << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return out;
	}
};

class SmartPtr
{
	Point* posptr;

public:
	SmartPtr(Point* ptr) : posptr(ptr) {}

	Point& operator* () const // 참조는 하되 변경은 불가
	{
		return *posptr;
	}

	Point* operator-> () const
	{
		return posptr;
	}

	~SmartPtr() // 스마트 포인터를 사용하는 이유
	{
		delete posptr;
	}
};

int main()
{
	// 객체이면서 다른 객체를 가르키는 포인터
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 5));
	SmartPtr sptr3(new Point(4, 8));
	
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(20, 30);
	sptr3->SetPos(30, 40);

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	return 0;
}
