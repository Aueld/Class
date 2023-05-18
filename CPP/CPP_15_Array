#include <iostream>
#include <array>

using namespace std;

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] { 1, 2, 3, 4, 5 };
	
	/*
		STL : Standard Template Libraries
	*/

	array<int, 5> arr3;
	array<int, 5> arr4{1, 2, 3, 4, 5};

	cout << arr4[0] << endl;
	cout << arr4[4] << endl;
	//cout << arr4[-1] << endl;
	//cout << arr4[5] << endl;
	// 예외처리가 되지 않음. 경계범위를 체크 할 수 없음

	cout << arr4.at(0) << endl; // 실행속도는 느려짐
	//cout << arr4.at(5) << endl;

	cout << arr4.size() << endl;

	return 0;
}
