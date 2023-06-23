#include <iostream>
#include <array>

using namespace std;

// nontype parameter
template<typename T, unsigned int SIZE>
class MyArray
{
public:
	MyArray() = default;
	~MyArray() = default;

	T& operator[](int index)
	{
		return arr2[index];
	}

private:
	T arr1[10];
	T arr2[SIZE];
};

int main()
{
	MyArray<int, 10> ma1;
	MyArray<float, 20> ma2;

	for (int i = 0; i < 20; i++)
	{
		ma2[i] = i + 1;
		cout << ma2[i] << " ";
	}
	cout << endl << endl;

	array<int, 20> arr1;
	for (int i = 0; i < 20; i++)
	{
		arr1[i] = i + 1;
		cout << arr1[i] << " ";
	}
	cout << endl << endl;


	return 0;
}
