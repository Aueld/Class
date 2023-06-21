#include <iostream>

using namespace std;

/*
	virtual_function
	자식 클래스에서 재정의를 하지 않아도 기본 동작이 되는 가상 함수

	pure_virtual_function
	순수 가상 함수는 자식 클래스에서 재정의 해야함

	abstract_class
	하나 이상의 순수 가상 함수가 있는 클래스

	interface
	순수 가상 함수로만 이루어진 클래스
*/

#pragma region pure virtual function, abstract class

class Unit abstract
{
public:
	Unit(const string& name) : name(name) {}

	auto GetName() const { return name; }

	virtual void Move() const final
	{
		cout << "move" << endl;
	}

	// 순수 가상 함수
	virtual void Attack() const abstract = 0;
	//virtual void Attack() const abstract;
	//virtual void Attack() const = 0;

private:
	string name;

};

class Mage : public Unit
{
public:
	Mage(string name) : Unit(name) {}

	void Attack() const override
	{
		cout << "마법" << endl;
	}
};

class Hero : public Unit
{
public:
	Hero(string name) : Unit(name) {}

	void Attack() const override
	{
		cout << "물리" << endl;
	}
};

class Prist : public Unit
{
public:
	Prist(string name) : Unit(name) {}
};

int main()
{
	//Unit unit("aa");
	// 순수 가상함수가 있는 클래스는 선언 불가능

	Mage mage("mage");
	mage.Attack();
	
	Hero hero("hero");
	hero.Attack();

	//Prist prist("prist");
	//prist.Attack();
	// 순수 가상함수의 재정의가 없어 사용 불가능

	return 0;
}
