#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd; // 컴퓨터에 생성되는 난수
	mt19937_64 messenne(rd()); // 시드값 초기화 // rd() 확인
	
	uniform_int_distribution<> randNum(1, 10);

	for (int i = 0; i < 10; i++)
		cout << randNum(messenne) << ", ";

	cout << endl;

	return 0;
}
