#include <iostream>

using namespace std;

class Mother
{
public:
	auto GetA() const
	{
		cout << "Mother" << endl;
		return a;
	}
	void SetA(const int& a)
	{
		this->a = a;
	}

private:
	int a;

protected:
	int b;
	int c;
};

class Child : public Mother
{
public:
	auto GetA() const
	{
		cout << "Child" << endl;
		return Mother::GetA();
	}

	auto GetA2() const
	{
		// 부모클래스의 함수 접근, VC 전용 키워드
		return __super::GetA();
	}

	auto GetB() const
	{
		cout << "Child" << endl;
		return Mother::b;
	}
	auto GetC() const
	{
		cout << "Child" << endl;
		return c;
	}
	void SetBC(const int& b, const int& c)
	{
		this->b = b;
		Mother::b = b;
		Mother::c = c;
	}

private :
	int b;
};

int main()
{
	Child c;

	c.SetA(10);
	cout << c.GetA() << endl << c.Mother::GetA();

	return 0;
}
