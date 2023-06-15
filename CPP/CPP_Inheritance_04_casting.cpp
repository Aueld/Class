#include <iostream>

using namespace std;

/*
	Up casting
	- 암시적 형변환, 자식 클래스를 부모 클래스 포인터로 가리키는 것

	Down casting
	- 부모 클래스 포인터가 가리키는 객체를 자식 클래스 포인터로 가리키는 것
*/

class Unit {};

class Hero : public Unit {};
class Mage : public Unit{};
class Assassin : public Unit {};

int main()
{
	// up casting
	Unit* hero = new Hero();
	Unit* mage = new Mage();
	Unit* assassin = new Assassin();

	Unit* unit[3] = { hero, mage, assassin };

	// down casting
	Hero* hero2 = static_cast<Hero*>(hero);	// 명시적 형변환 사용


	return 0;
}
