#include <iostream>

using namespace std;

class A
{
public:
	void print()
	{
		cout << "Print" << endl;
	}
};

int main()
{
	// 익명 객체
	A().print();

	return 0;
}
