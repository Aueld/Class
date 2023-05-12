#include <iostream>

using namespace std;

struct Test
{
	int a;
	int b;
	std::string str;

	void printNum()
	{
		cout << "Hello";
	}
};

int main()
{
	{
		// C
		int* ptr = (int*)malloc(5 * sizeof(int));
		//if(ptr != NULL) {}
		free(ptr);
		ptr = NULL; // 허상 포인터 이미 해제된 주소 공간에 값이 남아 있는 현상

		// CPP
		int* ptr1 = new int;
		delete ptr1;

		int* ptr2 = new int(7);
		delete ptr2;

		int* ptr3 = new int{ 7 };
		delete ptr3;

		int* ptr4 = new(std::nothrow) int{ 7 }; // 할당 실패시 NULL

		if (ptr4 == nullptr)
			cout << "Error" << endl;

		if (ptr4 != nullptr)
			delete ptr4;

		int* arr = new int[10]{ 1, 2, 3, 4, 5, 6, };
		delete[] arr; // 배열 할당 해제

		// 이차원 배열 포인터
		int** ptr_arr = new int* [3];
		ptr_arr[0] = new int[5];
		ptr_arr[1] = new int[5];
		ptr_arr[2] = new int[5];

		for (int i = 0; i < 3; i++) // 해제
			delete[] ptr_arr[i];
		delete[] ptr_arr;
	}

	Test* test = new Test;

	test->a = 10;
	test->b = 20;
	test->str = "Hello";
	test->printNum();

	delete test;

	//Test* testc = (Test*)malloc(sizeof(Test));
	// string 과 함수에서 예외 발생
	/*
		malloc 함수
		POD 타입에 대해서만 크기를 할당

		POD : Plain Old Data // 연속된 자료형
	*/


	return 0;
}

