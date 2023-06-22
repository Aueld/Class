#include <iostream>

using namespace std;

/*
	A
   / \
  B   C
   \ /
    D

	A에 대한 요소에 의해 모호성 발생
*/

class PoweredDevice abstract
{
public:
	PoweredDevice(int power) { cout << "PowerDevice " << power << endl; }

	int base;
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power)
	{
		cout << "Scanner " << scanner << endl;
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		:PoweredDevice(power)
	{
		cout << "Printer " << printer << endl;
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power1, int power2, int power3)
		: Scanner(scanner, power1), Printer(printer, power2)
		, PoweredDevice(power3)
	{

	}
};

int main()
{
	Copier copier{ 1, 2, 3, 4, 5 };
		
	//copier.base; // 모호성 발생

	//copier.Scanner::base;

	cout << &copier.Scanner::PoweredDevice::base << endl;
	cout << &copier.Printer::PoweredDevice::base << endl;

	// 다이아몬드 상속 문제 => 가상 상속으로 해결 가능
	// 가상 상속을 사용해 제일 하단의 자식 클래스의 부모 하나만 선언됨
	
	return 0;
}
