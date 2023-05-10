#include <iostream>

#define RED 1
#define MUL1(a,b) a + b
#define MUL2(a,b) ((a) + (b))
// 안전한 매크로 함수

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
// 가독성이 많이 떨어짐
// 자료형이 없기 때문에 모든 값이 다 들어올 수 있음
// 디버깅이 되지 않음
// 오류 체크를 하지 않음
// 디버깅이 없는 만큼 속도가 빠름
// 인라인 화

// inline

using namespace std;

// 인라인은 자료형 명시
inline int Max(int a, int b)
{
	return a > b ? a : b;
}
inline float Max(float a, float b)
{
	return a > b ? a : b;
}
// 최신 컴파일러가 함수 내에 코드가 짧으면 자동으로 인라인 함수로 만들어 줌 

int main()
{
	cout << MUL1(1, 2) << endl;
	cout << MUL1(1, 2) * MUL1(1, 2) << endl; // 1 + 2 * 1 + 2
	cout << MUL2(1, 2) * MUL2(1, 2) << endl;
	
	cout << MAX(1, 2) << endl;
	cout << Max(3, 4) << endl;
	cout << Max(3.45f, 4.21f) << endl;

	return 0;
}
