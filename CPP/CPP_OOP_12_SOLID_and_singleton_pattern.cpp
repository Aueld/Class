#include <iostream>

/*
	SOLID

	1. 단일 책임 원칙 (Single Responsibility Principle)			// 하나의 클래스는 하나의 기능만 가짐
	2. 개방-폐쇄 원칙 (Open Closed Principle)					// 확장에는 열려있되 수정은 불가능
	3. 리스코프 치환 원칙 (Liskov Substitution Principle)		// 자식 클래스는 언제나 부모클래스를 대체 할 수 있음
	4. 인터페이스 분리 원칙 (Interface Segregation Principle)	// 내가 사용 하지 말아야할 인터페이스는 구현하지 않음
	5. 의존 역전 원칙 (Dependency Inverson Principle)			// 의존 관계를 만들때 변화가 없는 것에 의존 해야 함, 구체적인 클래스보단 추상클래스를 의존 해야 함.
*/

/*
	디자인 패턴

	- Singleton pattern
	객체에 인스턴스가 하나만 존재하는 패턴
	개방-폐쇄 원칙 위반, 결합도가 높아지기 때문
	
*/

using namespace std;

class Audio
{
private:
	Audio() {}
	//Audio(const Audio& audio) {};
	Audio(const Audio& audio) = delete; // private 또는 delete 둘 중 하나
	Audio operator=(const Audio& audio) {}
public:
	static Audio& GetInstance()
	{
		static Audio audio;
		return audio;
	}

	void OutSound(string music)
	{
		cout << "소리 출력 : " << music << endl;
	}
};

int main()
{
	//Audio a;

	string bgm("던전");
	Audio::GetInstance().OutSound(bgm);


	return 0;
}
