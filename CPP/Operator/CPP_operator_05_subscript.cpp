#include <iostream>
#include <cassert>

using namespace std;

//[] 배열 첨자 연산자

class IntArray
{
public:
	//int Get(int index) { return list[index]; }
	//void Set(int index, int value) { list[index] = value; }

	//int* GetList() { return list; }

	int& operator[](int index)
	{
		if (index < 0 || index > 10)
		{
			cout << "Array index out of bound exception" << endl;
		}

		assert(index >= 0);

		return list[index];
	}

private:
	int list[3];
};

int main()
{
	{
		//int arr1[3] = { 1, 2, 3 };
		//cout << arr1[-1] << endl;
		//cout << arr1[3] << endl;
		// 경계 검사를 하지 않기 때문에
	}
	{
		//IntArray list;
		//list.Set(0, 1);
		//list.Set(1, 2);
		//list.Set(2, 3);
		//list.Set(3, 4);
		//list.Set(4, 5);
		//list.Set(5, 6);
		//list.Set(6, 7);

		//cout << list.Get(0) << endl;
		//cout << list.Get(1) << endl;
		//cout << list.Get(2) << endl;
		//cout << list.Get(3) << endl;
		//cout << list.Get(4) << endl;
	}

	{
		//IntArray list;
		//auto arr = list.GetList();

		//arr[0] = 1;
		//arr[1] = 2;
		//arr[2] = 3;
		//arr[3] = 4;
		//arr[4] = 5;

		//cout << arr[0] << endl;
		//cout << arr[1] << endl;
		//cout << arr[2] << endl;
		//cout << arr[3] << endl;
		//cout << arr[4] << endl;
	}

	{
		IntArray list;
		list[0] = 1;
		list[1] = 1;
		list[2] = 1;
		list[-1] = 1;
	}

	return 0;
}
