#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Hello"; // std

	cout << str.size() << endl;
	cout << str.length() << endl;

	string a("AAA");
	string b("BBB");

	cout << a + b << endl;

	string c = b + a;
	cout << c << endl;

	c = "CCC";
	c += "DDD";
	cout << c << endl;

	cout << c[2] << endl;

	int* ptr = nullptr;
	int* ptr2(nullptr);
	int* ptr3{nullptr};

	std::nullptr_t nptr;

	return 0;
}
