#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
float add(float a, float b) { return a + b; }
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
//void add(int a, int b) { return; } // 불가능

//using integer = int;
//int add(integer a, integer b) { return a + b; } // 불가능, 매개변수, 반환이 동일하기 때문

void output (int value){}
//void output (unsigned int value){} // 모호성 발생
void output (float value){}


int main()
{
	auto result1 = add(5, 4);
	auto result2 = add(5.1f, 23.4f);

	cout << result1 << endl;
	cout << result2 << endl;

	output(1);
	output(10.0f);
	output('c');

	return 0;
}
