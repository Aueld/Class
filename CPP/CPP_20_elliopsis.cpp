#include <iostream>
#include <cstdarg>

using namespace std;

// 가변 인자 함수
double findAverage(int count, ...)
{
	double sum = 0;

	// 가변 인자 목록
	va_list lists;

	va_start(lists, count);

	for (int i = 0; i < count; i++)
	{
		sum += va_arg(lists, int); // 접근 할 타입
	}

	va_end(lists); // 가변 인자 목록 초기화
	
	return sum / count;
}

int main()
{
	cout << findAverage(5, 1, 2, 3, 3, 4) << endl;
	cout << findAverage(3, 4, 41, 22) << endl;
	cout << findAverage(3, 1, 2, 3, 3, 4) << endl; // count 갯수 만큼만 실행

	return 0;
}
