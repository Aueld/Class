#include <iostream>

using namespace std;

int main()
{
	int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };

	for (const auto& number : fibonacci)
		cout << number << " ";

	cout << endl;

	for (const auto& number : { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 })
		cout << number << " ";

	int* test = new int[10];
	//for (auto t : test);

	return 0;
}
