#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Hello World" << endl;
	cout << "Hello World" << "\n";
	// endl은 \n보다 느림

	int a = 0;
	
	cin >> a;

	cout << "a : " << a << "\n";
	cout << oct << a << endl;
	cout << dec << a << endl;
	cout << hex << a << endl;

	// 진수 표시 설정 킴
	cout << showbase << showpos;
	cout << oct << a << endl;
	cout << dec << a << endl;
	cout << hex << a << endl;

	// 진수 표시 설정 끔
	cout << noshowbase << noshowpos;

	bool isTrue = true;
	bool isFalse = false;

	cout << isTrue << " " << isFalse << endl;

	// bool값 알파벳 표시
	cout << boolalpha;
	cout << isTrue << " " << isFalse << endl;
	cout << noboolalpha;

	// -------------------------------------------

	// C 언어 초기화 방법
	// 복사 초기화, copy initialization
	int x = 10;
	// CPP 언어 초기화 방법
	int y(10); // 직접 초기화, direct initialization
	int z{ 10 }; // 유니폼 초기화, uniform initialization, 형변환 불가능

	/*
		limits
	*/

	cout << numeric_limits<int>::min() << endl;
	cout << numeric_limits<int>::max() << endl;
	cout << numeric_limits<float>::min() << endl;
	cout << numeric_limits<float>::max() << endl;

	/*
		Casting
	*/

	int i = 10;
	float k = 10.1f;

	cout << k << endl;
	cout << (int)k << endl; // C
	cout << int(k) << endl; // CPP

	// 안전하며 자주 사용하는 방법
	cout << static_cast<int>(k) << endl;

	/*
		const vs constexpr
	*/
	const int c1(123);
	//c1 = 5;
	// const는 런타임때 상수로 정해짐 = 변수로 초기화 가능
	int i1 = 10;
	const int c2 = i1;

	int arr1[c1];
	//int arr2[c2];
	// 변수로 초기화한 상수는 배열의 인덱스로 사용 불가능

	// constexpr은 런타임 전에 먼저 상수로 정해짐
	constexpr float PI1 = 3.14f;
	float PI2 = 3.14f;
	//constexpr float PI3 = PI2; // 불가능
	constexpr int arrSize = 10;
	int arr[arrSize];



	return 0;
}
