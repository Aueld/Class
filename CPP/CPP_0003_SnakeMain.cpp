#include "stdafx.h"

void SetUp();
bool Update();
void Render();
void Food();

enum Direction
{
	Up = 72,
	Left = 75,
	Right = 77,
	Down = 80
};

struct Pos
{
	int x;
	int y;
};

const int boardRowMax = 20;
const int boardColMax = 20;

float delaySec = 0.04f;

std::list<Pos> snake;
Direction snakeDir;

Pos foodPos;
Stopwatch currentTime;

int main()
{
    system("pause");
    SetUp();
    while (Update())
    {
        Render();
    }

	return 0;
}

void SetUp()
{
    {
        HANDLE hConsole;
        CONSOLE_CURSOR_INFO ConsoleCursor;

        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        ConsoleCursor.bVisible = 0;
        ConsoleCursor.dwSize = 1;

        SetConsoleCursorInfo(hConsole, &ConsoleCursor);
    }

    Pos startPos = { boardColMax / 2, boardRowMax / 2 };
    snake.push_back(Pos{ startPos.x, startPos.y });
    snake.push_back(Pos{ startPos.x - 1, startPos.y - 1 });
    snake.push_back(Pos{ startPos.x - 2, startPos.y - 2 });

    snakeDir = Right;

    Food();
}

bool Update()
{
    currentTime.Start();

    Pos next = snake.front();

    {
        while (currentTime.GetElapsedTimeSec() < delaySec)
        {
            if (_kbhit() == true)
            {
                int key = _getch();

                if (key == 224)
                {
                    key = _getch();

                    switch (key)
                    {
                    case Up:
                        snakeDir = Up;
                        break;
                    case Down:
                        snakeDir = Down;
                        break;
                    case Left:
                        snakeDir = Left;
                        break;
                    case Right:
                        snakeDir = Right;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    switch (snakeDir)
    {
    case Up:
        next.y--;
        break;
    case Down:
        next.y++;
        break;
    case Left:
        next.x--;
        break;
    case Right:
        next.x++;
        break;
    }

    {
        if (next.x <= 0 || next.x > boardColMax - 2) return false;
        if (next.y <= 0 || next.y > boardRowMax - 2) return false;

        for (const auto& body : snake)
        {
            if (next.x == body.x && next.y == body.y)
                return false;
        }

        if (foodPos.x == next.x && foodPos.y == next.y)
        {
            snake.push_back(snake.back());
            Food();
        }
    }

    snake.push_front(next);
    snake.pop_back();

    return true;
}

void gotoxy(int x, int y)
{
    COORD pos = { x * 2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Render()
{
    system("cls");

    for (int row = 0; row < boardRowMax; row++)
    {
        gotoxy(0, row);
        cout << "※";
        gotoxy(boardColMax - 1, row);
        cout << "※";
    }

    for (int col = 0; col < boardColMax; col++)
    {
        gotoxy(col, 0);
        cout << "※";
        gotoxy(col, boardRowMax - 1);
        cout << "※";
    }

    // iterator
    for (auto iter = snake.begin(); iter != snake.end(); iter++)
    {
        gotoxy(iter->x, iter->y);
        if (iter == snake.begin())
            cout << "★";
        else
            cout << "☆";
    }

    {
        static int score = 0;

        score += 100;

        gotoxy(0, boardRowMax);
        cout << "Score : " << score << endl;
    }

    {
        gotoxy(foodPos.x, foodPos.y);
        cout << "＠";
    }
}

void Food()
{
    foodPos.x = Math::Random(1, boardColMax - 2);
    foodPos.y = Math::Random(1, boardRowMax - 2);

    for (auto iter = snake.begin(); iter != snake.end(); iter++)
    {
        if (foodPos.x == iter->x && foodPos.y == iter->y)
        {
            iter = snake.begin();

            foodPos.x = Math::Random(1, boardColMax - 2);
            foodPos.y = Math::Random(1, boardRowMax - 2);
        }
    }
}
