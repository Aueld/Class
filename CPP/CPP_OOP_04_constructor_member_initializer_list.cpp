#include <iostream>

using namespace std;

class Data
{
	const int a;
	int b;
	int c;

public:
	//Data(int aData, int bData, int cData)
	//{
	//	a = aData;
	//	b = bData;
	//	c = cData;

	//	// 생성 후 대입, 비효율적, 느림
	//}

	Data(int aData, int bData, int cData)
		: a(aData), b(bData), c(a - cData) // 생성과 동시에 초기화, 연산 가능, const여도 사용 가능
	{	}

	void print()
	{
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
};

int main()
{
	Data data(2, 4, 6);
	data.print();

	return 0;
}
