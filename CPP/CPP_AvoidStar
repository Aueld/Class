#include <iostream>
#include <windows.h>

using namespace std;

#define WIDTH 15
#define HEIGHT 20

struct Star
{
	int x;
	int y;
	bool isStar;
};

struct Player
{
	int x;
	int y;
};

void gotoxy(int x, int y)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Star star[WIDTH];
Player player;

void initialize()
{
	for (int i = 0; i < WIDTH; i++)
	{
		star[i].isStar = false;
	}

	player.x = WIDTH / 2;
	player.y = HEIGHT;
}

void createStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar == false)
		{
			star[i].x = rand() % WIDTH;
			star[i].y = 0;
			star[i].isStar = true;
			return;
		}
	}
}

void moveStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar)
		{
			star[i].y++;
		}
	}
}
int score;
void destroyStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar && star[i].y > HEIGHT)
		{
			star[i].isStar = false;
			score += 100;
			cout << "\n점수 : " << score << endl;
		}
	}
}

bool collidPlayer()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar && star[i].y == player.y && star[i].x == player.x)
		{
			cout << endl;
			cout << "점수 : " << score << endl;
			return true;
		}
	}
	return false;
}

int isKeyDown(int key)
{
	return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

void movePlayer()
{
	if (isKeyDown(VK_LEFT))
		player.x--;
	if (isKeyDown(VK_RIGHT))
		player.x++;
	if (isKeyDown(VK_UP))
		player.y--;
	if (isKeyDown(VK_DOWN))
		player.y++;

	if (player.x < 1)
		player.x = 1;
	if (player.x > WIDTH - 1)
		player.x = WIDTH - 1;
	if (player.y < 1)
		player.y = 1;
	if (player.y > HEIGHT)
		player.y = HEIGHT;
}

void PrintGame()
{
	system("cls");
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar)
		{
			gotoxy(star[i].x, star[i].y);
			cout << "★";
		}
	}

	gotoxy(player.x, player.y);
	cout << "▲";

	for (int i = 0; i < WIDTH + 1; i++)
	{
		gotoxy(i, 0);
		cout << "■";
		
		for (int j = 0; j < HEIGHT + 1; j++)
		{
			gotoxy(i, j);
			if(i == 0 || i == WIDTH)
				cout << "■";
		}

		gotoxy(i, HEIGHT + 1);
		cout << "■";
	}
}

int main()
{
	initialize();
	srand((unsigned int)time(NULL));

	Sleep(10);

	while (!(collidPlayer()))
	{
		createStar();
		moveStar();
		destroyStar();

		movePlayer();
		PrintGame();

		Sleep(30);
	}

	return 0;
}
