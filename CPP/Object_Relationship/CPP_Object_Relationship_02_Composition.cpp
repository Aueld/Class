#include <iostream>

using namespace std;


// part-of

class Point2D
{
public:
	int x;
	int y;
};

class Monster
{
public:
	Monster(int x, int y)
	{
		position.x = x;
		position.y = y;
	}

	// aggregation
	Monster(Point2D* point)
	{
		this->position2 = point;
	}

private:
	string name;
	Point2D position;
	Point2D* position2;
};

int main()
{
	{
		Monster mon1(10, 20);

		// Monster와 Point2D는 Composition 관계
	}

	// aggregation
	Point2D point;
	Monster mon2(&point);
	// 하지만 해당 상황에서는 필요없는 연산

	return 0;
}
