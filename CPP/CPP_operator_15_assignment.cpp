#include <iostream>
#include <cassert>

using namespace std;

/*
	깊은 복사 vs 얕은 복사
*/

class MyString
{
public:
	char* data = nullptr;
	int length = 0;

	MyString() = default;

	MyString(const char* const src = "")
	{
		assert(src);

		length = strlen(src) + 1;	// 공백문자 포함
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] = '\0';
	}

	// 깊은 복사
	MyString(const MyString& other)
	{
		cout << "copy constructor" << endl;
		// 깊은 복사를 사용하는 이유는 허상포인터 현상을 해결하기 위해
		// 대신 느림
		this->length = other.length;

		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
				this->data[i] = other.data[i];
		}
		else
		{
			this->data = nullptr;
		}
	}

	// 깊은 복사 대입
	MyString& operator = (const MyString& other)
	{
		if (this == &other) // prevent self-assignment
		{
			return *this; // 본인이 복사 될땐 본인이 할당되는 것을 방지
		}

		if (this->data != nullptr)
		{
			delete[] this->data;
			data = nullptr;
		}

		cout << "copy assignment operator" << endl;

		this->length = other.length;

		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
				this->data[i] = other.data[i];
		}
		else
		{
			this->data = nullptr;
		}

		return *this;
	}

	// 객체 소유권 이전
	MyString(MyString&& other)
	{
		cout << "move constructor" << endl;
		this->data = move(other.data);
		this->length = move(other.length);

		other.data = nullptr;
	}

	MyString& operator = (MyString&& other)
	{
		cout << "move assignment operator" << endl;

		if (this == &other)
			return *this;
		
		if (this->data != nullptr)
		{
			if (other.data != nullptr && this->data != other.data)
			{
				delete[] this->data;
				this->data = nullptr;

				this->data = move(other.data);
			}
		}
		else
		{
			this->data = move(other.data);
		}
		this->length = move(other.length);

		other.data = nullptr;

		return *this;
	}

	~MyString()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
};

int main()
{
	cout << "******************** 1" << endl;
	MyString str("Hello");
	// & 사용시 객체의 주소를 반환, (int*) 로 형변환 해 객체의 값(Hello)의 주소값을 반환
	cout << (int*)str.data << endl;
	cout << str.data << endl << endl;

	cout << "******************** 2" << endl;

	{
		MyString copy(str);					// copy constructor
		copy = str;							// copy assignment constructor
		cout << (int*)copy.data << endl;
		cout << copy.data << endl << endl;
	}

	cout << "******************** 3" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl;
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl;
	}

	cout << "******************** 4" << endl;
	{
		MyString copy(move(str));
		copy = move(str);

		cout << (int*)copy.data << endl;
		cout << copy.data << endl << endl;
	}

	cout << "******************** 5" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl;
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl;
	}

	return 0;
}
