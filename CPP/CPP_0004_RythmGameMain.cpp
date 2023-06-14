#include "stdafx.h"

#define COLUMN 6
#define ROW 29
#define CHECKLINE 3
#define DROPTIME 0.1f
#define SPAWNTIME 0.4f

struct note
{
	int x;
	int y;
};

std::vector<note> gameNote;

Timer timer;
float noteDropCount;
float noteSpawnCount;
int score = 100;

void Start();
bool Update();
void CheckNote(int);
void Render();

int main()
{
    Start();

    while(Update())
    {
        Render();
    }

	return 0;
}

void Start()
{
	system("title RhythmGame");
    
    {
        HANDLE hConsole;
        CONSOLE_CURSOR_INFO ConsoleCursor;

        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        ConsoleCursor.bVisible = 0;
        ConsoleCursor.dwSize = 1;

        SetConsoleCursorInfo(hConsole, &ConsoleCursor);
    }

    std::cout << "**********리듬 게임**********" << std::endl;

    system("pause");
    system("cls");
}

bool Update()
{
    timer.Update();

    noteDropCount += timer.GetDeltaTimeSEC();
    noteSpawnCount += timer.GetDeltaTimeSEC();
    // 만들어진 첫 시간에 대한 초기화

    if (GetAsyncKeyState('D')) // 키 눌림 체크
    {
        CheckNote(1);
    }
    if (GetAsyncKeyState('F'))
    {
        CheckNote(2);
    }
    if (GetAsyncKeyState('J'))
    {
        CheckNote(3);
    }
    if (GetAsyncKeyState('K'))
    {
        CheckNote(4);
    }

    if (noteSpawnCount >= SPAWNTIME)
    {
        note temp;

        temp.x = Math::Random(1, COLUMN - 2);
        temp.y = 0;

        gameNote.push_back(temp);

        noteSpawnCount = 0.0f;
    }

    if (noteDropCount >= DROPTIME)
    {
        for (auto& note : gameNote)
        {
            note.y++;
        }

        for (auto iter = gameNote.begin(); iter != gameNote.end();)
        {
            if (iter->y >= ROW - 1)
            {
                iter = gameNote.erase(iter);
                score -= 10;

                if (score == 0)
                    exit(1);
            }
            else
                iter++;
        }

        noteDropCount = 0.0f;
    }

    return true;
}

void CheckNote(int x)
{
    for (auto iter = gameNote.begin(); iter != gameNote.end();)
    {
        if (iter->x == x && iter->y >= ROW - CHECKLINE - 1)
        {
            iter = gameNote.erase(iter);
            score += 10;
        }
        else
            iter++;
    }
}

void gotoxy(int x, int y)
{
    COORD pos = { x * 2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Render()
{
    system("cls");

    for (int i = 0; i < ROW; i++)
    {
        gotoxy(0, i);
        std::cout << "※";
        gotoxy(COLUMN - 1, i);
        std::cout << "※";
    }

    for (int i = 0; i < COLUMN; i++)
    {
        gotoxy(i, ROW - 1);
        std::cout << "※";
    }

    for (int i = 0; i < CHECKLINE; i++)
    {
        gotoxy(0, ROW - i - 2);
        std::cout << "▶";
        gotoxy(COLUMN - 1, ROW - i - 2);
        std::cout << "◀";
    }

    {
        gotoxy(1, ROW);
        std::cout << " D F J K";
    }

    {
        for (const auto& note : gameNote)
        {
            gotoxy(note.x, note.y);
            std::cout << "♪";
        }
    }

    {
        gotoxy(10, 5);
        std::cout << "score : " << score;
    }
}
