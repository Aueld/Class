#include <iostream>

using namespace std;

class Unit
{
public:
	Unit(string& name) : name(name) {}

	virtual void Attack() const {}
protected:
	string name;
};

class Warrior : public Unit
{
public:
	Warrior(string name) : Unit(name) {}
	void Attack() const override { cout << "Warrior Attack" << endl; }
};

class Mage : public Unit
{
public:
	Mage(string name) : Unit(name) {}
	void Attack() const override { cout << "Mage Attack" << endl; }
};

int main()
{
	Warrior wars[]{ Warrior("W1"), Warrior("W2"), Warrior("W3"), Warrior("W4"), Warrior("W5"), };
	Mage mages[]{ Mage("M1"), Mage("M2"), Mage("M3"), Mage("M4"), Mage("M5"), };

	for (const auto& war : wars)
		war.Attack();
	for (const auto& mage : mages)
		mage.Attack();

	cout << endl;

	Unit* units[]{
		&wars[0],
		&wars[1],
		&wars[2],
		&wars[3],
		&wars[4],
		&mages[0],
		&mages[1],
		&mages[2],
		&mages[3],
		&mages[4],
	};

	for (const auto& unit : units)
		unit->Attack();

	return 0;
}
