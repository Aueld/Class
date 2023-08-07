#include <iostream>

using namespace std;

class Point
{
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

	friend ostream& operator << (ostream& out, Point& pos)
	{
		out << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return out;
	}

	// new 동작 : 생성자의 호출 -> 주소에 맞게 형변환
	void* operator new (size_t size)
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size]; // 필요한 메모리의 크기가 byte 단위로 할당 되기 때문.
		return adr;
	}

	void operator delete(void* adr)
	{
		cout << "operator delete()" << endl;
		//delete[] adr;
		delete[]((char*)adr); // void 포인터 형변환을 허용하지 않는 컴파일러에서 사용 방법
	}

	void* operator new[](size_t size)
	{
		cout << "operator new [] : " << size << endl;

		void* adr = new char[size];
		return adr;
	}

	void operator delete[](void* adr)
	{
		cout << "operator delete[]" << endl;
		delete[] adr;
	}
};

int main()
{
	Point* ptr = new Point(3, 4);
	// new, delete 연산자는 static 함수라서
	// 객체의 실체화가 되지 않아도 호출 가능

	cout << *ptr;

	Point* arr = new Point[3];

	for (int i = 0; i < 3; i++)
	{
		arr[i] = *ptr;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i];
	}

	delete ptr;
	delete[] arr;

	return 0;
}
