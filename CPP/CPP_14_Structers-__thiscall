#include <iostream>

using namespace std;

// 구조체는 선언으로 실체화를 하였을때부터 메모리 할당
// 함수는 코드 영역에 존재, 
struct person
{
	int age;
	float weight = 50.0f;
	string name = "AA";

	void __thiscall Print(/* person* */) // 자신을 객체 가짐, 객체에 의한 호출
	{
		// 아직 만들어지지 않은 age 변수 사용
		cout << age << endl;
	}
};

int main()
{
	person p = { 20, 50.2f, "AB" };
	person p2;

	p.Print();
	p2.Print();

	cout << sizeof(p);

	//person::Print(); // 불가능
}
