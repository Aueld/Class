#include <iostream>

using namespace std;

class Character
{
public:
	Character(string&& name) // R-value 변경하지 않겠다는 표현
		: name(name)
	{}

	// 중첩 형식
	enum class Movement
	{
		Idle,
		Walk,
		Run,
		Count
	};
	// enum 클래스의 마지막 부분 Count를 통해 배열 선언의 값으로 사용 가능
	// static_cast<int>(enum::Count)

	// 캐릭터의 이동상태 변경
	void SetCharacterMovement(enum class Movement inMove)
	{
		movementState = inMove;
		speed = movementSpeed[static_cast<int>(inMove)];
	}

	void PrintCurrentMovementState()
	{
		switch (movementState)
		{
		case Character::Movement::Idle:
			cout << name << "의 현재 이동 상태 : Idle,\t현재 속도 : " << speed << endl;
			break;
		case Character::Movement::Walk:
			cout << name << "의 현재 이동 상태 : Walk,\t현재 속도 : " << speed << endl;
			break;
		case Character::Movement::Run:
			cout << name << "의 현재 이동 상태 : Run,\t현재 속도 : " << speed << endl;
			break;
		}
	}

private:
	string name;

	const int movementSpeed[static_cast<int>(Movement::Count)] = { // 형변환
		0,
		200,
		500
	};

	enum class Movement movementState = Movement::Idle;

	int speed = movementSpeed[static_cast<int>(Movement::Idle)];
};

int main()
{
	Character player(string("Player"));

	player.PrintCurrentMovementState();
	player.SetCharacterMovement(Character::Movement::Walk);
	player.PrintCurrentMovementState();
	player.SetCharacterMovement(Character::Movement::Run);
	player.PrintCurrentMovementState();


	return 0;
}
