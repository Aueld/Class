#include <iostream>

using namespace std;

// 클래스 내부에 하나만 존재, 선언은 클래스 내부에서, 초기화는 파일영역에서
class Test
{
public:
	int value = 1;
	static int count; // 내부에서 초기화 불가능 = 클래스는 실체화 되어야만 메모리 할당
};

int Test::count = 1;

// 스태틱 변수는 바로 만들어져야 하는 변수, 헤더에서 선언 후, CPP에서 초기화

int main()
{
	Test t1, t2;
	
	t1.value = 10;
	t2.value = 20;

	cout << &t1.value << ", " << t1.value << endl;
	cout << &t2.value << ", " << t2.value << endl;

	// 모든 객체에서 공유
	t1.count = 30;
	t2.count = 40;

	cout << &t1.count << ", " << t1.count << endl;
	cout << &t2.count << ", " << t2.count << endl;

	cout << &Test::count << ", " << Test::count << endl;

	return 0;
}
