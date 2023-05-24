#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>

using namespace std;

// 위치
struct Pos
{
	int x;
	int y;
};

// 보드 클래스
class Board
{
	int** board;	// 보드
	int size;		// 크기

public:
	Board(int size) :size(size)
	{
		// 보드 동적 생성
		board = new int* [size];
		for (int i = 0; i < size; i++)
			board[i] = new int[size];

		for (int x = 0; x < size; x++)
			board[0][x] = 0;
		for (int y = 1; y < size - 1; y++)
		{
			board[y][0] = 0;
			for (int x = 1; x < size - 1; x++)
			{
				board[y][x] = 1;
			}
			board[y][size - 1] = 0;
		}
		for (int x = 0; x < size; x++)
			board[size - 1][x] = 0;

		// 플레이어 셋팅
		board[size - 2][size / 2] = 2;
	}

	~Board()
	{
		// 메모리 해제
		for (int i = 0; i < size; i++)
		{
			delete[](board[i]);
		}
		delete[](board);
	}

	// 보드 출력
	void ShowBoard(int score)
	{
		system("cls");
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				switch (board[i][j])
				{
				case 0: // 벽
					cout << "■";
					break;
				case 1: // 길
					cout << "  ";
					break;
				case 2: // 플레이어
					cout << "○";
					break;
				case 3: // 별
					cout << "☆";
					break;
				default:
					break;
				}
			}
			if (i == 1)
				cout << "<= 별 생성 지점";
			cout << endl;
		}
		cout << "점수 : " << score << endl;
	}

	Pos GetUnitCode(int code)
	{
		Pos temp = { NULL };
		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (board[y][x] == code)
				{
					temp.y = y;
					temp.x = x;
				}
			}
		}

		return temp;
	}

	int** GetBoard()
	{
		return board;
	}

	int GetSize()
	{
		return size;
	}
};

class Star
{
	Pos pos;
	Pos randPos;
	random_device rd;
public:
	void SetStar(Board* board, int randX, int randY)
	{
		randPos = { NULL };
		pos = { randX, randY };

		board->GetBoard()[pos.y][pos.x] = 3;
	}

	void Swap(int** board, Pos sour, Pos dest)
	{
		int temp = board[sour.y][sour.x];
		board[sour.y][sour.x] = board[dest.y][dest.x];
		board[dest.y][dest.x] = temp;

		pos = dest;
	}

	void Action(int** board, int size, Pos dest)
	{
		mt19937_64 gen(rd());
		uniform_int_distribution<int> ran(1, size - 2);

		randPos = { ran(gen), 1 };

		switch (board[dest.y][dest.x])
		{
		case 0: // 벽일때
			// 바꾸는 자리가 길이 아닐때까지
			while (board[randPos.y][randPos.x] != 1)
				randPos = { ran(gen), 1 };
			// 길일때 스왑
			Swap(board, pos, randPos);
			break;
		case 1: // 길일때
			Swap(board, pos, dest);
			break;
		case 2: // 별이 플레이어에 닿을때
			Hit();
			break;
		case 3: // 별끼리 충돌일때
			// 바꾸는 자리가 길이 아닐때까지
			while (board[randPos.y][randPos.x] != 1)
				randPos = { ran(gen), 1 };
			// 길일때 스왑
			Swap(board, pos, randPos);
		default:
			break;
		}
	}

	void Hit()
	{
		cout << "Game Over" << endl;
		exit(0);
	}

	void Move(Board* board)
	{
		// 아래로 한칸씩 이동
		Pos dest = { pos.x, pos.y + 1 };

		Action(board->GetBoard(), board->GetSize(), dest);
	}

	Pos GetPos()
	{
		return pos;
	}
};

class Player
{
	Pos pos;
public:
	Player(Pos pos)
	{
		this->pos.x = pos.x;
		this->pos.y = pos.y;
	}

	Pos GetPos()
	{
		return pos;
	}

	// 이동 가능한지 판단
	bool DoMove(int** board, Pos dest)
	{
		if (board[dest.y][dest.x] > 0)
			return true;

		return false;
	}

	void Swap(int** board, Pos sour, Pos dest)
	{
		int temp = board[sour.y][sour.x];
		board[sour.y][sour.x] = board[dest.y][dest.x];
		board[dest.y][dest.x] = temp;

		pos = dest;
	}

	void Hit()
	{
		cout << "Game Over" << endl;
		exit(0);
	}

	void Action(int** board, Pos dest)
	{
		if (DoMove(board, dest))
		{
			switch (board[dest.y][dest.x])
			{
			case 1: // 길일때
				Swap(board, pos, dest);
				break;
			case 3: // 플레이어가 이동으로 별에 닿을때
				Hit();
				break;
			default:
				break;
			}
		}
	}

	void Move(Board* board, char input)
	{
		Pos dest = { NULL };

		switch (input)
		{
		case 'w':
			dest = { pos.x, pos.y - 1 };
			break;
		case 's':
			dest = { pos.x, pos.y + 1 };
			break;
		case 'a':
			dest = { pos.x - 1, pos.y };
			break;
		case 'd':
			dest = { pos.x + 1, pos.y };
			break;
		default:
			break;
		}

		Action(board->GetBoard(), dest);
	}
};

// 바로 이동 하는 함수, conio.h
int getCommand()
{
	if (_kbhit())
	{
		return _getch();
	}

	return -1;
}

int main()
{
	random_device rd;
	mt19937_64 gen(rd());

	int size = 0, count = 0;
	int score = 0, bonus = 0;

	// 보드 크기가 12 이상 20이하일때
	while (size < 12 || size > 20)
	{
		cout << "게임판 크기 입력 (12 이상 20 이하) : ";
		cin >> size;
	}

	// 보드 생성
	Board board(size);
	Board* boardPtr = &board;
	Player player(board.GetUnitCode(2));

	uniform_int_distribution<int> ranX(1, size - 2);

	Star* star = new Star[size];

	while (true)
	{
		Sleep(80);

		player.Move(boardPtr, getCommand());
		board.ShowBoard(score);

		if (count < size)
		{
			star[count].SetStar(boardPtr, ranX(gen), 1);
			count++;
		}

		for (int i = 0; i < count; i++)
		{
			star[i].Move(boardPtr);
		}

		score += 10 + (bonus % 5);
		if (score > 1000)
			bonus++;
	}

	// 할당한 메모리 해제
	delete[] star;

	return 0;
}
