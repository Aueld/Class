#include <iostream>

using namespace std;

int Test1(int& a)
{
	a += 10;

	return a;
}
int Test2(int&& a)
{
	return a;
}

int Ref(int& n)
{
	n += 5;

	return n;
}

int main()
{
	/*
		L-value reference &  : 나중에 다시 접근이 가능한 값
		R-value reference && : 식이 끝나면 접근이 불가능한 값
	*/

	int val = 7;
	int& r = val;

	cout << val << ", " << r << endl;
	r = 5;
	cout << val << ", " << r << endl;

	const int& r2 = 10; // 의미 없음

	int&& rr = 10; // R-value reference, 상수화, 한번만 사용


	cout << Test1(rr) << ", " << endl;//Test2(r) << endl;


	cout << endl;

	int n = 0;

	cout << n << endl;

	Ref(n);

	cout << n << endl;

	//----------- Const
	const int* conat a = 5;
	// const 는 왼쪽에 적용, 단 첫 const는 가독성을 위해 오른쪽 적용
	
	return 0;
}
